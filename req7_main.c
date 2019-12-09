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
    

    while(1){
        switch(switch_counter){
            case 0:
               Led_On(LED_0);
               //SwDelay_ms(1000);
               timer0Delay_ms(1000);
               Led_Off(LED_0);
               switch_counter++;
               break;

            case 1:
               Led_On(LED_1);
               //SwDelay_ms(1000);
               timer0Delay_ms(1000);
               Led_Off(LED_1);
               switch_counter++;
               break;

            case 2:
               Led_On(LED_2);
               //SwDelay_ms(1000);
               timer0Delay_ms(1000);
               Led_Off(LED_2);
               switch_counter++;
               break;

            case 3:
                switch_counter = 0;
        }
    }


    return 0;
}
