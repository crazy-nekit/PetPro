#ifndef LOGIC_H
#define LOGIC_H

#include "main.h"

void Logic_Init(void);
void Logic_StartUART(void);
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart);

#endif
