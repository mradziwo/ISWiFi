/*
 * database.c

 *
 *  Created on: 1 Jul 2017
 *      Author: CCM
 */

#include "database.h"


void rewriteVariables()
{
	U16 i;
	for(i = 0; i < globalVariablesSize; i++)
	{
	  if (globalVariables[i].overwrite)
	  {
		  globalVariables[i].value=globalVariables[i].candidate;
	  }
	  else
	  {
		  globalVariables[i].value=globalVariables[i].ovrewriteValue;
	  }
	  globalVariables[i].valid=((globalVariables[i].value>=globalVariables[i].min)&&(globalVariables[i].value<=globalVariables[i].max));
	}

}

void writeVar(S16 index, S16 value)
{

	globalVariables[index].candidate=value;
	if (globalVariables[index].overwrite)
		globalVariables[index].value=globalVariables[index].ovrewriteValue;
	else
		globalVariables[index].value=globalVariables[index].candidate;
	globalVariables[index].valid=((globalVariables[index].value>=globalVariables[index].min)&&(globalVariables[index].value<=globalVariables[index].max));
}

S16 readVar(S16 index)
{
	return globalVariables[index].value;
}

void overwriteVar(S16 index, S16 enable)
{
	if (enable)
	{
		globalVariables[index].overwrite=1;
		globalVariables[index].value=globalVariables[index].ovrewriteValue;
	}
	else
	{
		globalVariables[index].overwrite=0;
		globalVariables[index].value=globalVariables[index].candidate;
	}
}

void  setOvervtiteVarValue(S16 index, S16 value)
{
	globalVariables[index].ovrewriteValue=value;
}


U8 setParam(S16 index, S16 value)
{
	if ((value>=parameters[index].min)&&(value<=parameters[index].max))
	{
		parameters[index].value=value;
		return 0;
	}
	else
		return 1;
}

S16 getParam(S16 index)
{
	return parameters[index].value;
}

void initVariables()
{
	globalVariablesSize=sizeof(globalVariables) / sizeof(globalVariables[0]);
}

void initConfig()
{
	parametersSize=sizeof(parameters) / sizeof(parameters[0]);
}

void DatabaseTask(void const* pvParameters)
{
	initConfig();
	initVariables();
	while(1)
		{
		rewriteVariables();
		osDelay(100);
		}
}
