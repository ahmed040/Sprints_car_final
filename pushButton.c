#include "pushButton.h"
static uint8 Button_read[4] = {0, 0, 0, 0};
static En_buttonStatus_t EN_Button_read[4] = {Released, Released, Released, Released};
void read_button(void);
void pushButton_Init(En_buttonId btn_id){
    switch (btn_id){
        case BTN_0:
            gpioPinDirection((uint8)BTN_0_GPIO, (uint8)BTN_0_BIT, 0x00);
            break;
        case BTN_1:
            gpioPinDirection((uint8)BTN_1_GPIO, (uint8)BTN_1_BIT, 0x00);
            break;
        case BTN_2:
            gpioPinDirection((uint8)BTN_2_GPIO, (uint8)BTN_2_BIT, 0x00);
            break;
        case BTN_3:
            gpioPinDirection((uint8)BTN_3_GPIO, (uint8)BTN_3_BIT, 0x00);
            break;
    }
}
void read_button(void){
    uint8 i = 0;
    for (i = 0; i < 4; i++){
        switch ((En_buttonId)(i)){
            case BTN_0:
                Button_read[i] = gpioPinRead((uint8)BTN_0_GPIO, (uint8)BTN_0_BIT);
                break;
            case BTN_1:
                Button_read[i] = gpioPinRead((uint8)BTN_1_GPIO, (uint8)BTN_1_BIT);
                break;
            case BTN_2:
                Button_read[i] = gpioPinRead((uint8)BTN_2_GPIO, (uint8)BTN_2_BIT);
                break;
            case BTN_3:
                Button_read[i] = gpioPinRead((uint8)BTN_3_GPIO, (uint8)BTN_3_BIT);
                break;
        }
    }
}

void pushButton_Update(void){
    uint8 reading1[4] = {0, 0, 0, 0};
    uint8 reading2[4] = {0, 0, 0, 0};
    uint8 i = 0;
    read_button();
    for (i = 0; i < 4; i++){
        reading1[i] = Button_read[i];
    }
    SwDelay_ms(50);
    read_button();
    for (i = 0; i < 4; i++){
        reading2[i] = Button_read[i];
    }
    for (i = 0; i < 4; i++){
        if (reading1[i]){
            if (reading2[i]){
                EN_Button_read[i] = Pressed;
            }
            else{
                EN_Button_read[i] = Prereleased;
            }
        }
        else{
            if (reading2[i]){
                EN_Button_read[i] = Prepressed;
            }
            else{
                EN_Button_read[i] = Released;
            }
        }
    }
}

En_buttonStatus_t pushButton_GetStatus(En_buttonId btn_id){
    return EN_Button_read[(uint8)(btn_id)];
}

