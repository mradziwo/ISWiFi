#ifndef VCP_H_
#define VCP_H_

#include "app.h"


void VcpRxEvent(U8* data, U32 size);

void VcpTask(void const* pvParameters);

U8 Send(char* data, U8 size, U32 timeout);

#endif /* VCP_H_ */
