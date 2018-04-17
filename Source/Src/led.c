#include "app.h"
#include "filter.h"
#include "led.h"


extern SPI_HandleTypeDef hspi1;

static tGpioOutput Enable,Latch;
static tLed Output;



void LedInit(void)
	{
	GpioOutputInit(&Enable,GPIOD,GPIO_PIN_1 ,GpioActiveLow);
	GpioOutputInit(&Latch ,GPIOD,GPIO_PIN_3 ,GpioActiveHigh);
	Output.u16=0;
	};

//void LedWrite(tLed* write)
void LedWrite(U16* write)
	{
	assert_param(write!=NULL);

//	if(HAL_SPI_Transmit(&hspi1,(U8*)&write->Chip.u16,1,100)==HAL_OK)
	if(HAL_SPI_Transmit(&hspi1,(U8*)&write,2,100)==HAL_OK)
		{
		GpioOutputSet(&Enable,false);
		GpioOutputSet(&Latch,true);
		GpioOutputSet(&Latch,false);
		GpioOutputSet(&Enable,true);
		}
	};
void LedWriteDirect(U16 write)
	{
	assert_param(write!=NULL);
	U8 buf[2];
	buf[1]=(U8)write&(0xFF);
	buf[0]=(U8)((write>>8)&(0xFF));
	if(HAL_SPI_Transmit(&hspi1,buf,2,100)==HAL_OK)
		{
		GpioOutputSet(&Enable,false);
		GpioOutputSet(&Latch,true);
		GpioOutputSet(&Latch,false);
		GpioOutputSet(&Enable,true);
		}
	};

void LedUp(LedIdx Led){
	Output.u16 |= (U16)(1<<Led);
	LedWriteDirect(Output.u16);
}
void LedDown(LedIdx Led){
	Output.u16 &= ~((U16)(1<<Led));
	LedWriteDirect(Output.u16);
}
void LedSet(LedIdx Led, U8 state){
	if (state)
		LedUp(Led);
	else
		LedDown(Led);
}



/*
static tLed Display[2];
static U8  Segment;
static U32 RxError;
static U32 Timestamp;

void DisplayRefresh(U32 timestamp)
	{
	LedWrite(Segment%ARRAY_SIZE(Display),&Display[Segment%ARRAY_SIZE(Display)]);
	Segment++;

	//RTCTIME rtc;
	//rtc_gettime(&rtc);
	//U8 value=rtc.sec;
//	Display[0].Seg.u8=GetLed7SegCode(value/10);
//	Display[1].Seg.u8=GetLed7SegCode(value%10);
	U8 value=GetRegs()->Phase;
	Display[0].Seg.u8=GetLed7SegCode(value>>4);
	Display[1].Seg.u8=GetLed7SegCode(value&0xF);

	Display[0].Led.Group0.Led1=GetRegs()->ContactStart;
	Display[0].Led.Group0.Led2=GetRegs()->ContactDrv1;
	Display[0].Led.Group0.Led3=GetRegs()->ContactDrv2;
	if(timestamp-Timestamp>=500)
		{
		Timestamp=timestamp;
		U32 rxerr=AppRS485RxError();
		Display[0].Led.Group0.Led4=!!(RxError!=rxerr);
		RxError=rxerr;
		}
	Display[0].Led.Group0.Led5=!AppBackupValid();
	Display[0].Led.Group0.Led6=GetRegs()->ContactInput;
	Display[0].Led.Group0.Led7=GetRegs()->Alarm;
	Display[0].Led.Group0.Led8=GetRegs()->Fan;

	Display[1].Led.Group0.Led1=GetRegs()->IgnitionTrafo;
	Display[1].Led.Group0.Led2=GetRegs()->AuxBlower;
	Display[1].Led.Group0.Led3=GetRegs()->SolenoidValve1;
	Display[1].Led.Group0.Led4=GetRegs()->SolenoidValve2;
	Display[1].Led.Group0.Led5=GetRegs()->BurnerFail;
	Display[1].Led.Group0.Led6=GetRegs()->ClearFail;
	Display[1].Led.Group0.Led7=GetRegs()->DKGPowerSupply;
	Display[1].Led.Group0.Led8=GetRegs()->PowerSupply;
	};*/
