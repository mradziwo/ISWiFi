#ifndef _FILTER_H_
#define _FILTER_H_

#include "app.h"
#include "common.h"

typedef enum
	{
	GpioActiveLow=0,
	GpioActiveHigh,
	}tGpioActiveType;

typedef enum
	{
	GpioFilterBistable=0,
	GpioFilterMonostableEventRaise,
	GpioFilterMonostableEventFall
	}tGpioFilterType;

typedef struct
	{
	GPIO_TypeDef* Port;
	U16 Pin;
	tGpioFilterType Type;
	tGpioActiveType Active;
	U32 Timer;
	U32 Period;
	U8  Output;
	U8  Flag;
	U8  InitDone;
	}tGpioFilter;

void GpioFilterInit     (tGpioFilter* self, GPIO_TypeDef* port, U16 pin, tGpioFilterType type, tGpioActiveType active, U32 period);
U8   GpioFilterProcess  (tGpioFilter* self, U32 step);
void GpioFilterSetOutput(tGpioFilter* self, U8 output);
U8   GpioFilterIsActive (tGpioFilter* self);


typedef struct
	{
	tGpioActiveType Type;
	GPIO_TypeDef* Port;
	U16 Pin;
	U8  InitDone;
	}tGpioOutput;

void GpioOutputInit        (tGpioOutput* self, GPIO_TypeDef* port, U16 pin, tGpioActiveType type);
void GpioOutputSet         (tGpioOutput* self, U8 active);
void GpioOutputToggle      (tGpioOutput* self);
U8   GpioOutputIsActive    (tGpioOutput* self);


typedef struct
	{
	U32 Timer;
	U32 Interval;
	U8  Output;
	}tImpulse;

void ImpulseInit    (tImpulse* self, U32 interval);
U8   ImpulseProcess (tImpulse* self, U32 timestamp, U8 signal);
U8   ImpulseIsActive(tImpulse* self);


typedef struct
	{
	S16* Buf;
	U8   Size;
	U8   Index;
	U8   Valid;
	}tLowPassFIR;

U8  LowPassFIRInit   (tLowPassFIR* self, S16* buf, U8 size);
U8  LowPassFIRProcess(tLowPassFIR* self, S16 sample);
S16 LowPassFIRValue  (tLowPassFIR* self);


typedef enum  {ascending, descending} direction;
typedef enum  {forward, inverse} polarity;

typedef struct
	{
	S16  HighThreshold;
	S16  LowThreshold;
	polarity Polarity;
	direction  State;
	}tHystController;



U8  HystContrInit   (tHystController* self, S16 Threshold, polarity Polarity, U16 Hysteresis);
U8  HystContrProcess (tHystController* self,S16 sample);


#endif /* _FILTER_H_ */
