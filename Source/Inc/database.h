/*
 * database.h
 *
 *  Created on: 1 Jul 2017
 *      Author: CCM
 */

#ifndef DATABASE_H_
#define DATABASE_H_

#include "common.h"

typedef struct
{
	const char* name; 		//name of variable
	S16 value;				//value to be used in system
	S16 candidate;			//candidate to be written to value (if overwrite is not 1)
	U8 overwrite;			//overwrite value with overwrite value instead of candidate value
	S16 ovrewriteValue;
	const S16 min;
	const S16 max;
	U8 valid;

} variableStruct;

typedef struct
{
	const char* name;
	S16 value;
	S16 min;
	S16 max;
} parameterStruct;
#define VAR_TEMP1 0
#define VAR_TEMP2 1
#define VAR_TEMP3 2
#define VAR_PK1 3
#define VAR_PK2 4

static variableStruct globalVariables[]={

		[VAR_TEMP1]={ .name="TempT1",	.candidate=0,	.value=0, 	.overwrite=0, 	.ovrewriteValue=0, 	.min=-300, 	.max=600, .valid=0},
		[VAR_TEMP2]={ .name="TempT2",	.candidate=0,	.value=0, 	.overwrite=0, 	.ovrewriteValue=0, 	.min=-300, 	.max=600, .valid=0},
		[VAR_TEMP3]={ .name="TempT3",	.candidate=0,	.value=0, 	.overwrite=0, 	.ovrewriteValue=0, 	.min=-300, 	.max=600, .valid=0},
		[VAR_PK1]={ .name="Relay1",	.candidate=0,	.value=0, 	.overwrite=0, 	.ovrewriteValue=0, 	.min=-300, 	.max=600, .valid=0},
		[VAR_PK2]={ .name="Relay2",	.candidate=0,	.value=0, 	.overwrite=0, 	.ovrewriteValue=0, 	.min=-300, 	.max=600, .valid=0}

};
static U16 globalVariablesSize;

#define PAR_C1SETPOINT 0
#define PAR_C2SETPOINT 1
#define PAR_C1HIST 2
#define PAR_C2HIST 3
static parameterStruct parameters[]={
		[PAR_C1SETPOINT]={ 	.name="Controller1.Setpoint",		.value=280, 	.min=-30, 	.max=60},
		[PAR_C1HIST]={ 		.name="Controller1.Hysteresis",		.value=20, 		.min=-30, 	.max=60},
		[PAR_C2SETPOINT]={ 	.name="Controller2.Setpoint",		.value=280, 	.min=-30, 	.max=60},
		[PAR_C2HIST]={ 		.name="Controller2.Hysteresis",		.value=20, 		.min=-30, 	.max=60}
};

static U16 parametersSize;

void rewriteVariables();

void writeVar(S16 index, S16 value);
S16 readVar(S16 index);
void overwriteVar(S16 index, S16 enable);
void  setOvervtiteVarValue(S16 index, S16 value);

U8 setParam(S16 index, S16 value);
S16 getParam(S16 index);

void initVariables();

void initConfig();

void DatabaseTask(void const* pvParameters);

#endif /* DATABASE_H_ */
