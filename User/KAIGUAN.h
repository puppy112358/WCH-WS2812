//
// Created by 86180 on 2024/7/20.
//

#ifndef L103PRO_USER_KAIGUAN_H_
#define L103PRO_USER_KAIGUAN_H_

#define  kaiguan1 COM_Mode[0]==WORKING?GPIO_WriteBit(GPIOA, GPIO_Pin_8, 1):GPIO_WriteBit(GPIOA, GPIO_Pin_8, 0)
#define  kaiguan2 COM_Mode[1]==WORKING?GPIO_WriteBit(GPIOB, GPIO_Pin_14, 1):GPIO_WriteBit(GPIOB, GPIO_Pin_14, 0)
#define  kaiguan3 COM_Mode[2]==WORKING?GPIO_WriteBit(GPIOA, GPIO_Pin_15, 1):GPIO_WriteBit(GPIOA, GPIO_Pin_15, 0)
#define  kaiguan4 COM_Mode[3]==WORKING?GPIO_WriteBit(GPIOB, GPIO_Pin_12, 1):GPIO_WriteBit(GPIOB, GPIO_Pin_12, 0)
#define  kaiguan5 COM_Mode[4]==WORKING?GPIO_WriteBit(GPIOA, GPIO_Pin_11,  1):GPIO_WriteBit(GPIOA, GPIO_Pin_11,  0)
#define  kaiguan6 COM_Mode[5]==WORKING?GPIO_WriteBit(GPIOB, GPIO_Pin_13, 1):GPIO_WriteBit(GPIOB, GPIO_Pin_13, 0)
#define  kaiguan7 COM_Mode[6]==WORKING?GPIO_WriteBit(GPIOB, GPIO_Pin_13, 1):GPIO_WriteBit(GPIOB, GPIO_Pin_13, 0)
#define  kaiguan8 COM_Mode[7]==WORKING?GPIO_WriteBit(GPIOA, GPIO_Pin_12, 1):GPIO_WriteBit(GPIOA, GPIO_Pin_12, 0)

#define jianpan1 GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_4)
#define jianpan2 GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_5)
#define jianpan3 GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_6)
#define jianpan4 GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_0)
#define jianpan5 GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_1)
#define jianpan8 GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_4)
#define jianpan7 GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_3)
#define jianpan6 GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_2)

enum working_mode
{
    CLOSING = 0,
    WORKING = 1,
    ALARMING
};

void kaiguan_Init();

void TIM1_Config(void);

void TIM1_NVIC_Config(void);

int ReadKey();


#endif //L103PRO_USER_KAIGUAN_H_
