#include "gpio.h"

void gpioPortDirection(uint8 port, uint8 direction){
    switch(port){
        case GPIOA:
            PORTA_DIR = direction;
            break;
        case GPIOB:
            PORTB_DIR = direction;
            break;
        case GPIOC:
            PORTC_DIR = direction;
            break;
        case GPIOD:
            PORTD_DIR = direction;
            break;
    }
}
void gpioPortWrite(uint8 port, uint8 value){
    switch(port){
        case GPIOA:
            PORTA_DATA = value;
            break;
        case GPIOB:
            PORTB_DATA = value;
            break;
        case GPIOC:
            PORTC_DATA = value;
            break;
        case GPIOD:
            PORTD_DATA = value;
            break;
    }
}
void gpioPortToggle(uint8 port){
    switch(port){
        case GPIOA:
            PORTA_DATA = ~PORTA_DATA;
            break;
        case GPIOB:
            PORTB_DATA = ~PORTB_DATA;
            break;
        case GPIOC:
            PORTC_DATA = ~PORTC_DATA;
            break;
        case GPIOD:
            PORTD_DATA = ~PORTD_DATA;
            break;
    }
}
uint8 gpioPortRead(uint8 port){
    uint8 reading = 0;
    switch(port){
        case GPIOA:
            reading = PORTA_PIN;
            break;
        case GPIOB:
            reading = PORTB_PIN;
            break;
        case GPIOC:
            reading = PORTC_PIN;
            break;
        case GPIOD:
            reading = PORTD_PIN;
            break;
    }
    return reading;
}

void gpioPinDirection(uint8 port, uint8 pins, uint8 direction){
    switch(port){
        case GPIOA:
            if (direction){
                PORTA_DIR = PORTA_DIR | pins;
            }
            else{
                PORTA_DIR = PORTA_DIR & (~pins);
            }
            break;
        case GPIOB:
            if (direction){
                PORTB_DIR = PORTB_DIR | pins;
            }
            else{
                PORTB_DIR = PORTB_DIR & (~pins);
            }
            break;
        case GPIOC:
            if (direction){
                PORTC_DIR = PORTC_DIR | pins;
            }
            else{
                PORTC_DIR = PORTC_DIR & (~pins);
            }
            break;
        case GPIOD:
            if (direction){
                PORTD_DIR = PORTD_DIR | pins;
            }
            else{
                PORTD_DIR = PORTD_DIR & (~pins);
            }
            break;
    }
}
void gpioPinWrite(uint8 port, uint8 pins, uint8 value){
    switch(port){
        case GPIOA:
            if (value){
                PORTA_DATA = PORTA_DATA | pins;
            }
            else{
                PORTA_DATA = PORTA_DATA & (~pins);
            }
            break;
        case GPIOB:
            if (value){
                PORTB_DATA = PORTB_DATA | pins;
            }
            else{
                PORTB_DATA = PORTB_DATA & (~pins);
            }
            break;
        case GPIOC:
            if (value){
                PORTC_DATA = PORTC_DATA | pins;
            }
            else{
                PORTC_DATA = PORTC_DATA & (~pins);
            }
            break;
        case GPIOD:
            if (value){
                PORTD_DATA = PORTD_DATA | pins;
            }
            else{
                PORTD_DATA = PORTD_DATA & (~pins);
            }
            break;
    }
}

void gpioPinToggle(uint8 port, uint8 pins){
    switch(port){
        case GPIOA:
            PORTA_DATA = PORTA_DATA ^ pins;
            break;
        case GPIOB:
            PORTB_DATA = PORTB_DATA ^ pins;
            break;
        case GPIOC:
            PORTC_DATA = PORTC_DATA ^ pins;
            break;
        case GPIOD:
            PORTD_DATA = PORTD_DATA ^ pins;
            break;
    }
}

uint8 gpioPinRead(uint8 port, uint8 pin){
    uint8 reading = 0;
    switch(port){
        case GPIOA:
            reading = PORTA_PIN;
            break;
        case GPIOB:
            reading = PORTB_PIN;
            break;
        case GPIOC:
            reading = PORTC_PIN;
            break;
        case GPIOD:
            reading = PORTD_PIN;
            break;
    }
    return (reading & pin);
}

void gpioUpperNibbleDirection(uint8 port, uint8 direction){
    uint8 iterator_bit = 0x10;
    uint8 i = 0;
    for (i = 0; i < 4; i++){
        gpioPinDirection(port, iterator_bit, direction);
        iterator_bit = iterator_bit << 1;
    }
}
void gpioUpperNibbleWrite(uint8 port, uint8 value){
    uint8 iterator_bit = 0x10;
    uint8 i = 0;
    for (i = 0; i < 4; i++){
        gpioPinWrite(port, iterator_bit, value);
        iterator_bit = iterator_bit << 1;
    }
}

void gpioUpperNibbleToggle(uint8 port){
    uint8 iterator_bit = 0x10;
    uint8 i = 0;
    for (i = 0; i < 4; i++){
        gpioPinToggle(port, iterator_bit);
        iterator_bit = iterator_bit << 1;
    }
}

uint8 gpioUpperNibbleRead(uint8 port){
    uint8 reading = 0;
    switch(port){
        case GPIOA:
            reading = PORTA_PIN;
            break;
        case GPIOB:
            reading = PORTB_PIN;
            break;
        case GPIOC:
            reading = PORTC_PIN;
            break;
        case GPIOD:
            reading = PORTD_PIN;
            break;
    }
    return (reading & (0xF0));
}

void gpioLowerNibbleDirection(uint8 port, uint8 direction){
    uint8 iterator_bit = 0x01;
    uint8 i = 0;
    for (i = 0; i < 4; i++){
        gpioPinDirection(port, iterator_bit, direction);
        iterator_bit = iterator_bit << 1;
    }
}
void gpioLowerNibbleWrite(uint8 port, uint8 value){
    uint8 iterator_bit = 0x01;
    uint8 i = 0;
    for (i = 0; i < 4; i++){
        gpioPinWrite(port, iterator_bit, value);
        iterator_bit = iterator_bit << 1;
    }
}

void gpioLowerNibbleToggle(uint8 port){
    uint8 iterator_bit = 0x01;
    uint8 i = 0;
    for (i = 0; i < 4; i++){
        gpioPinToggle(port, iterator_bit);
        iterator_bit = iterator_bit << 1;
    }
}

uint8 gpioLowerNibbleRead(uint8 port){
    uint8 reading = 0;
    switch(port){
        case GPIOA:
            reading = PORTA_PIN;
            break;
        case GPIOB:
            reading = PORTB_PIN;
            break;
        case GPIOC:
            reading = PORTC_PIN;
            break;
        case GPIOD:
            reading = PORTD_PIN;
            break;
    }
    return (reading & (0x0F));
}
