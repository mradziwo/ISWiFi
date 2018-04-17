/*
 * HysteresisController.c
 *
 *  Created on: 28 Jun 2017
 *      Author: CCM
 */
#include "HysteresisController.h"
#include "database.h"
#include "led.h"
#include "filter.h"
#include "relays.h"
#include "vcp.h"


static tHystController Controller1, Controller2;


void TempControllerTask(void const* pvParameters)
{
	char buf[32];
	  osDelay(5000);
	  sprintf(buf, "Controler Task Started:\r\n");
	  Send(buf, strlen(buf), 500);

	HystContrInit(&Controller1, getParam(PAR_C1SETPOINT),inverse, getParam(PAR_C1HIST));
	HystContrInit(&Controller2, getParam(PAR_C2SETPOINT),inverse, getParam(PAR_C2HIST));
	while(1)
	{
		U8 out1,out2;
		out1=HystContrProcess(&Controller1,readVar(VAR_TEMP1));
		//RelayPK1Set((readVar(VAR_TEMP1)<=readVar(VAR_TEMP3))?out1:0);
		RelayPK1Set(out1);
		LedSet(PK1,out1);
		out2=HystContrProcess(&Controller2,readVar(VAR_TEMP2));
		//RelayPK2Set((readVar(VAR_TEMP2)<=readVar(VAR_TEMP3))?out2:0);
		RelayPK2Set(out2);
		LedSet(PK2,out2);
		sprintf(buf, "PK out:\r\nPk1:\t%d\tPK2:\t%d\r\n", out1, out2);
		Send(buf, strlen(buf), 500);
		osDelay(1000);

	}
}
