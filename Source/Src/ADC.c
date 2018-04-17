/*
 * ADC.c
 *
 *  Created on: 13 Jun 2017
 *      Author: CCM
 */
/* USER CODE BEGIN PV */
#include "app.h"
#include "common.h"
#include "database.h"
#include "filter.h"

uint32_t adcResult = 0;
static ADC_HandleTypeDef hadc1;

/* USER CODE END PV */
static S16 GetAnalogTemperature(uint32_t Channel)
	{
	ADC_ChannelConfTypeDef sConfig;
	sConfig.Rank = 1;
	sConfig.SamplingTime = ADC_SAMPLETIME_28CYCLES_5;
	sConfig.Channel = Channel;//ADC_CHANNEL_15;
	HAL_ADC_ConfigChannel(&hadc1, &sConfig);
	HAL_ADC_Start(&hadc1);
	HAL_ADC_PollForConversion(&hadc1,1);
	return HAL_ADC_GetValue(&hadc1);
	};


static S16 GetADC_Temp1(void)
		{
		return GetAnalogTemperature(ADC_CHANNEL_14);
		}

static S16 GetADC_Temp2(void)
		{
		return GetAnalogTemperature(ADC_CHANNEL_15);
		}
static S16 GetADC_Temp3(void)
		{
		return GetAnalogTemperature(ADC_CHANNEL_8);
		}


void ADCTask(void const* pvParameters)
{
	hadc1=*(ADC_HandleTypeDef*)pvParameters;
	S16 t1, t2, t3;


	tLowPassFIR AnalogTemp1;
	S16 AnalogTempBuf1[20];
	LowPassFIRInit(&AnalogTemp1,AnalogTempBuf1,ARRAY_SIZE(AnalogTempBuf1));
	tLowPassFIR AnalogTemp2;
	S16 AnalogTempBuf2[20];
	LowPassFIRInit(&AnalogTemp2,AnalogTempBuf2,ARRAY_SIZE(AnalogTempBuf2));
	tLowPassFIR AnalogTemp3;
	S16 AnalogTempBuf3[20];
	LowPassFIRInit(&AnalogTemp3,AnalogTempBuf3,ARRAY_SIZE(AnalogTempBuf3));

	while(1)
	{
		t1=GetADC_Temp1();
		LowPassFIRProcess(&AnalogTemp1,t1);
		t1=LowPassFIRValue(&AnalogTemp1);
		t1=(((S32)t1*19)>>4)-2458;
		writeVar(VAR_TEMP1, t1);

		t2=GetADC_Temp2();
		LowPassFIRProcess(&AnalogTemp2,t2);
		t2=LowPassFIRValue(&AnalogTemp2);
		t2=(((S32)t2*19)>>4)-2458;
		writeVar(VAR_TEMP2, t2);

		t3=GetADC_Temp3();
		LowPassFIRProcess(&AnalogTemp3,t3);
		t3=LowPassFIRValue(&AnalogTemp3);
		t3=(((S32)t3*19)>>4)-2458;
		writeVar(VAR_TEMP3, t3);

		osDelay(500);
	}

}
