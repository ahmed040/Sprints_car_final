/*
 */


#include "gpio.h"
#include "led.h"
#include "softwareDelay.h"
#include "pushButton.h"
#include "timers.h"


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
    

    while (1){
        pushButton_Update();
        button_tracker = pushButton_GetStatus(BTN_0);
        cycle_counter++;
        if (button_tracker == Pressed){
            Press_time_counter++;
            if (Press_time_counter > 20){
                long_press_flag = 1;
            }
            else {
                long_press_flag = 0;
            }
            if ((cycle_counter - push_counter < 20) && (cycle_counter - push_counter > 3)){
                stop_time = 40;
            }
            else {
            Led_On(LED_2);
            push_counter = cycle_counter;
            stop_time = 20;

            }
        }
        else {
            Press_time_counter = 0;
            if ((cycle_counter - push_counter) > stop_time){
                if (long_press_flag == 0){
                    Led_Off(LED_2);
                }
            }

        }
        if (cycle_counter > 100000){
            if (cycle_counter > push_counter){
                cycle_counter = 50 +  cycle_counter - push_counter;
                push_counter = 50;
            }
            else{
                push_counter = 50 + push_counter - cycle_counter;
                cycle_counter = 50;
            }
        }
    }

    return 0;
}
