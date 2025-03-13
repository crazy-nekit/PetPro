#include "logic.h"
#include "main.h"
#include <stdint.h>
#include <string.h>

#define Reley_Pin GPIO_PIN_9
#define Led_Pin GPIO_PIN_1

extern UART_HandleTypeDef huart1; //Use Uart1 from main.c

static uint8_t rData;

 void Logic_Init(void) {
	 HAL_GPIO_WritePin(GPIOB, Reley_Pin, GPIO_PIN_RESET);
 }

 void Logic_StartUART(void){
	 HAL_UART_Receive_IT(&huart1, &rData, 1);
 }

 void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart) {
	 if (huart ->Instance==USART1){
		 if (rData == '1'){
			 HAL_GPIO_WritePin(GPIOB, Reley_Pin, GPIO_PIN_SET);
			 HAL_GPIO_WritePin(GPIOB, Led_Pin, GPIO_PIN_SET);
		 }
		 else if (rData == '0') {
			 HAL_GPIO_WritePin(GPIOB, Reley_Pin, GPIO_PIN_RESET);
			 HAL_GPIO_WritePin(GPIOB, Led_Pin, GPIO_PIN_RESET);

		}

		 HAL_UART_Receive_IT(&huart1, &rData, 1);
	 }
 }

