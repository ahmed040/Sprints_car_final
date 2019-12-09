#include "softwareDelay.h"
void SwDelay_ms(uint32 n){
    uint32 iterator_delay = 0x00000000;
    uint32 iterator_delay2 = 75;
    uint32 iterator_delay3 = 1;
    uint32 iterator_delay4 = 0;
    uint32 iterator_delay5 = 0;
    for (iterator_delay = 0; iterator_delay < n; iterator_delay++){
        for(iterator_delay4 = 0; iterator_delay4 < iterator_delay2; iterator_delay4++){
            for(iterator_delay5 = 0; iterator_delay5 < iterator_delay3; ){
                iterator_delay5++;
            }
        }
    }

}
