#include "cmsis_os.h"
#include "usbd_cdc_if.h"
#include "app.h"
#include "relays.h"
#include "led.h"

static osMailQId Rx;

typedef struct
	{
	U8 Data[CDC_DATA_FS_MAX_PACKET_SIZE];
	U8 Size;
	}tVcpBuf;


void VcpRxEvent(U8* data, U32 size)
	{
	tVcpBuf* buf=(tVcpBuf*)osMailAlloc(Rx,0);
	if(buf)
		{
		buf->Size=MIN(size,sizeof(buf->Data));
		memcpy(buf->Data,data,buf->Size);
		osMailPut(Rx,buf);
		}
	};

//static
U8 Send(char* data, U8 size, U32 timeout)
	{
	U32 timestamp=osKernelSysTick();
	U8 ret=0;
	while((ret=CDC_Transmit_FS(data,size))==USBD_BUSY && osKernelSysTick()-timestamp<timeout)
		osDelay(MIN(timeout,5));
	return ret;
	};

void VcpTask(void const* pvParameters)
	{
	U16 led;
	/*HAL_GPIO_TogglePin(GPIOE, PK1_HEATER_Pin);

	HAL_GPIO_TogglePin(GPIOE, PK1_HEATER_Pin);*/
	osMailQDef(RxBuf,16,tVcpBuf);
	while((Rx=osMailCreate(osMailQ(RxBuf),NULL))==NULL);
	while(1)
		{
		osEvent event;
		event=osMailGet(Rx,osWaitForever);
		if(event.status==osEventMail)
			{
			osMailQDef(RxBuf,16,tVcpBuf);
			tVcpBuf* buf=(tVcpBuf*)event.value.p;

			U8* data=buf->Data;
			U32 size=buf->Size;
			while(size--)
				{
				switch (data[0])
					{
					case '1':
						RelayPK1Set(true);
						break;

					case '2':
						RelayPK1Set(false);
						break;

					case '3':
						RelayPK2Set(true);
						break;

					case '4':
						RelayPK2Set(false);
						break;

					default:
						break;
					}


				}

			osMailFree(Rx,event.value.p);
			}
		}
	osThreadTerminate(NULL);
	};
