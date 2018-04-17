#ifndef RELAYS_H_
#define RELAYS_H_
#include "app.h"
#include "filter.h"
#include "database.h"

void RelaysInit(void);

void RelaysOpen(void);

void RelayPK1Toggle();
void RelayPK2Toggle();


void RelayPK1Set(U8 state);
void RelayPK2Set(U8 state);


#endif /* RELAYS_H_ */
