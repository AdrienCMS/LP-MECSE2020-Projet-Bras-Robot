#include "mbed.h"

AnalogIn Data(A1);

DigitalOut Led(D7);
Serial pc(USBTX, USBRX, 115200);

int main() {
    
    float valeur ;
    float tension ;
    
    
    //int max_valeur      = 300;              // max analog data
    //int min_valeur     = 100;              // min analog data
    //int static_valeur   = 0;                // sttatic analog data 
    
    
    while(1) {
        
        valeur = Data.read();
        valeur = valeur * 3300;
        pc.printf("*\nValeur=%f", valeur);
        
        tension = valeur*(3.6/3300);
        pc.printf("\nTension =%fV", tension);
        
        if(valeur > 2000) {
            Led =1;
            pc.printf("\r MOUVEMENT VERS LE BAS");
            }
        else {
            Led =0;
            pc.printf("\r MOUVEMENT VERS LE HAUT");
            }    
        
        wait (2); 
        
        
        
    }
}
