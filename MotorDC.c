#include "MotorDC.h"



void MotorDC_Init(En_motorType_t MOT_x){
    switch(MOT_x){
        case MOT_1:
            gpioPinDirection(MOTOR_EN_1_GPIO, MOTOR_EN_1_BIT, 0xFF);
            gpioPinDirection(MOTOR_OUT_1A_GPIO, MOTOR_OUT_1A_BIT, 0xFF);
            gpioPinDirection(MOTOR_OUT_1B_GPIO, MOTOR_OUT_1B_BIT, 0xFF);
            break;
        case MOT_2:
            gpioPinDirection(MOTOR_EN_2_GPIO, MOTOR_EN_2_BIT, 0xFF);
            gpioPinDirection(MOTOR_OUT_2A_GPIO, MOTOR_OUT_2A_BIT, 0xFF);
            gpioPinDirection(MOTOR_OUT_2B_GPIO, MOTOR_OUT_2B_BIT, 0xFF);
            break;
    }

}

void MotorDC_Dir(En_motorType_t MOT_x, En_motorDir_t dir){
    uint8 A_Direction = 0x00, B_Direction = 0x00;
    switch(dir){
        case STOP:
           A_Direction = 0x00;
           B_Direction = 0x00;
           break;
        case FORWARD:
           A_Direction = 0xFF;
           B_Direction = 0x00;
           break;
        case BACKWARD:
           A_Direction = 0x00;
           B_Direction = 0xFF;
           break;
    }
    switch(MOT_x){
        case MOT_1:
            gpioPinWrite(MOTOR_OUT_1A_GPIO, MOTOR_OUT_1A_BIT, A_Direction);
            gpioPinWrite(MOTOR_OUT_1B_GPIO, MOTOR_OUT_1B_BIT, B_Direction);
            break;
        case MOT_2:
            gpioPinWrite(MOTOR_OUT_2A_GPIO, MOTOR_OUT_2A_BIT, A_Direction);
            gpioPinWrite(MOTOR_OUT_2B_GPIO, MOTOR_OUT_2B_BIT, B_Direction);
            break;
    }

}

void MotorDC_Speed(uint8 speed){
    timer1SwPWM(speed,200);
}


void MotorDC_Speed_HwPWM(uint8 speed){

}

