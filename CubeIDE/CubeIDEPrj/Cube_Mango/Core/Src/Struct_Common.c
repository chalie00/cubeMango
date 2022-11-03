#include "stm32f1xx.h"
#include "Struct_Common.h"



//RTC Value 
//--------------------------------------------------------
//----------------------------------------------------------------------


//Timer Value
uint32_t aCCValue_Buffer[3] = { 0, 0, 0 }, uwTimerPeriod = 0;


uint8_t ErrorCnt;



// Co2 Value
//--------------------------------------------------
float readCo2 = 0 ;
uint16_t Co2Density = 0 ;
uint8_t readCo2_ErrorCNT = 0, Co2_read_Flag = 0;
//--------------------------------------------------





//System Struct
//------------------------------------
stSystemState SystemState, ExtDevice;
//---------------------------------------


//Usart Struct Define
//----------------------------------------------
//UART_HandleTypeDef huart1 , huart2 , huart3 , huart4 ;
stUSART_TX USART1_TX, USART2_TX, USART3_TX , DEBUG_TX ;
stUSART_RX USART1_RX, USART2_RX, USART3_RX , DEBUG_RX ;
//----------------------------------------------



// KEY Strut Define
//--------------------------------------------
stKEY KEYt;
//--------------------------------------------


//EEPROM
//---------------------------------------------
usEEPROM rts_EEP;
//--------------------------------------------






//RTC Struct
//-----------------------------------

RTC_TimeTypeDef sTime;
RTC_DateTypeDef sDate;
RTC_DateTypeDef DateToUpdate ;
//-----------------------------------

//-------------------------------------------



