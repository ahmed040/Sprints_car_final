/*
 */


#include "gpio.h"
#include "led.h"
#include "softwareDelay.h"
#include "pushButton.h"
#include "timers.h"
#include "interrupt.h"
#include "MotorDC.h"

int main(void)
{
    // Insert code
    sei();
    soft_pwm_timer_1 = 0;
    MotorDC_Init(MOT_1);
    MotorDC_Init(MOT_2);
    MotorDC_Dir(MOT_1, FORWARD);
    MotorDC_Dir(MOT_2, FORWARD);
    MotorDC_Speed(0);
    En_buttonStatus_t button_tracker;
    Led_Init(LED_0);
    Led_Off(LED_0);
    Led_Init(LED_1);
    Led_Off(LED_1);
    Led_Init(LED_2);
    Led_Off(LED_2);
    pushButton_Init(BTN_0);
    pushButton_Init(BTN_1);
    uint16 push_counter = 0, cycle_counter = 0, long_press_flag = 0, switch_counter = 0, Press_time_counter = 0, number_of_presses = 0, stop_time = 20;
    timer0Init(T0_COMP_MODE, T0_OC0_DIS, T0_PRESCALER_256, 0, 32, (uint8)(T0_POLLING));
    timer1Init(T1_COMP_MODE_OCR1A_TOP, T1_OC0_DIS, T1_PRESCALER_1024, 0, 32, 0, 0, (uint8)(T1_INTERRUPT_CMP_1A | T1_INTERRUPT_CMP_1B));
    while (1){
        MotorDC_Speed(20);
        SwDelay_ms(1000);
        MotorDC_Speed(40);
        SwDelay_ms(1000);
        MotorDC_Speed(60);
        SwDelay_ms(1000);
        MotorDC_Speed(80);
        SwDelay_ms(1000);
        MotorDC_Speed(100);
        SwDelay_ms(1000);
        MotorDC_Speed(80);
        SwDelay_ms(1000);
        MotorDC_Speed(60);
        SwDelay_ms(1000);
        MotorDC_Speed(40);
        SwDelay_ms(1000);
        MotorDC_Speed(20);
        SwDelay_ms(1000);
        MotorDC_Speed(0);
        SwDelay_ms(1000);
        MotorDC_Dir(MOT_1, STOP);
        MotorDC_Dir(MOT_2, STOP);
        SwDelay_ms(2000);
        MotorDC_Speed(20);
        MotorDC_Dir(MOT_1, FORWARD);
        MotorDC_Dir(MOT_2, BACKWARD);
        SwDelay_ms(2000);
        MotorDC_Dir(MOT_1, STOP);
        MotorDC_Dir(MOT_2, STOP);
        break;
    }

    return 0;
}
