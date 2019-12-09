#include "interrupt.h"
#include "timers.h"
ISR(INT0_vect){
}
ISR(INT1_vect){
}
ISR(INT2_vect){
}
ISR(TIMER2_COMP_vect){
    if ((soft_pwm_timer_2 == 1)){
        soft_pwm_timer_2 = 0;
        OCR2 = high_period_timer_2;
        TCCR2 = (TCCR2 & 0xCF) | (uint8)T2_OC2_CLEAR;
    }
    else if((soft_pwm_timer_2 == 0)){
        soft_pwm_timer_2 = 1;
        OCR2 = low_period_timer_2;
        TCCR2 = (TCCR2 & 0xCF) | (uint8)T2_OC2_SET;
    }
}
ISR(TIMER2_OVF_vect){
}
ISR(TIMER1_CAPT_vect){
}
ISR(TIMER1_COMPA_vect){
    if ((soft_pwm_timer_1 == 1)){
        soft_pwm_timer_1 = 0;
        OCR1A = high_period_timer_1;
        OCR1B = high_period_timer_1;
        TCCR1 = (TCCR1 & 0x3FFF) | (uint16)T1_OC1A_CLEAR | (uint16)T1_OC1B_CLEAR;
    }
    else if((soft_pwm_timer_1 == 0)){
        soft_pwm_timer_1 = 1;
        OCR1A = low_period_timer_1;
        OCR1B = low_period_timer_1;
        TCCR1 = (TCCR1 & 0x3FFF) | (uint16)T1_OC1A_SET | (uint16)T1_OC1B_SET;
    }
}
ISR(TIMER1_COMPB_vect){
}
ISR(TIMER1_OVF_vect){
}
ISR(TIMER0_COMP_vect){
    if ((soft_pwm_timer_0 == 1)){
        soft_pwm_timer_0 = 0;
        OCR0 = high_period_timer_0;
        TCCR0 = (TCCR0 & 0xCF) | (uint8)T0_OC0_CLEAR;
    }
    else if((soft_pwm_timer_0 == 0)){
        soft_pwm_timer_0 = 1;
        OCR0 = low_period_timer_0;
        TCCR0 = (TCCR0 & 0xCF) | (uint8)T0_OC0_SET;
    }
}
ISR(TIMER0_OVF_vect){
}
ISR(SPI_STC_vect){
}
ISR(USART_RXC_vect){
}
ISR(USART_UDRE_vect){
}
ISR(USART_TXC_vect){
}
ISR(ADC_vect){
}
ISR(EE_RDY_vect){
}
ISR(ANA_COMP_vect){
}
ISR(TWI_vect){
}
ISR(SPM_RDY_vect){
}
