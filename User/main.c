
#include <string.h>
#include "debug.h"
#include "WS2812.h"
/* EEPROM DATA ADDRESS Length Definition */
#pragma clang diagnostic push
#pragma ide diagnostic ignored "EndlessLoop"
#define Address_8bit  0
#define Address_16bit  1

/* Global Variable */
u16 RxBuffer1[6] = {0};                                             /* USART2 Using */
volatile u8 RxCnt1 = 0;
float Bus_V[8] = {0};
float current[8] = {0};
float power[8] = {0};
int COM_Mode[8] = {0};
int time = 0;
int key = 0;
int old_key = 0;
char isLongTouch = 0;
int alert_flag = 0;

double current_para = 0.00017297;
double Bus_V_para = 0.00120795;

void USART2_IRQHandler(void) __attribute__((interrupt("WCH-Interrupt-fast")));

void DMA1_Channel2_IRQHandler(void) __attribute__((interrupt("WCH-Interrupt-fast")));

void DMA1_Channel3_IRQHandler(void) __attribute__((interrupt("WCH-Interrupt-fast")));


/* EERPOM DATA ADDRESS Length Selection */
#define Address_Lenth   Address_8bit
//#define Address_Lenth   Address_16bit

/* Global Variable */


/*********************************************************************
 * @fn      main
 *
 * @brief   Main program.
 *
 * @return  none
 */
int main(void)
{
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);
    SystemCoreClockUpdate();
    Delay_Init();
    USART_Printf_Init(115200);
    printf("SystemClk:%lu\r\n", SystemCoreClock);
    printf("ChipID:%08lx\r\n", DBGMCU_GetCHIPID());

    WS2812Init();

//  串口屏文本
    char Screen_Txt[20];
    char Index[10];
    volatile uint8_t led = 0;
    u16 temp = 0;

    int j = 0;
    int n = 0;//循环20次刷新一次数据
    while (1)
    {
 
     for (int i = 0; i < 5; ++i)
        {
            if (COM_Mode[i] == CLOSING)
            {
                set6PixelColor(i, 100, 100, 100);
            } else if (COM_Mode[i] == WORKING)
            {
                set6PixelColor(i, 0, 255, 0);
            } else
            {
                set6PixelColor(i, 255, 0, 0);
                alert_flag = 1;
            }

        }
        for (int i = 2; i >= 0; i--)
        {
            if (COM_Mode[i + 5] == CLOSING)
            {
                set3PixelColor(i, 100, 100, 100);
            } else if (COM_Mode[i + 5] == WORKING)
            {
                set3PixelColor(i, 0, 255, 0);
            } else
            {
                set3PixelColor(i, 255, 0, 0);
                alert_flag = 1;
            }

        }
        if (alert_flag ==1){
            set6PixelColor(5, 255, 0, 0);
        } else
        {
            set6PixelColor(5, 10, 10, 255);
        }
        alert_flag = 0;

        w2812_sync();
    }

}

void DMA1_Channel2_IRQHandler(void)
{
    if (DMA_GetFlagStatus(DMA1_FLAG_TC2))
    {
        TIM_Cmd(TIM2, DISABLE);
        DMA_Cmd(DMA1_Channel2, DISABLE);
        DMA_ClearFlag(DMA1_FLAG_TC2);
    }
}

void DMA1_Channel3_IRQHandler(void)
{
    if (DMA_GetFlagStatus(DMA1_FLAG_TC3))
    {
        TIM_Cmd(TIM3, DISABLE);
        DMA_Cmd(DMA1_Channel3, DISABLE);
        DMA_ClearFlag(DMA1_FLAG_TC3);
    }
}

void TIM1_UP_IRQHandler(void) __attribute__((interrupt("WCH-Interrupt-fast")));

#pragma clang diagnostic pop