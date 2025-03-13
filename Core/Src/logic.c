#include "logic.h"
#include "main.h"
#include <stdint.h>
#include <string.h>

#define Reley_Pin GPIO_PIN_9
#define Led_Pin GPIO_PIN_1

extern UART_HandleTypeDef huart1; //Use Uart1 from main.c


#define BUFF_SIZE 5

static uint8_t rData[BUFF_SIZE];
static uint8_t ind = 0;

 void Logic_Init(void) {
	 HAL_GPIO_WritePin(GPIOB, Reley_Pin, GPIO_PIN_RESET);
 }

 void Logic_StartUART(void){
	 HAL_UART_Receive_IT(&huart1, &rData[ind], 1);
 }

 void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart) {
	 if (huart ->Instance==USART1){
			 if (rData[ind] == '\n' || rData[ind] == '\r'){
				 rData[ind] = '\0';

				 if (strcmp((char*)rData, "on") == 0) {
				 HAL_GPIO_WritePin(GPIOB, Reley_Pin, GPIO_PIN_SET);
				 HAL_GPIO_WritePin(GPIOB, Led_Pin, GPIO_PIN_SET);
			 }
				 else if (strcmp((char*)rData, "off") == 0) {
				 HAL_GPIO_WritePin(GPIOB, Reley_Pin, GPIO_PIN_RESET);
				 HAL_GPIO_WritePin(GPIOB, Led_Pin, GPIO_PIN_RESET);

			}

			memset(rData, 0, BUFF_SIZE);
			ind = 0;

			 }

			 else {
				 ind++;
				 if (ind >= BUFF_SIZE - 1){
					 ind = 0;
				 }
			 }


		HAL_UART_Receive_IT(&huart1, &rData[ind], 1 );
	 }
 }

