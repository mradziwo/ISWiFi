/*
 * common.h
 *
 *  Created on: 1 Jul 2017
 *      Author: CCM
 */

#ifndef COMMON_H_
#define COMMON_H_
#include "stm32f1xx.h"
#include "stm32f1xx_hal_tim.h"
#include "cmsis_os.h"
#define ARRAY_SIZE(array)           (sizeof(array)/sizeof(array[0]))
#define ASSERT(expression,comment)  typedef int comment[1-2*!(expression)]
#define ASSERT_SIZE(type,size)      ASSERT(sizeof(type)==size,ErrorSize_of_##type)

typedef uint64_t U64;
typedef  int64_t S64;

typedef uint32_t U32;
typedef  int32_t S32;

typedef uint16_t U16;
typedef  int16_t S16;

typedef  uint8_t  U8;
typedef   int8_t  S8;

#define false 0
#define true  1

#endif /* COMMON_H_ */
