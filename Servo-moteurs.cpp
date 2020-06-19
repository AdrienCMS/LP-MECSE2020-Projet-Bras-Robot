#include "mbed.h"

#define period 20


PwmOut pwm_1(PA_12);

PwmOut pwm_2(PB_0);

PwmOut pwm_3(PB_7);

DigitalOut myled(LED1);

int main() {

    int pulseWidth_1 = 500;
    int pulseWidth_2 = 1000;
    int pulseWidth_3 = 1500;

    pwm_1.period_ms(period);
    pwm_2.period_ms(period);
    pwm_3.period_ms(period);


    while(1) {


            myled = !myled;
            wait_ms(10);

            pwm_1.pulsewidth_us(pulseWidth_1);
            pwm_1.pulsewidth_us(pulseWidth_2);
            pwm_1.pulsewidth_us(pulseWidth_3);

            printf("%d : %d : %d\n\r",pulseWidth_1,pulseWidth_2,pulseWidth_3);

            pulseWidth_1 +=10;
            pulseWidth_2 +=10;
            pulseWidth_3 +=10;

            if(pulseWidth_1>2300)pulseWidth_1 = 500;
            if(pulseWidth_2>2300)pulseWidth_2 = 500;
            if(pulseWidth_3>2300)pulseWidth_3 = 500;


 

    }
}