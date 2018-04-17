
#include "relays.h"

static tGpioOutput PK1, PK2;

void RelaysInit(void)
	{
	GpioOutputInit(&PK1,GPIOE,GPIO_PIN_10 ,GpioActiveLow);
	GpioOutputInit(&PK2 ,GPIOE,GPIO_PIN_11 ,GpioActiveHigh);
	};


void static RelaySet(tGpioOutput* relay, U8 state)
{

	GpioOutputSet(relay,state);
}

void static RelayToggle(tGpioOutput* relay)
{
	GpioOutputToggle(relay);
}

void RelayPK1Toggle()
{
	RelayToggle(&PK1);
}
void RelayPK2Toggle()
{
	RelayToggle(&PK2);
}


void RelayPK1Set(U8 state)
{
	writeVar(VAR_PK1, state);
	RelaySet(&PK1, (U8)readVar(VAR_PK1));
}
void RelayPK2Set(U8 state)
{
	writeVar(VAR_PK2, state);
	RelaySet(&PK2, (U8)readVar(VAR_PK2));
}
