//
// Created by 86180 on 2024/7/20.
//
/*
 * A4 A5 A6 B0 B1 五个键盘开关
 * B1 大按钮
 * B2 B3 B4 三个键盘开关
 * B5 继电器
 * A1 5个灯
 * A7 3个灯
 * B8 usb路径切换
 */

#include "KAIGUAN.h"
#include "debug.h"
//开关使能
void kaiguan_Init(){
    RCC_PB2PeriphClockCmd(RCC_PB2Periph_GPIOA, ENABLE);
    RCC_PB2PeriphClockCmd(RCC_PB2Periph_GPIOB, ENABLE);

    GPIO_InitTypeDef GPIO_InitStructure;
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_11 | GPIO_Pin_12 | GPIO_Pin_15 | GPIO_Pin_8;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_6;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9 | GPIO_Pin_5 | GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOB, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_4;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOB, &GPIO_InitStructure);
    GPIO_WriteBit(GPIOB, GPIO_Pin_12, 0);
    GPIO_WriteBit(GPIOB, GPIO_Pin_13, 0);
    GPIO_WriteBit(GPIOB, GPIO_Pin_14, 0);
    GPIO_WriteBit(GPIOA, GPIO_Pin_15, 0);
    GPIO_WriteBit(GPIOA, GPIO_Pin_8,  0);
    GPIO_WriteBit(GPIOA, GPIO_Pin_11, 0);
    GPIO_WriteBit(GPIOA, GPIO_Pin_12, 0);
    GPIO_WriteBit(GPIOB, GPIO_Pin_5, 1);//继电器
    GPIO_WriteBit(GPIOB, GPIO_Pin_9, 1);//大开关

}
int ReadKey(){
    if (jianpan1 == 0){
        return 1;
    } else if (jianpan2==0){
        return 2;
    }
    else if (jianpan3 == 0){
        return 3;
    }
    else if (jianpan4 == 0){
        return 4;
    }
    else if (jianpan5 == 0){
        return 5;
    }
    else if (jianpan6 == 0){
        return 6;
    }
    else if (jianpan7 == 0){
        return 7;
    }
    else if (jianpan8 == 0){
        return 8;
    }
    return 0;
}
void TIM1_Config(void)
{
    TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;

    // 开启定时器时钟
    RCC_PB2PeriphClockCmd(RCC_PB2Periph_TIM1, ENABLE);
    // 自动重装载寄存器周的值(计数值)1MS中断一次
    TIM_TimeBaseStructure.TIM_Period=1000;

    // 累计TIM_Period个频率后产生一个更新或者中断
    // 时钟预分频数为96-1，则驱动计数器的时钟CK_CNT = CK_INT / 96=1M
    TIM_TimeBaseStructure.TIM_Prescaler= 96-1;

    // 时钟分频因子 ，基本定时器没有，不用管
    TIM_TimeBaseStructure.TIM_ClockDivision=TIM_CKD_DIV1;

    // 计数器计数模式，基本定时器只能向上计数，没有计数模式的设置
    TIM_TimeBaseStructure.TIM_CounterMode=TIM_CounterMode_Up;

    // 重复计数器的值，基本定时器没有，不用管
    TIM_TimeBaseStructure.TIM_RepetitionCounter=0;

    // 初始化定时器
    TIM_TimeBaseInit(TIM1, &TIM_TimeBaseStructure);

    // 清除计数器中断标志位
    TIM_ClearFlag(TIM1, TIM_FLAG_Update);

    // 开启计数器中断
    TIM_ITConfig(TIM1,TIM_IT_Update,ENABLE);

    // 使能计数器
    TIM_Cmd(TIM1, ENABLE);

    // 暂时关闭定时器的时钟，等待使用
    RCC_PB2PeriphClockCmd(RCC_PB2Periph_TIM1, DISABLE);
}

// 中断优先级配置
void TIM1_NVIC_Config(void)
{
    NVIC_InitTypeDef NVIC_InitStructure;
    // 设置中断组为0
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);
    // 设置中断来源
    NVIC_InitStructure.NVIC_IRQChannel = TIM1_UP_IRQn ;
    // 设置主优先级为 0
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
    // 设置抢占优先级为3
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);
}