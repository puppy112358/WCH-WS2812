//
// Created by 86180 on 2024/7/8.
//

#ifndef L103PRO_UART_H
#define L103PRO_UART_H
#include "ch32l103.h"

enum gongneng
{
    kaiguan = 1,
    not_baojing = 2,
    dianliu = 3,
};
void USART_Send(USART_TypeDef *_UART,u8 *data, u8 len);
void USART2_Init(void);
void clear_TJC();

#endif //L103PRO_UART_H
