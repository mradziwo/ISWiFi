#ifndef LED_H_
#define LED_H_


typedef union
	{
	U16 u16;
	struct
		{
		U16 Out0  :1; // LSB
		U16 Out1  :1;
		U16 Out2  :1;
		U16 Out3  :1;
		U16 Out4  :1;
		U16 Out5  :1;
		U16 Out6  :1;
		U16 Out7  :1;
		U16 Out8  :1;
		U16 Out9  :1;
		U16 Out10 :1;
		U16 Out11 :1;
		U16 Out12 :1;
		U16 Out13 :1;
		U16 Out14 :1;
		U16 Out15 :1; // MSB
		};
	}tLed;

ASSERT_SIZE(tLed, 2);

typedef enum  { RS485_1_RX, RS485_1_TX, RS485_2_RX, RS485_2_TX, WIFI_OK, WIFI_NOK, PK2, PK1, OUT1, OUT2, OUT3, OUT4 } LedIdx;



void LedUp(LedIdx Led);
void LedDown(LedIdx Led);
void LedSet(LedIdx Led, U8 state);

void LedInit(void);
void LedWrite(U16* write);

void DisplayRefresh(U32 timestamp);

#endif /* LED_H_ */
