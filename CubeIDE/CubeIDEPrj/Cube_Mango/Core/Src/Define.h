#ifndef DEFINE_H_
#define DEFINE_H_

#define BAUD_9600               9600
#define BAUD_19200              19200
#define BAUD_38400              38400
#define BAUD_57600              57600
#define BAUD_115200             115200

#define D_KEY_LONG_PRESS_TIME		300

#define _between(x, a, b) 			(a <= x && x <= b)
#define _swap(a, b) 				{ a ^= b; b ^= a; a ^= b; }
#define M_ADC_REAL(a)				(a * 3300) / 4096


#define AM 0x00
#define PM 0x01

#define SYSTEM_Booting 		0x00
#define SYSTEM_RUN 		0x01

// Key Define 
//----------------------------------------------
#define	D_KEY_SET					0x01
#define	D_KEY_LEFT					0x02
#define	D_KEY_UP					0x04
#define	D_KEY_DOWN					0x08
#define	D_KEY_RIGHT					0x10
#define 	D_KEY_PULSE					0x20
#define 	D_KEY_NONE					0x0F
//-----------------------------------------------


// UART Define
//-----------------------------------------------
#define UART_BUFFER_SIZE		80
#define D_USART1_RX_TIMEOUT     250 // MAX 255
#define D_USART1_RX_BUF_LEN     80
#define D_USART1_RX_BUF_CNT     250  

#define D_USART1_TX_TIMEOUT     100 // MAX 255
#define D_USART1_TX_BUF_LEN	120				/* MODULE to ENGINE */
#define D_USART1_TX_BUF_CNT	31

#define D_USART2_RX_TIMEOUT     100// MAX 255
#define D_USART2_RX_BUF_LEN     30
#define D_USART2_RX_BUF_CNT     31

#define D_USART2_TX_TIMEOUT     100 // MAX 255
#define D_USART2_TX_BUF_LEN	30				/* MODULE to ENGINE */
#define D_USART2_TX_BUF_CNT	31

#define D_USART3_RX_TIMEOUT     100 // MAX 255
#define D_USART3_RX_BUF_LEN     250
#define D_USART3_RX_BUF_CNT     250

#define D_USART3_TX_TIMEOUT     100 // MAX 255
#define D_USART3_TX_BUF_LEN	30				/* MODULE to ENGINE */
#define D_USART3_TX_BUF_CNT	31

#define D_BAUD_009600           9600
#define D_BAUD_019200           19200
#define D_BAUD_038400           38400
#define D_BAUD_057600           57600
#define D_BAUD_115200			115200
//------------------------------------------------



//#define UART_BUFFER_SIZE 100 

//	PB3_55 : Button Left 
//	PB4_56 : Button UP
//	PC12_53 : Button Right
//	PA15_50 : Button Down
//	PD_2 : SET  S/W

//0x4001 2400 - 0x4002 1FFF GPIOG
//0x4001 2000 - 0x4002 1BFF GPIOF
//0x4001 1C00 - 0x4002 17FF GPIOH
//0x4001 1800 - 0x4002 13FF GPIOE
//0x4001 1400 - 0x4002 0FFF GPIOD
//0x4001 1000 - 0x4002 0BFF GPIOC
//0x4001 0C00 - 0x4002 07FF GPIOB
//0x4001 0800 - 0x4002 03FF GPIOA

//	15 14    13 12   11 10    _9 _8    _7 _6    _5 _4    _3 _2   _1 _0 	
//0x00 00 _ 00 00 _ 00 00 _ 00 00 _ 00 00 _ 00 00 _ 00 00 _ 00 00
//      F          F           F          F           F          F           F          F 

//	15 14 13 12 _ 11 10 _9 _8 _  _7 _6  _5 _4 _  _3 _2 _1 _0 	
//0x 0   0   0   0     0   0   0   0      0   0   0    0      0   0   0  0
//            F                    F                    F                      F 

#if 1
//PC6
#define M_LED0_OFF   		(*(volatile unsigned *)0x40011010) |= 0x00000040;		 //BRSS 
#define M_LED0_ON 		 	(*(volatile unsigned *)0x40011014) |= 0x0040; 		//BRSS
#define M_LED0_TOGGLE  		(*(volatile unsigned *)0x4001100C) ^= 0x0040;  	//ODR

//PC7
#define M_LED1_OFF   		(*(volatile unsigned *)0x40011010) |= 0x00000080;		 //BRSS 
#define M_LED1_ON 		 	(*(volatile unsigned *)0x40011014) |= 0x0080; 		//BRSS
#define M_LED1_TOGGLE  		(*(volatile unsigned *)0x4001100C) ^= 0x0080;  	//ODR

//PC8
#define M_LED2_OFF   		(*(volatile unsigned *)0x40011010) |= 0x00000100;		 //BRSS 
#define M_LED2_ON 		 	(*(volatile unsigned *)0x40011014) |= 0x0100; 		//BRSS
#define M_LED2_TOGGLE  		(*(volatile unsigned *)0x4001100C) ^= 0x0100;  	//ODR

//PC9
#define M_LED3_OFF   		(*(volatile unsigned *)0x40011010) |= 0x0000200;		 //BRSS 
#define M_LED3_ON 		 	(*(volatile unsigned *)0x40011014) |= 0x0200; 		//BRSS
#define M_LED3_TOGGLE  		(*(volatile unsigned *)0x4001100C) ^= 0x0200; 	 //ODR

//PA11
#define M_LED4_OFF   		(*(volatile unsigned *)0x40010810) |= 0x00000800;		 //BRSS 
#define M_LED4_ON 		 	(*(volatile unsigned *)0x40010814) |= 0x0800; 		//BRSS
#define M_LED4_TOGGLE  		(*(volatile unsigned *)0x4001080C) ^= 0x0800; 	 //ODR

//PA12
#define M_LED5_OFF   		(*(volatile unsigned *)0x40010810) |= 0x00001000;		 //BRSS 
#define M_LED5_ON 		 	(*(volatile unsigned *)0x40010814) |= 0x1000; 		//BRSS
#define M_LED5_TOGGLE  		(*(volatile unsigned *)0x4001080C) ^= 0x1000; 	 //ODR

//LED ALL OFF
#define M_LED_012_ON		(*(volatile unsigned *)0x40011014) |= 0x03C0; // LED 0 ~ 3 OFF
#define M_LED_345_ON		(*(volatile unsigned *)0x40010814) |= 0x1800; // LED 4 ~ 6 OFF

//LED ALL ON
#define M_LED_012_OFF		(*(volatile unsigned *)0x40011010) |= 0x000003C0; // LED 0 ~ 3 OFF
#define M_LED_345_OFF		(*(volatile unsigned *)0x40010810) |= 0x00001800; // LED 4 ~ 6 OFF
#else
#define M_LED0_OFF			HAL_GPIO_WritePin(GPIOC, GPIO_PIN_7 , GPIO_PIN_SET)
#define M_LED0_ON			HAL_GPIO_WritePin(GPIOC, GPIO_PIN_7 , GPIO_PIN_RESET)
#define M_LED0_TOGGLE		HAL_GPIO_TogglePin( GPIOC, GPIO_PIN_7 )

#define M_LED1_OFF			HAL_GPIO_WritePin(GPIOC, GPIO_PIN_8 , GPIO_PIN_SET)
#define M_LED1_ON			HAL_GPIO_WritePin(GPIOC, GPIO_PIN_8 , GPIO_PIN_RESET)
#define M_LED1_TOGGLE		HAL_GPIO_TogglePin( GPIOC, GPIO_PIN_8 )

#define M_LED2_OFF			HAL_GPIO_WritePin(GPIOC, GPIO_PIN_9 , GPIO_PIN_SET)
#define M_LED2_ON			HAL_GPIO_WritePin(GPIOC, GPIO_PIN_9 , GPIO_PIN_RESET)
#define M_LED2_TOGGLE		HAL_GPIO_TogglePin( GPIOC, GPIO_PIN_9 )

#define M_LED3_OFF			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8 , GPIO_PIN_SET)
#define M_LED3_ON			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8 , GPIO_PIN_RESET)
#define M_LED3_TOGGLE		HAL_GPIO_TogglePin( GPIOA, GPIO_PIN_8 )

#define M_LED4_OFF			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11 , GPIO_PIN_SET)
#define M_LED4_ON			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11 , GPIO_PIN_RESET)
#define M_LED4_TOGGLE		HAL_GPIO_TogglePin( GPIOA, GPIO_PIN_11 )

#define M_LED5_OFF			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12 , GPIO_PIN_SET)
#define M_LED5_ON			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12 , GPIO_PIN_RESET)
#define M_LED5_TOGGLE		HAL_GPIO_TogglePin( GPIOA, GPIO_PIN_12 )

//LED ALL OFF
#define M_LED_012_ON		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_7 | GPIO_PIN_8 | GPIO_PIN_9 , GPIO_PIN_RESET); // LED 0 ~ 3 OFF
#define M_LED_345_ON		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8 | GPIO_PIN_11 | GPIO_PIN_12 , GPIO_PIN_RESET); // LED 4 ~ 6 OFF

//LED ALL ON
#define M_LED_012_OFF		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_7 | GPIO_PIN_8 | GPIO_PIN_9 , GPIO_PIN_SET); // LED 0 ~ 3 OFF
#define M_LED_345_OFF		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8 | GPIO_PIN_11 | GPIO_PIN_12 , GPIO_PIN_SET); // LED 4 ~ 6 OFF

#endif


//==========================================
// USART DEFINE
//==========================================
#define  String const unsigned char
#endif
