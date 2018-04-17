/**
  ******************************************************************************
  * File Name          : main.h
  * Description        : This file contains the common defines of the application
  ******************************************************************************
  *
  * Copyright (c) 2017 STMicroelectronics International N.V. 
  * All rights reserved.
  *
  * Redistribution and use in source and binary forms, with or without 
  * modification, are permitted, provided that the following conditions are met:
  *
  * 1. Redistribution of source code must retain the above copyright notice, 
  *    this list of conditions and the following disclaimer.
  * 2. Redistributions in binary form must reproduce the above copyright notice,
  *    this list of conditions and the following disclaimer in the documentation
  *    and/or other materials provided with the distribution.
  * 3. Neither the name of STMicroelectronics nor the names of other 
  *    contributors to this software may be used to endorse or promote products 
  *    derived from this software without specific written permission.
  * 4. This software, including modifications and/or derivative works of this 
  *    software, must execute solely and exclusively on microcontroller or
  *    microprocessor devices manufactured by or for STMicroelectronics.
  * 5. Redistribution and use of this software other than as permitted under 
  *    this license is void and will automatically terminate your rights under 
  *    this license. 
  *
  * THIS SOFTWARE IS PROVIDED BY STMICROELECTRONICS AND CONTRIBUTORS "AS IS" 
  * AND ANY EXPRESS, IMPLIED OR STATUTORY WARRANTIES, INCLUDING, BUT NOT 
  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A 
  * PARTICULAR PURPOSE AND NON-INFRINGEMENT OF THIRD PARTY INTELLECTUAL PROPERTY
  * RIGHTS ARE DISCLAIMED TO THE FULLEST EXTENT PERMITTED BY LAW. IN NO EVENT 
  * SHALL STMICROELECTRONICS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, 
  * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF 
  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING 
  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
  * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H
  /* Includes ------------------------------------------------------------------*/

/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private define ------------------------------------------------------------*/

#define USART2_RS485_DIR_Pin GPIO_PIN_1
#define USART2_RS485_DIR_GPIO_Port GPIOA
#define USART2_RS485_TXD_Pin GPIO_PIN_2
#define USART2_RS485_TXD_GPIO_Port GPIOA
#define USART2_RS485_RXD_Pin GPIO_PIN_3
#define USART2_RS485_RXD_GPIO_Port GPIOA
#define SPI1_SCK___LED_CLK_Pin GPIO_PIN_5
#define SPI1_SCK___LED_CLK_GPIO_Port GPIOA
#define SPI1_MOSI___LED_SDI_Pin GPIO_PIN_7
#define SPI1_MOSI___LED_SDI_GPIO_Port GPIOA
#define ADC_TEMP1_Pin GPIO_PIN_4
#define ADC_TEMP1_GPIO_Port GPIOC
#define ADC_TEMP2_Pin GPIO_PIN_5
#define ADC_TEMP2_GPIO_Port GPIOC
#define ADC_TEMP3_Pin GPIO_PIN_0
#define ADC_TEMP3_GPIO_Port GPIOB
#define PK1_HEATER_Pin GPIO_PIN_10
#define PK1_HEATER_GPIO_Port GPIOE
#define PK2_HEATER_Pin GPIO_PIN_11
#define PK2_HEATER_GPIO_Port GPIOE
#define POWER_OFF_Pin GPIO_PIN_12
#define POWER_OFF_GPIO_Port GPIOE
#define POWER_FAIL_Pin GPIO_PIN_13
#define POWER_FAIL_GPIO_Port GPIOE
#define S1_Pin GPIO_PIN_14
#define S1_GPIO_Port GPIOE
#define S2_Pin GPIO_PIN_15
#define S2_GPIO_Port GPIOE
#define USART3_WIFI_TXD_Pin GPIO_PIN_10
#define USART3_WIFI_TXD_GPIO_Port GPIOB
#define USART3_WIFI_RXD_Pin GPIO_PIN_11
#define USART3_WIFI_RXD_GPIO_Port GPIOB
#define WIFI_RESET_Pin GPIO_PIN_14
#define WIFI_RESET_GPIO_Port GPIOD
#define WIFI_MODE_Pin GPIO_PIN_15
#define WIFI_MODE_GPIO_Port GPIOD
#define SDMICRO_CARDDETECT_Pin GPIO_PIN_9
#define SDMICRO_CARDDETECT_GPIO_Port GPIOC
#define RS485_2_DIR_Pin GPIO_PIN_0
#define RS485_2_DIR_GPIO_Port GPIOD
#define LED_LE_Pin GPIO_PIN_1
#define LED_LE_GPIO_Port GPIOD
#define LED_OE_Pin GPIO_PIN_3
#define LED_OE_GPIO_Port GPIOD
#define XPORT_RESET_Pin GPIO_PIN_7
#define XPORT_RESET_GPIO_Port GPIOD
#define USART1_TX___XPORT_IN_Pin GPIO_PIN_6
#define USART1_TX___XPORT_IN_GPIO_Port GPIOB
#define USART1_RX___XPORT_OUT_Pin GPIO_PIN_7
#define USART1_RX___XPORT_OUT_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */
/* USER CODE END Private defines */

/**
  * @}
  */ 

/**
  * @}
*/ 

#endif /* __MAIN_H */
/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
