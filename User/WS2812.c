//
// Created by 86180 on 2024/7/21.
//

#include "WS2818.h"
/* PWM Output Mode Definition */
uint16_t color_buf6[COLOR6_BUFFER_LEN] = {0};
uint16_t color_buf3[COLOR3_BUFFER_LEN] = {0};

void WS2812Init(){
    TIM2_PWMOut_Init(10-1, 12-1, 0);
    TIM3_PWMOut_Init(10-1, 12-1, 0);
    TIM2_DMA_Init(DMA1_Channel2, (u32)TIM2_CH2CVR_ADDRESS, COLOR6_BUFFER_LEN);
    TIM3_DMA_Init(DMA1_Channel3, (u32)TIM3_CH2CVR_ADDRESS, COLOR3_BUFFER_LEN);
    TIM_DMACmd(TIM2, TIM_DMA_Update, ENABLE);
    TIM_DMACmd(TIM3, TIM_DMA_Update, ENABLE);
    TIM_Cmd(TIM2, ENABLE);
    TIM_Cmd(TIM3, ENABLE);
    TIM_CtrlPWMOutputs(TIM2, ENABLE);
    TIM_CtrlPWMOutputs(TIM3, ENABLE);
    for (int i = 0; i < 6; i++) {
        set6PixelColor(i, 0, 0, 0);
    }
    for (int i = 0; i < 3; i++) {
        set3PixelColor(i, 0, 0, 0);
    }
    set3PixelColor(2, 0, 255, 0);

}

void set6PixelColor(uint16_t id, uint8_t r, uint8_t g, uint8_t b)
{
    int i = 0, j = id * 24u;
    if (id >= 6) {
        return;
    }

    for (i = 0; i < 8; i++) {
        if (g & (0x80 >> i)) {
            color_buf6[j] = CODE_1;
        } else {
            color_buf6[j] = CODE_0;
        }
        j++;
    }
    for (i = 0; i < 8; i++) {
        if (r & (0x80 >> i)) {
            color_buf6[j] = CODE_1;
        } else {
            color_buf6[j] = CODE_0;
        }
        j++;
    }
    for (i = 0; i < 8; i++) {
        if (b & (0x80 >> i)) {
            color_buf6[j] = CODE_1;
        } else {
            color_buf6[j] = CODE_0;
        }
        j++;
    }
}

///
/// \param id
/// \param r
/// \param g
/// \param b
void set3PixelColor(uint16_t id, uint8_t r, uint8_t g, uint8_t b)
{
    int i = 0, j = id * 24u;
    if (id >= 4) {
        return;
    }

    for (i = 0; i < 8; i++) {
        if (g & (0x80 >> i)) {
            color_buf3[j] = CODE_1;
        } else {
            color_buf3[j] = CODE_0;
        }
        j++;
    }
    for (i = 0; i < 8; i++) {
        if (r & (0x80 >> i)) {
            color_buf3[j] = CODE_1;
        } else {
            color_buf3[j] = CODE_0;
        }
        j++;
    }
    for (i = 0; i < 8; i++) {
        if (b & (0x80 >> i)) {
            color_buf3[j] = CODE_1;
        } else {
            color_buf3[j] = CODE_0;
        }
        j++;
    }
}

void w2812_sync()
{
    while(DMA_GetCurrDataCounter(DMA1_Channel2)!=0);
    DMA_SetCurrDataCounter(DMA1_Channel2, COLOR6_BUFFER_LEN);
    DMA_Cmd( DMA1_Channel2, ENABLE);
    TIM_Cmd( TIM2, ENABLE);
    while(DMA_GetCurrDataCounter(DMA1_Channel3)!=0);
    DMA_SetCurrDataCounter(DMA1_Channel3, COLOR3_BUFFER_LEN);
    DMA_Cmd( DMA1_Channel3, ENABLE);
    TIM_Cmd( TIM3, ENABLE);

}

void TIM2_PWMOut_Init(u16 arr, u16 psc, u16 ccp)
{
    GPIO_InitTypeDef        GPIO_InitStructure = {0};
    TIM_OCInitTypeDef       TIM_OCInitStructure = {0};
    TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure = {0};

    RCC_PB2PeriphClockCmd(RCC_PB2Periph_GPIOA, ENABLE);
    RCC_PB1PeriphClockCmd(RCC_PB1Periph_TIM2,ENABLE);
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_InitStructure);

    TIM_TimeBaseInitStructure.TIM_Period = arr;
    TIM_TimeBaseInitStructure.TIM_Prescaler = psc;
    TIM_TimeBaseInitStructure.TIM_ClockDivision = TIM_CKD_DIV1;
    TIM_TimeBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up;
    TIM_TimeBaseInitStructure.TIM_RepetitionCounter = 0;
    TIM_TimeBaseInit(TIM2, &TIM_TimeBaseInitStructure);

    TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
    TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
    TIM_OCInitStructure.TIM_Pulse = ccp;
    TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
    TIM_OC2Init(TIM2, &TIM_OCInitStructure);

    TIM_OC2PreloadConfig(TIM2, TIM_OCPreload_Disable);
    TIM_ARRPreloadConfig(TIM2, ENABLE);
}
void TIM3_PWMOut_Init(u16 arr, u16 psc, u16 ccp)
{
    GPIO_InitTypeDef        GPIO_InitStructure = {0};
    TIM_OCInitTypeDef       TIM_OCInitStructure = {0};
    TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure = {0};

    RCC_PB2PeriphClockCmd(RCC_PB2Periph_GPIOA, ENABLE);
    RCC_PB1PeriphClockCmd(RCC_PB1Periph_TIM3,ENABLE);
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_InitStructure);

    TIM_TimeBaseInitStructure.TIM_Period = arr;
    TIM_TimeBaseInitStructure.TIM_Prescaler = psc;
    TIM_TimeBaseInitStructure.TIM_ClockDivision = TIM_CKD_DIV1;
    TIM_TimeBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up;
    TIM_TimeBaseInitStructure.TIM_RepetitionCounter = 0;
    TIM_TimeBaseInit(TIM3, &TIM_TimeBaseInitStructure);

    TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
    TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
    TIM_OCInitStructure.TIM_Pulse = ccp;
    TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
    TIM_OC2Init(TIM3, &TIM_OCInitStructure);

    TIM_OC2PreloadConfig(TIM3, TIM_OCPreload_Disable);
    TIM_ARRPreloadConfig(TIM3, ENABLE);
}

void TIM2_DMA_Init(DMA_Channel_TypeDef *DMA_CHx, u32 ppadr, u16 bufsize)
{
    DMA_InitTypeDef DMA_InitStructure = {0};
    NVIC_InitTypeDef NVIC_InitStructure = {0};
    RCC_HBPeriphClockCmd(RCC_HBPeriph_DMA1, ENABLE);

    DMA_DeInit(DMA_CHx);
    DMA_Cmd(DMA_CHx,DISABLE);
    DMA_InitStructure.DMA_PeripheralBaseAddr = ppadr;
    DMA_InitStructure.DMA_MemoryBaseAddr = (uint32_t )color_buf6;
    DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralDST;
    DMA_InitStructure.DMA_BufferSize = bufsize;
    DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
    DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;
    DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Word;
    DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_HalfWord;
    DMA_InitStructure.DMA_Mode = DMA_Mode_Normal;
    DMA_InitStructure.DMA_Priority = DMA_Priority_VeryHigh;
    DMA_InitStructure.DMA_M2M = DMA_M2M_Disable;
    DMA_Init(DMA_CHx, &DMA_InitStructure);

    DMA_Cmd(DMA_CHx, ENABLE);

    DMA_ITConfig( DMA1_Channel2, DMA_IT_TC, ENABLE);
    NVIC_InitStructure.NVIC_IRQChannel = DMA1_Channel2_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);

}
void TIM3_DMA_Init(DMA_Channel_TypeDef *DMA_CHx, u32 ppadr, u16 bufsize)
{
    DMA_InitTypeDef DMA_InitStructure = {0};
    NVIC_InitTypeDef NVIC_InitStructure = {0};
    RCC_HBPeriphClockCmd(RCC_HBPeriph_DMA1, ENABLE);

    DMA_DeInit(DMA_CHx);
    DMA_Cmd(DMA_CHx,DISABLE);
    DMA_InitStructure.DMA_PeripheralBaseAddr = ppadr;
    DMA_InitStructure.DMA_MemoryBaseAddr = (uint32_t )color_buf3;
    DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralDST;
    DMA_InitStructure.DMA_BufferSize = bufsize;
    DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
    DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;
    DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_HalfWord;
    DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_HalfWord;
    DMA_InitStructure.DMA_Mode = DMA_Mode_Normal;
    DMA_InitStructure.DMA_Priority = DMA_Priority_VeryHigh;
    DMA_InitStructure.DMA_M2M = DMA_M2M_Disable;
    DMA_Init(DMA_CHx, &DMA_InitStructure);

    DMA_Cmd(DMA_CHx, ENABLE);

    DMA_ITConfig( DMA1_Channel3, DMA_IT_TC, ENABLE);
    NVIC_InitStructure.NVIC_IRQChannel = DMA1_Channel3_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);

}

/*
 * A4 A5 A6 B0 B1 五个键盘开关
 * B1 大按钮
 * B2 B3 B4 三个键盘开关
 * B5 继电器
 * A1 5个灯
 * A7 3个灯
 * B8 usb路径切换

 */
