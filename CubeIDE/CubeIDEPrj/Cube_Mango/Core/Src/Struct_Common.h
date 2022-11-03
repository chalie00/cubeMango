#include "stm32f1xx_hal.h"
#include "Define.h"
#include "StructContainor.h"



extern uint8_t ErrorCnt;


//System Struct
//------------------------------------
extern stSystemState SystemState, ExtDevice;
//---------------------------------------

//Usart Struct Define
//----------------------------------------------
//UART_HandleTypeDef huart1 , huart2 , huart3 , huart4 ;
extern stUSART_TX USART1_TX, USART2_TX, USART3_TX, DEBUG_TX ;
extern stUSART_RX USART1_RX, USART2_RX, USART3_RX, DEBUG_RX ;
//----------------------------------------------


// KEY Strut Define
//--------------------------------------------
extern stKEY KEYt;
//--------------------------------------------


//EEPROM
//---------------------------------------------
extern usEEPROM rts_EEP;
//--------------------------------------------



//RTC Struct
//-----------------------------------
extern RTC_TimeTypeDef sTime;
extern RTC_DateTypeDef sDate;
extern RTC_DateTypeDef DateToUpdate ;
//-----------------------------------

//GPIO Struct
//--------------------------------------------
extern GPIO_InitTypeDef GPIO_InitStruct ;
//--------------------------------------------

//USART Struct
//-------------------------------------------
extern UART_HandleTypeDef huart1;
extern UART_HandleTypeDef huart3;
extern DMA_HandleTypeDef hdma_usart1_rx;
extern DMA_HandleTypeDef hdma_usart3_rx;

