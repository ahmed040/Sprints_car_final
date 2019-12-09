#include "led.h"
void Led_Init(En_LedNumber_t led_id){
    switch (led_id){
        case LED_0:
            gpioPinDirection((uint8)LED_0_GPIO, (uint8)LED_0_BIT, 0xFF);
            break;
        case LED_1:
            gpioPinDirection((uint8)LED_1_GPIO, (uint8)LED_1_BIT, 0xFF);
            break;
        case LED_2:
            gpioPinDirection((uint8)LED_2_GPIO, (uint8)LED_2_BIT, 0xFF);
            break;
        case LED_3:
            gpioPinDirection((uint8)LED_3_GPIO, (uint8)LED_3_BIT, 0xFF);
            break;
    }
}
void Led_On(En_LedNumber_t led_id){
    switch (led_id){
        case LED_0:
            gpioPinWrite((uint8)LED_0_GPIO, (uint8)LED_0_BIT, 0xFF);
            break;
        case LED_1:
            gpioPinWrite((uint8)LED_1_GPIO, (uint8)LED_1_BIT, 0xFF);
            break;
        case LED_2:
            gpioPinWrite((uint8)LED_2_GPIO, (uint8)LED_2_BIT, 0xFF);
            break;
        case LED_3:
            gpioPinWrite((uint8)LED_3_GPIO, (uint8)LED_3_BIT, 0xFF);
            break;
    }
}
void Led_Off(En_LedNumber_t led_id){
    switch (led_id){
        case LED_0:
            gpioPinWrite((uint8)LED_0_GPIO, (uint8)LED_0_BIT, 0x00);
            break;
        case LED_1:
            gpioPinWrite((uint8)LED_1_GPIO, (uint8)LED_1_BIT, 0x00);
            break;
        case LED_2:
            gpioPinWrite((uint8)LED_2_GPIO, (uint8)LED_2_BIT, 0x00);
            break;
        case LED_3:
            gpioPinWrite((uint8)LED_3_GPIO, (uint8)LED_3_BIT, 0x00);
            break;
    }
}
void Led_Toggle(En_LedNumber_t led_id){
    switch (led_id){
        case LED_0:
            gpioPinToggle((uint8)LED_0_GPIO, (uint8)LED_0_BIT);
            break;
        case LED_1:
            gpioPinToggle((uint8)LED_1_GPIO, (uint8)LED_1_BIT);
            break;
        case LED_2:
            gpioPinToggle((uint8)LED_2_GPIO, (uint8)LED_2_BIT);
            break;
        case LED_3:
            gpioPinToggle((uint8)LED_3_GPIO, (uint8)LED_3_BIT);
            break;
    }
}
