#include "uart.h"
#include "TJCScreen.h"
//串口屏清屏
void clear_TJC(){
    char Screen_Txt[20];
    char Index[3];
    // 电压显示初始化
    for (int i = 1; i < 22; i += 3) {
        sprintf(Screen_Txt, "电压：%.4fV",0.0);
        sprintf(Index, "t%d", i);
        TCJSendTxt(Index, Screen_Txt);
    }
    // 电流显示初始化
    for (int i = 0; i < 21; i += 3) {
        sprintf(Screen_Txt, "电流：%.4fA", 0.0);
        sprintf(Index, "t%d", i);
        TCJSendTxt(Index, Screen_Txt);
    }
    // 功耗显示初始化
    for (int i = 2; i < 23; i += 3) {
        sprintf(Screen_Txt, "功耗：%.4fW", 0.0);
        sprintf(Index, "t%d", i);
        TCJSendTxt(Index, Screen_Txt);
    }
    // 图片显示初始化
    for (int i = 0; i < 7; i++) {
        sprintf(Index, "p%d", i);
        TCJSetPic(Index, 0);
    }

}
/*******************************************************************************
  * @函数名称	USART_Send
  * @函数说明   发送信息
  * @输入参数   _UART：串口号
								data：要发送的信息的首地址
                len： 发送的长度
  * @输出参数   无
  * @返回参数   无
*******************************************************************************/
void USART_Send(USART_TypeDef *_UART,u8 *data, u8 len)
{
    for(int i = 0; i < len; i++)
    {
        USART_SendData(_UART, data[i]); //向串口发送数据
        while(USART_GetFlagStatus(_UART, USART_FLAG_TXE) == RESET); //等待发送结束
    }
}
/*********************************************************************
 * @fn      USART2_Init
 *
 * @brief   Initializes the USART2  peripheral.
 *
 * @return  none
 */
void USART2_Init(void)
{
    GPIO_InitTypeDef  GPIO_InitStructure = {0};
    USART_InitTypeDef USART_InitStructure = {0};
    NVIC_InitTypeDef  NVIC_InitStructure = {0};

    RCC_PB1PeriphClockCmd(RCC_PB1Periph_USART2, ENABLE);
    RCC_PB2PeriphClockCmd(RCC_PB2Periph_GPIOA , ENABLE);

    /* USART2 TX-->A.2   RX-->A.3 */
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_Init(GPIOA, &GPIO_InitStructure);
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    GPIO_Init(GPIOA, &GPIO_InitStructure);


    USART_InitStructure.USART_BaudRate = 115200;
    USART_InitStructure.USART_WordLength = USART_WordLength_8b;
    USART_InitStructure.USART_StopBits = USART_StopBits_1;
    USART_InitStructure.USART_Parity = USART_Parity_No;
    USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
    USART_InitStructure.USART_Mode = USART_Mode_Tx | USART_Mode_Rx;

    USART_Init(USART2, &USART_InitStructure);
    USART_ITConfig(USART2, USART_IT_RXNE, ENABLE);
    USART_ITConfig(USART2, USART_IT_IDLE, ENABLE);

    NVIC_InitStructure.NVIC_IRQChannel = USART2_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);

    USART_Cmd(USART2, ENABLE);
}

