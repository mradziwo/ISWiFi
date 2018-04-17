#include "filter.h"


void GpioFilterInit(tGpioFilter* self, GPIO_TypeDef* port, U16 pin, tGpioFilterType type, tGpioActiveType active, U32 period)
	{
	assert_param(self!=NULL);
	assert_param(IS_GPIO_ALL_INSTANCE(port));
	assert_param(IS_GPIO_PIN(pin));
	assert_param(period>0);
	self->Port=port;
	self->Pin=pin;
	self->Type=type;
	self->Active=active;
	self->Period=period;
	self->Flag=false;
	self->Timer=0;
	self->Output=!active;
	self->InitDone=true;
	};

U8 GpioFilterProcess(tGpioFilter* self, U32 step)
	{
	assert_param(self!=NULL);
	if(self->InitDone==false) return false;

	GPIO_PinState state=HAL_GPIO_ReadPin(self->Port,self->Pin);
	if(state==GPIO_PIN_SET)
		{
		U32 v=self->Timer+step;
		if(v<self->Timer || v>self->Period) v=self->Period;
		self->Timer=v;
		}
	else
		{
		U32 v=self->Timer-step;
		if(v>self->Period) v=0;
		self->Timer=v;
		}

	if(self->Type==GpioFilterBistable)
		{
		if(self->Timer>=self->Period) self->Output=true;
		if(self->Timer<=0)            self->Output=false;
		}
	else if(self->Type==GpioFilterMonostableEventRaise)
		{
		if(self->Timer>=self->Period && self->Flag==false)
			{
			self->Flag=true;
			self->Output=!self->Output;
			}
		if(self->Timer<=0)
			self->Flag=false;
		}
	else if(self->Type==GpioFilterMonostableEventFall)
		{
		if(self->Timer<=0 && self->Flag==true)
			{
			self->Flag=false;
			self->Output=!self->Output;
			}
		if(self->Timer>=self->Period)
			self->Flag=true;
		};

	return GpioFilterIsActive(self);
	};

void GpioFilterSetOutput(tGpioFilter* self, U8 output)
	{
	assert_param(self!=NULL);
	self->Output=!!output;
	};

U8 GpioFilterIsActive(tGpioFilter* self)
	{
	assert_param(self!=NULL);
	if(self->InitDone==false) return false;
	return (self->Active==GpioActiveHigh)==(self->Output==true);
	};


void GpioOutputInit(tGpioOutput* self, GPIO_TypeDef* port, U16 pin, tGpioActiveType type)
	{
	assert_param(self!=NULL);
	assert_param(IS_GPIO_ALL_INSTANCE(port));
	assert_param(IS_GPIO_PIN(pin));
	self->Port=port;
	self->Pin=pin;
	self->Type=type;
	self->InitDone=true;
	GpioOutputSet(self,false);
	};

void GpioOutputSet(tGpioOutput* self, U8 active)
	{
	assert_param(self!=NULL);
	if(self->InitDone==false) return;
	HAL_GPIO_WritePin(self->Port,self->Pin,((self->Type==GpioActiveHigh)==(active==true))?GPIO_PIN_SET:GPIO_PIN_RESET);
	};

void GpioOutputToggle(tGpioOutput* self)
	{
	assert_param(self!=NULL);
	if(self->InitDone==false) return;
	HAL_GPIO_TogglePin(self->Port,self->Pin);
	};

U8 GpioOutputIsActive(tGpioOutput* self)
	{
	assert_param(self!=NULL);
	if(self->InitDone==false) return false;
	return (self->Type==GpioActiveHigh)==(HAL_GPIO_ReadPin(self->Port,self->Pin)==GPIO_PIN_SET);
	};


void ImpulseInit(tImpulse* self, U32 interval)
	{
	assert_param(self!=NULL);
	self->Timer=0;
	self->Interval=interval;
	self->Output=false;
	};

U8 ImpulseProcess(tImpulse* self, U32 timestamp, U8 signal)
	{
	assert_param(self!=NULL);
	if(signal)
		{
		self->Output=signal;
		self->Timer=timestamp;
		}
	else if(timestamp-self->Timer>=self->Interval)
		{
		self->Timer=timestamp-self->Interval;
		self->Output=signal;
		}
	return self->Output;
	};

U8 ImpulseIsActive(tImpulse* self)
	{
	assert_param(self!=NULL);
	return self->Output;
	};


U8 LowPassFIRInit(tLowPassFIR* self, S16* buf, U8 size)
	{
	if(self==NULL || buf==NULL || size<=0) return 1;
	self->Buf=buf;
	self->Size=size;
	self->Index=0;
	self->Valid=false;
	self->Buf[0]=0;
	return 0;
	};

U8 LowPassFIRProcess(tLowPassFIR* self, S16 sample)
	{
	if(self==NULL) return 1;
	if(self->Index>=self->Size) return 2;

	self->Buf[self->Index]=sample;
	if(++self->Index>=self->Size)
		{
		self->Index=0;
		self->Valid=true;
		}
	if(self->Valid)
		{
		U8 index=self->Index+self->Size/2;
		if(index>=self->Size) index-=self->Size;
		S32 mean=0;
		U8 i;
		for(i=0;i<self->Size;i++) mean+=self->Buf[i];
		self->Buf[index]=(mean+(i>>1))/i;
		}
	return 0;
	};

S16 LowPassFIRValue(tLowPassFIR* self)
	{
	if(self==NULL) return 0;
	U8 index=0;
	if(self->Valid)
		{
		index=self->Index+self->Size/2;
		if(index>=self->Size) index-=self->Size;
		}
	else if(self->Index>0)
		index=self->Index-1;
	return self->Buf[index];
	};

U8  HystContrInit   (tHystController* self, S16 Threshold, polarity Polarity, U16 Hysteresis)
{
	if(self==NULL) return 1;
	self->HighThreshold=Threshold+Hysteresis;
	self->LowThreshold=Threshold-Hysteresis;
	self->State= ascending;
	self->Polarity=Polarity;
	return 0;
}


U8 HystContrProcess (tHystController* self,S16 sample)
{
	U8 output=0;
	switch (self->State)
	{
	case ascending:
		if (sample>=self->HighThreshold)
		{
			self->State=descending;
			output=!self->Polarity;
		}
		else
			output = self->Polarity;
		break;
	case descending:
		if (sample<=self->LowThreshold)
		{
			self->State=ascending;
			output = self->Polarity;
		}
		output = !self->Polarity;
		break;
	}

	return output;
}
