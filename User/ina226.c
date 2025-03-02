//
// Created by 86180 on 2024/6/5.
//

#include "ina226.h"

__attribute__((unused)) u8 INA226_ReadByte(u8 device_addr, u8 reg_addr) {
    u8 temp = 0;
//
    while (I2C_GetFlagStatus(I2C2, I2C_FLAG_BUSY) != RESET);
    I2C_GenerateSTART(I2C2, ENABLE);

    while (!I2C_CheckEvent(I2C2, I2C_EVENT_MASTER_MODE_SELECT));
    I2C_Send7bitAddress(I2C2, device_addr, I2C_Direction_Transmitter);

    while (!I2C_CheckEvent(I2C2, I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED));

#if (Address_Lenth == Address_8bit)
    I2C_SendData(I2C2, reg_addr);
    while (!I2C_CheckEvent(I2C2, I2C_EVENT_MASTER_BYTE_TRANSMITTED));

#elif (Address_Lenth == Address_16bit)
    I2C_SendData( I2C2, (u8)(reg_addr>>8) );
    while( !I2C_CheckEvent( I2C2, I2C_EVENT_MASTER_BYTE_TRANSMITTED ) );

    I2C_SendData( I2C2, (u8)(reg_addr&0x00FF) );
    while( !I2C_CheckEvent( I2C2, I2C_EVENT_MASTER_BYTE_TRANSMITTED ) );

#endif

    I2C_GenerateSTART(I2C2, ENABLE);

    while (!I2C_CheckEvent(I2C2, I2C_EVENT_MASTER_MODE_SELECT));
    I2C_Send7bitAddress(I2C2, device_addr, I2C_Direction_Receiver);

    while (!I2C_CheckEvent(I2C2, I2C_EVENT_MASTER_RECEIVER_MODE_SELECTED));
    while (I2C_GetFlagStatus(I2C2, I2C_FLAG_RXNE) == RESET);
    I2C_AcknowledgeConfig(I2C2, DISABLE);

    temp = I2C_ReceiveData(I2C2);
    I2C_GenerateSTOP(I2C2, ENABLE);

    return temp;
}

__attribute__((unused)) void INA226_WriteByte(u8 device_addr, u8 reg_addr, u8 reg_data) {
    while (I2C_GetFlagStatus(I2C2, I2C_FLAG_BUSY) != RESET);
    I2C_GenerateSTART(I2C2, ENABLE);

    while (!I2C_CheckEvent(I2C2, I2C_EVENT_MASTER_MODE_SELECT));
    I2C_Send7bitAddress(I2C2, device_addr, I2C_Direction_Transmitter);
//    Delay_Ms(20);

    while (!I2C_CheckEvent(I2C2, I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED));

#if (Address_Lenth == Address_8bit)
    I2C_SendData(I2C2, reg_addr);
    while (!I2C_CheckEvent(I2C2, I2C_EVENT_MASTER_BYTE_TRANSMITTED));

#elif (Address_Lenth == Address_16bit)
    I2C_SendData( I2C2, (u8)(reg_addr>>8) );
    while( !I2C_CheckEvent( I2C2, I2C_EVENT_MASTER_BYTE_TRANSMITTED ) );

    I2C_SendData( I2C2, (u8)(reg_addr&0x00FF) );
    while( !I2C_CheckEvent( I2C2, I2C_EVENT_MASTER_BYTE_TRANSMITTED ) );

#endif

    if (I2C_GetFlagStatus(I2C2, I2C_FLAG_TXE) != RESET) {
        I2C_SendData(I2C2, reg_data);
    }

    while (!I2C_CheckEvent(I2C2, I2C_EVENT_MASTER_BYTE_TRANSMITTED));
    I2C_GenerateSTOP(I2C2, ENABLE);
}

u8 INA226_Read2Byte_I2C2(u8 device_addr, u8 reg_addr, u16 *data) {
    u8 buffer[2] = {0};
    u16 temp = 0;

    int waiting = 0;
    while (I2C_GetFlagStatus(I2C2, I2C_FLAG_BUSY) != RESET) {
        Delay_Us(10);
        waiting++;
        if (waiting > 10000) {
            printf("BUSY\r\n");
            I2C_GenerateSTOP(I2C2, ENABLE);
            return 1;
        }

    }
    I2C_GenerateSTART(I2C2, ENABLE);
    waiting = 0;
    while (!I2C_CheckEvent(I2C2, I2C_EVENT_MASTER_MODE_SELECT));
    I2C_Send7bitAddress(I2C2, device_addr, I2C_Direction_Transmitter);
    Delay_Ms(10);
    while (!I2C_CheckEvent(I2C2, I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED)) {
        Delay_Us(10);
        waiting++;
        if (waiting > 10000) {
//            printf("I2C2 I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED error\r\n");
            I2C_GenerateSTOP(I2C2, ENABLE);
            return 1;

        }
    }

#if (Address_Lenth == Address_8bit)
    I2C_SendData(I2C2, reg_addr);
//    Delay_Ms(10);
    while (!I2C_CheckEvent(I2C2, I2C_EVENT_MASTER_BYTE_TRANSMITTED));

#elif (Address_Lenth == Address_16bit)
    I2C_SendData( I2C2, (u8)(reg_addr>>8) );
    while( !I2C_CheckEvent( I2C2, I2C_EVENT_MASTER_BYTE_TRANSMITTED ) );

    I2C_SendData( I2C2, (u8)(reg_addr&0x00FF) );
    while( !I2C_CheckEvent( I2C2, I2C_EVENT_MASTER_BYTE_TRANSMITTED ) );

#endif

    I2C_GenerateSTART(I2C2, ENABLE);

    while (!I2C_CheckEvent(I2C2, I2C_EVENT_MASTER_MODE_SELECT));
    I2C_Send7bitAddress(I2C2, device_addr, I2C_Direction_Receiver);
    waiting = 0;
    while (!I2C_CheckEvent(I2C2, I2C_EVENT_MASTER_RECEIVER_MODE_SELECTED)) {
        Delay_Us(10);
        waiting++;
        if (waiting > 10000) {
//            printf("I2C2 I2C_EVENT_MASTER_RECEIVER_MODE_SELECTED error\r\n");
            I2C_GenerateSTOP(I2C2, ENABLE);
            return 1;
        }
    }
    while (I2C_GetFlagStatus(I2C2, I2C_FLAG_RXNE) == RESET);
    buffer[0] = I2C_ReceiveData(I2C2);
    while (!I2C_CheckEvent(I2C2, I2C_EVENT_MASTER_BYTE_RECEIVED));
    buffer[1] = I2C_ReceiveData(I2C2);
    I2C_AcknowledgeConfig(I2C2, ENABLE);

//    t1 = I2C_ReceiveData(I2C2);

    I2C_GenerateSTOP(I2C2, ENABLE);
    temp = buffer[0] << 8 | buffer[1];

    *data = temp;
    return 0;
}


u8 INA226_Read2Byte_I2C1(u8 device_addr, u8 reg_addr, u16 *data) {
    u8 buffer[2] = {0};
    u16 temp = 0;
    int waiting = 0;
    while (I2C_GetFlagStatus(I2C1, I2C_FLAG_BUSY) != RESET) {
        Delay_Us(10);
        waiting ++;
        if (waiting > 10000){
//            printf("I2C1 I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED error\r\n");
            I2C_GenerateSTOP(I2C1, ENABLE);
            return 1;
        }
    };
    I2C_GenerateSTART(I2C1, ENABLE);

    while (!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_MODE_SELECT));
    I2C_Send7bitAddress(I2C1, device_addr, I2C_Direction_Transmitter);

    waiting = 0;
//    Delay_Ms(10);
    while (!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED)) {
        Delay_Us(10);
        waiting++;
        if (waiting > 10000) {
//            printf("I2C1 I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED error\r\n");
            I2C_GenerateSTOP(I2C1, ENABLE);
            return 1;
        }
    }

#if (Address_Lenth == Address_8bit)
    I2C_SendData(I2C1, reg_addr);

//    Delay_Ms(10);
    waiting = 0;
    while (!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_BYTE_TRANSMITTED)){
        Delay_Us(10);
        waiting++;
        if (waiting > 10000) {
//            printf("I2C1 I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED error\r\n");
            I2C_GenerateSTOP(I2C1, ENABLE);
            return 1;
        }
    }

#elif (Address_Lenth == Address_16bit)
    I2C_SendData( I2C1, (u8)(reg_addr>>8) );
    while( !I2C_CheckEvent( I2C1, I2C_EVENT_MASTER_BYTE_TRANSMITTED ) );

    I2C_SendData( I2C1, (u8)(reg_addr&0x00FF) );
    while( !I2C_CheckEvent( I2C1, I2C_EVENT_MASTER_BYTE_TRANSMITTED ) );

#endif

    I2C_GenerateSTART(I2C1, ENABLE);

    while (!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_MODE_SELECT));
    I2C_Send7bitAddress(I2C1, device_addr, I2C_Direction_Receiver);
    waiting = 0;
    while (!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_RECEIVER_MODE_SELECTED)) {
        Delay_Us(10);
        waiting++;
        if (waiting > 10000) {
//            printf("I2C1 I2C_EVENT_MASTER_RECEIVER_MODE_SELECTED error\r\n");
            I2C_GenerateSTOP(I2C1, ENABLE);
            return 1;
        }
    }
    while (I2C_GetFlagStatus(I2C1, I2C_FLAG_RXNE) == RESET);
    buffer[0] = I2C_ReceiveData(I2C1);
    while (!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_BYTE_RECEIVED));
    buffer[1] = I2C_ReceiveData(I2C1);
    I2C_AcknowledgeConfig(I2C1, ENABLE);


    I2C_GenerateSTOP(I2C1, ENABLE);
    temp = buffer[0] << 8 | buffer[1];

    *data = temp;
    return 0;
}

void INA226_Write2Byte_I2C2(u8 device_addr, u8 reg_addr, u16 reg_data) {
    u8 data_high = (u8) ((reg_data & 0xFF00) >> 8);
    u8 data_low = (u8) reg_data & 0x00FF;
//    INA226_WriteByte(reg_addr, data_high);
//    Delay_Ms(10);
//    INA226_WriteByte(reg_addr+1, data_low);
    int waiting = 0;
    while (I2C_GetFlagStatus(I2C2, I2C_FLAG_BUSY) != RESET) {
        Delay_Us(10);
        waiting++;
        if (waiting > 10000) {
//            printf("I2C2 BUSY\r\n");
            I2C_GenerateSTOP(I2C2, ENABLE);
            return;
        }
    }
    I2C_GenerateSTART(I2C2, ENABLE);

    waiting = 0;
    while (!I2C_CheckEvent(I2C2, I2C_EVENT_MASTER_MODE_SELECT)) {
        Delay_Us(10);
        waiting++;
        if (waiting > 10000) {
//            printf("I2C2 BUSY\r\n");
            I2C_GenerateSTOP(I2C2, ENABLE);
            return;
        }
    }
    I2C_Send7bitAddress(I2C2, device_addr, I2C_Direction_Transmitter);
//    Delay_Ms(20);

    waiting = 0;
    while (!I2C_CheckEvent(I2C2, I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED)) {
        Delay_Us(10);
        waiting++;
        if (waiting > 10000) {
//            printf("I2C2 I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED error\r\n");
            I2C_GenerateSTOP(I2C2, ENABLE);
            return;
        }
    }

#if (Address_Lenth == Address_8bit)
    I2C_SendData(I2C2, reg_addr);
//    Delay_Ms(10);
    waiting = 0;
    while (!I2C_CheckEvent(I2C2, I2C_EVENT_MASTER_BYTE_TRANSMITTED)) {
        waiting++;
        Delay_Us(10);
        if (waiting > 10000) {
//            printf("I2C2 I2C_EVENT_MASTER_BYTE_TRANSMITTED error\r\n");
            I2C_GenerateSTOP(I2C2, ENABLE);
            return;
        }


    }

#elif (Address_Lenth == Address_16bit)
    I2C_SendData( I2C2, (u8)(reg_addr>>8) );
    while( !I2C_CheckEvent( I2C2, I2C_EVENT_MASTER_BYTE_TRANSMITTED ) );

    I2C_SendData( I2C2, (u8)(reg_addr&0x00FF) );
    while( !I2C_CheckEvent( I2C2, I2C_EVENT_MASTER_BYTE_TRANSMITTED ) );

#endif

    if (I2C_GetFlagStatus(I2C2, I2C_FLAG_TXE) != RESET) {
        I2C_SendData(I2C2, data_high);
//        Delay_Ms(20);
        while (!I2C_CheckEvent(I2C2, I2C_EVENT_MASTER_BYTE_TRANSMITTED));
        I2C_SendData(I2C2, data_low);
//        Delay_Ms(20);
//        I2C_SendData(I2C2, data_low);

    }
    waiting = 0;
    while (!I2C_CheckEvent(I2C2, I2C_EVENT_MASTER_BYTE_TRANSMITTED)) {
        Delay_Us(10);
        waiting++;
        if (waiting > 10000) {
//            printf("I2C2 I2C_EVENT_MASTER_BYTE_TRANSMITTED error\r\n");
            I2C_GenerateSTOP(I2C2, ENABLE);
            return;
        }

    }
    I2C_GenerateSTOP(I2C2, ENABLE);
    Delay_Ms(10);

}

void INA226_Write2Byte_I2C1(u8 device_addr, u8 reg_addr, u16 reg_data) {
    u8 data_high = (u8) ((reg_data & 0xFF00) >> 8);
    u8 data_low = (u8) reg_data & 0x00FF;
//    INA226_WriteByte(reg_addr, data_high);
//    Delay_Ms(10);
//    INA226_WriteByte(reg_addr+1, data_low);
    int waiting = 0;

    while (I2C_GetFlagStatus(I2C1, I2C_FLAG_BUSY) != RESET) {
        Delay_Us(10);
        waiting ++;
        if (waiting > 10000){
//            printf("I2C1 BUSY\r\n");
            I2C_GenerateSTOP(I2C1, ENABLE);
            return;
        }
    };
    I2C_GenerateSTART(I2C1, ENABLE);

    while (!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_MODE_SELECT));
    I2C_Send7bitAddress(I2C1, device_addr, I2C_Direction_Transmitter);
//    Delay_Ms(20);
    waiting = 0;
    while (!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED)) {
        Delay_Us(10);
        waiting++;
        if (waiting > 10000) {
//            printf("I2C1 I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED error\r\n");
            I2C_GenerateSTOP(I2C1, ENABLE);
            return;
        }

    }

#if (Address_Lenth == Address_8bit)
    I2C_SendData(I2C1, reg_addr);
//    Delay_Ms(10);
    waiting = 0;
    while (!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_BYTE_TRANSMITTED)) {
        Delay_Us(10);
        waiting++;
        if (waiting > 10000) {
//            printf("I2C1 I2C_EVENT_MASTER_BYTE_TRANSMITTED error\r\n");
            I2C_GenerateSTOP(I2C1, ENABLE);
            return;
        }

    }

#elif (Address_Lenth == Address_16bit)
    I2C_SendData( I2C1, (u8)(reg_addr>>8) );
    while( !I2C_CheckEvent( I2C1, I2C_EVENT_MASTER_BYTE_TRANSMITTED ) );

    I2C_SendData( I2C1, (u8)(reg_addr&0x00FF) );
    while( !I2C_CheckEvent( I2C1, I2C_EVENT_MASTER_BYTE_TRANSMITTED ) );

#endif

    if (I2C_GetFlagStatus(I2C1, I2C_FLAG_TXE) != RESET) {
        I2C_SendData(I2C1, data_high);
//        Delay_Ms(20);
        while (!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_BYTE_TRANSMITTED));
        I2C_SendData(I2C1, data_low);
//        Delay_Ms(20);
//        I2C_SendData(I2C2, data_low);

    }
    waiting = 0;

    while (!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_BYTE_TRANSMITTED)) {
        Delay_Us(10);
        waiting++;
        if (waiting > 10000) {
//            printf("I2C1 I2C_EVENT_MASTER_BYTE_TRANSMITTED error\r\n");
            I2C_GenerateSTOP(I2C1, ENABLE);
            return;
        }
    }
    I2C_GenerateSTOP(I2C1, ENABLE);
    Delay_Ms(5);
}
//
void INA226_Init(void) {
    IIC_Init(100000);
    printf("INA226 INIT begin\r\n");

    INA226_Write2Byte_I2C2(addr1, Config_Reg, 0x4127);//0100_010_100_100_111 //采集16次取平均值更新一次,连续测量分流电压和总线电压
    INA226_Write2Byte_I2C2(addr2, Config_Reg, 0x4127);//0100_010_100_100_111 //采集16次取平均值更新一次,连续测量分流电压和总线电压
    INA226_Write2Byte_I2C1(addr3, Config_Reg, 0x4127);//0100_010_100_100_111 //采集16次取平均值更新一次,连续测量分流电压和总线电压
    INA226_Write2Byte_I2C1(addr4, Config_Reg, 0x4127);//0100_010_100_100_111 //采集16次取平均值更新一次,连续测量分流电压和总线电压
    INA226_Write2Byte_I2C1(addr5, Config_Reg, 0x4127);//0100_010_100_100_111 //采集16次取平均值更新一次,连续测量分流电压和总线电压
    INA226_Write2Byte_I2C2(addr6, Config_Reg, 0x4127);//0100_010_100_100_111 //采集16次取平均值更新一次,连续测量分流电压和总线电压
//    INA226_Write2Byte_I2C2(addr7, Config_Reg, 0x4127);//0100_010_100_100_111 //采集16次取平均值更新一次,连续测量分流电压和总线电压
    INA226_Write2Byte_I2C1(addr8, Config_Reg, 0x4127);//0100_010_100_100_111 //采集16次取平均值更新一次,连续测量分流电压和总线电压
    INA226_Write2Byte_I2C2(addr1, Calib_Reg, calibrate_value);
    INA226_Write2Byte_I2C2(addr2, Calib_Reg, calibrate_value);
    INA226_Write2Byte_I2C1(addr3, Calib_Reg, calibrate_value);
    INA226_Write2Byte_I2C1(addr4, Calib_Reg, calibrate_value);
    INA226_Write2Byte_I2C1(addr5, Calib_Reg, calibrate_value);
    INA226_Write2Byte_I2C2(addr6, Calib_Reg, calibrate_value);
//    INA226_Write2Byte_I2C2(addr7, Calib_Reg, calibrate_value);
    INA226_Write2Byte_I2C1(addr8, Calib_Reg, calibrate_value);

    INA226_Write2Byte_I2C2(addr1, Mask_En_Reg, 0x8001);
    INA226_Write2Byte_I2C2(addr2, Mask_En_Reg, 0x8001);
    INA226_Write2Byte_I2C1(addr3, Mask_En_Reg, 0x8001);
    INA226_Write2Byte_I2C1(addr4, Mask_En_Reg, 0x8001);
    INA226_Write2Byte_I2C1(addr5, Mask_En_Reg, 0x8001);
    INA226_Write2Byte_I2C2(addr6, Mask_En_Reg, 0x8001);
//    INA226_Write2Byte_I2C2(addr7, Mask_En_Reg, 0x8001);
    INA226_Write2Byte_I2C1(addr8, Mask_En_Reg, 0x8001);


    INA226_Write2Byte_I2C2(addr1, Alert_Reg_limit , 0x39d);//960 3
    INA226_Write2Byte_I2C2(addr2, Alert_Reg_limit , 0x3a6);
    INA226_Write2Byte_I2C1(addr3, Alert_Reg_limit , 0x36e);
    INA226_Write2Byte_I2C1(addr4, Alert_Reg_limit , 0x383);
    INA226_Write2Byte_I2C1(addr5, Alert_Reg_limit , 0x384);
    INA226_Write2Byte_I2C2(addr6, Alert_Reg_limit , 0x360);
//    INA226_Write2Byte_I2C2(addr7, Alert_Reg_limit , 0x320);
    INA226_Write2Byte_I2C1(addr8, Alert_Reg_limit , 0x39d);
    uint16_t y;
    INA226_Read2Byte_I2C2(addr1,Mask_En_Reg,&y);
    INA226_Read2Byte_I2C2(addr2,Mask_En_Reg,&y);
    INA226_Read2Byte_I2C1(addr3,Mask_En_Reg,&y);
    INA226_Read2Byte_I2C1(addr4,Mask_En_Reg,&y);
    INA226_Read2Byte_I2C1(addr5,Mask_En_Reg,&y);
    INA226_Read2Byte_I2C2(addr6,Mask_En_Reg,&y);
//    INA226_Read2Byte_I2C2(addr7,Mask_En_Reg,&y);
    INA226_Read2Byte_I2C1(addr8,Mask_En_Reg,&y);

    Delay_Ms(10);
    printf("INA226 INIT end\r\n");
}

void IIC_Init(u32 bound) {
    GPIO_InitTypeDef GPIO_InitStructure = {0};
    I2C_InitTypeDef I2C_InitTStructure = {0};

    RCC_PB2PeriphClockCmd(RCC_PB2Periph_GPIOB, ENABLE);
    RCC_PB1PeriphClockCmd(RCC_PB1Periph_I2C2, ENABLE);
    RCC_PB1PeriphClockCmd(RCC_PB1Periph_I2C1, ENABLE);

    // 测试板，中间SDA
    // PB10  I2C2_SCL  PB11 I2C2_SDA
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10 | GPIO_Pin_6;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_OD;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOB, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11 | GPIO_Pin_7;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_OD;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOB, &GPIO_InitStructure);


    I2C_InitTStructure.I2C_ClockSpeed = bound;
    I2C_InitTStructure.I2C_Mode = I2C_Mode_I2C;
    I2C_InitTStructure.I2C_DutyCycle = I2C_DutyCycle_2;
    I2C_InitTStructure.I2C_OwnAddress1 = 0x00;
    I2C_InitTStructure.I2C_Ack = I2C_Ack_Enable;
    I2C_InitTStructure.I2C_AcknowledgedAddress = I2C_AcknowledgedAddress_7bit;
    I2C_Init(I2C2, &I2C_InitTStructure);
    I2C_Init(I2C1, &I2C_InitTStructure);

    I2C_Cmd(I2C2, ENABLE);
    I2C_Cmd(I2C1, ENABLE);

    I2C_AcknowledgeConfig(I2C2, ENABLE);
    I2C_AcknowledgeConfig(I2C1, ENABLE);
}

