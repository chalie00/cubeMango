/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    usart.c
  * @brief   This file provides code for the configuration
  *          of the USART instances.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "usart.h"
#include "Define.h"
#include "Struct_Common.h"

/* USER CODE BEGIN 0 */
void UART1_RxProc(void);
void UART2_TxProc(void);
void UART3_TxProc(void) ;

void UART1_RxIntr(uint8_t lub_buff);
void UART2_RxIntr(uint8_t lub_buff);
void UART3_RxIntr(uint8_t lub_buff);

void DEBUG_RxIntr(uint8_t lub_buff) ;
void DEBUG_TxProc();
/* USER CODE END 0 */

UART_HandleTypeDef huart3;

/* USART3 init function */

void MX_USART3_UART_Init(void)
{

  /* USER CODE BEGIN USART3_Init 0 */

  /* USER CODE END USART3_Init 0 */

  /* USER CODE BEGIN USART3_Init 1 */

  /* USER CODE END USART3_Init 1 */
  huart3.Instance = USART3;
  huart3.Init.BaudRate = 115200;
  huart3.Init.WordLength = UART_WORDLENGTH_8B;
  huart3.Init.StopBits = UART_STOPBITS_1;
  huart3.Init.Parity = UART_PARITY_NONE;
  huart3.Init.Mode = UART_MODE_TX_RX;
  huart3.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart3.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart3) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART3_Init 2 */
  HAL_UART_Receive_IT(&huart3, &DEBUG_RX.TempBUF , 1 );
  /* USER CODE END USART3_Init 2 */

}

void HAL_UART_MspInit(UART_HandleTypeDef* uartHandle)
{

  GPIO_InitTypeDef GPIO_InitStruct = {0};
  if(uartHandle->Instance==USART3)
  {
  /* USER CODE BEGIN USART3_MspInit 0 */

  /* USER CODE END USART3_MspInit 0 */
    /* USART3 clock enable */
    __HAL_RCC_USART3_CLK_ENABLE();

    __HAL_RCC_GPIOB_CLK_ENABLE();
    /**USART3 GPIO Configuration
    PB10     ------> USART3_TX
    PB11     ------> USART3_RX
    */
    GPIO_InitStruct.Pin = GPIO_PIN_10;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = GPIO_PIN_11;
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

    /* USART3 interrupt Init */
    HAL_NVIC_SetPriority(USART3_IRQn, 0, 0);
    HAL_NVIC_EnableIRQ(USART3_IRQn);
  /* USER CODE BEGIN USART3_MspInit 1 */

  /* USER CODE END USART3_MspInit 1 */
  }
}

void HAL_UART_MspDeInit(UART_HandleTypeDef* uartHandle)
{

  if(uartHandle->Instance==USART3)
  {
  /* USER CODE BEGIN USART3_MspDeInit 0 */

  /* USER CODE END USART3_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_USART3_CLK_DISABLE();

    /**USART3 GPIO Configuration
    PB10     ------> USART3_TX
    PB11     ------> USART3_RX
    */
    HAL_GPIO_DeInit(GPIOB, GPIO_PIN_10|GPIO_PIN_11);

    /* USART3 interrupt Deinit */
    HAL_NVIC_DisableIRQ(USART3_IRQn);
  /* USER CODE BEGIN USART3_MspDeInit 1 */

  /* USER CODE END USART3_MspDeInit 1 */
  }
}

/* USER CODE BEGIN 1 */


uint32_t ieBaudRate = 0;



void UART3_RxIntr(uint8_t lub_buff)
{
	if(USART3_RX.CNT == 0)
		{
			M_LED5_ON;
			USART3_RX.TIMEOUT = D_USART3_RX_TIMEOUT;
			USART3_RX.BUF[USART3_RX.CNT++] = lub_buff ;
//			DEBUG_TX.BUF[DEBUG_TX.CNT++] = lub_buff ;
		}
		else if(USART3_RX.CNT < D_USART3_RX_BUF_LEN )
				{
					USART3_RX.BUF[USART3_RX.CNT++] = lub_buff ;
//					DEBUG_TX.BUF[DEBUG_TX.CNT++] = lub_buff ;
				}
				else if(USART3_RX.CNT > D_USART3_RX_BUF_LEN )
						{
							USART3_RX.CNT = 0;
							USART3_RX.TIMEOUT = 0;
							//memcpy( &USART3_RX.BUF[D_USART3_TX_BUF_LEN] , 0x00 , D_USART3_TX_BUF_LEN );
						}
}

void DEBUG_RxIntr(uint8_t lub_buff)
{
	if(DEBUG_RX.CNT == 0)
		{
			M_LED1_ON;
			DEBUG_RX.TIMEOUT = DEBUG_TX.TIMEOUT= D_USART3_RX_TIMEOUT;
			DEBUG_RX.BUF[DEBUG_RX.CNT++] = lub_buff ;
			DEBUG_TX.BUF[DEBUG_TX.CNT++] = lub_buff ;
		}
		else if(DEBUG_RX.CNT < D_USART3_RX_BUF_LEN )
				{
					DEBUG_RX.BUF[DEBUG_RX.CNT++] = lub_buff ;
					DEBUG_TX.BUF[DEBUG_TX.CNT++] = lub_buff ;
				}
				else if(DEBUG_RX.CNT >= D_USART3_RX_BUF_LEN )
						{
							DEBUG_RX.CNT = 0;
							DEBUG_RX.TIMEOUT = 0;
//							memcpy( &DEBUG_RX.BUF[D_USART3_RX_BUF_LEN] , 0x00 , D_USART3_RX_BUF_LEN );
						}
}


void DEBUG_TxProc( void )
{
	if( DEBUG_TX.CNT != 0 )
		{
			if( DEBUG_TX.TIMEOUT != 0)
				{
					M_LED2_ON;
					DEBUG_TX.HEAD = DEBUG_TX.CNT ;
					if( DEBUG_TX.TAIL < DEBUG_TX.HEAD )
							{
								for( uint8_t i = DEBUG_TX.TAIL ; i < DEBUG_TX.HEAD ; i++ )
									{
										HAL_UART_Transmit( &huart3, &DEBUG_TX.BUF[DEBUG_TX.TAIL++] , 1 , 100 ) ;
									}
							}
							else if( DEBUG_TX.TAIL >= DEBUG_TX.HEAD )
									{
										DEBUG_TX.TIMEOUT = 0;
										DEBUG_TX.HEAD = DEBUG_TX.CNT = DEBUG_TX.TAIL = 0 ;
										M_LED2_OFF;
										//										memcpy( &DEBUG_TX.BUF[D_USART3_TX_BUF_LEN] , 0x00 , D_USART3_TX_BUF_LEN );
									}
//							printf( "\r" ) ;
				}
		}
}

void UART3_TxProc(void)
{
	if( USART3_RX.CNT != 0 )
		{
			USART3_RX.TempBUF = USART3_RX.BUF[0];
			if( USART3_RX.TIMEOUT != 0)
				{
					USART3_TX.HEAD = USART3_RX.CNT ;
					if( USART3_TX.TAIL < USART3_TX.HEAD )
						{
							for( uint8_t i = USART3_TX.TAIL ; i < USART3_TX.HEAD ; i++ )
								{
//								UART0_TX_CH( USART3_RX.BUF[USART3_TX.TAIL++] ) ;
									HAL_UART_Transmit( &huart3, &USART3_RX.BUF[USART3_TX.TAIL++] , 1 , 100 ) ;
								}
//							printf( "\r" ) ;

						}
				}
		}
}

/* USER CODE END 1 */
