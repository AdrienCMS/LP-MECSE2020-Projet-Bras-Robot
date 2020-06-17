#include "mbed.h"

#define Arduino_add 0x6C // slave address
 
I2C i2c(D14, D15);
 
DigitalOut myled(LED1);
InterruptIn Bp(USER_BUTTON);
 
Serial pc(SERIAL_TX, SERIAL_RX, 115200);

int ah = 0, i;
int ind = 0; 

char data_write[1];
char data_read[1];

int main()
{ 
    i2c.start();
    //Bp.rise(&Change);
 
    pc.printf("\r\nLancement du programme\r\n");
    
    data_write[0] = 'O';
    //pc.printf("%s", data_write);
    pc.printf("Envoi : %c\r\n", data_write[0]);
    int status = i2c.write(Arduino_add, data_write, 1, 0);
    if (status != 0) { // Error
        while (1) {
            myled = !myled;
            wait(0.2);
            int status = i2c.write(Arduino_add, data_write, 1);
            pc.printf("Erreur...\r\n");
            if (status == 0) {
                break;
            }
        }
    }
    i2c.read(Arduino_add, data_read, 1, 0);
    pc.printf("Recu : %c \r\n", data_read[0]);
    
    
    
    while (1) {
        // Read temperature register*
       if (ah == 0) {
            pc.printf("\r\nBoucle infinie !!\r\n");
            ah++;
        }
        
        data_write[0] = 'l';
        pc.printf("Envoi : %c\r\n", data_write[0]);
        i2c.write(Arduino_add, data_write, 1, 1); // no stop
        i2c.read(Arduino_add, data_read, 1, 0);
        pc.printf("Recu : %c \r\n", data_read[0]);
        memset(data_read, 0, 0);
        wait(10);
        
        data_write[0] = 'h';
        pc.printf("Envoi : %c\r\n", data_write[0]);
        i2c.write(Arduino_add, data_write, 1, 1); // no stop
        i2c.read(Arduino_add, data_read, 1, 0);
        pc.printf("Recu : %c \r\n", data_read[0]);
        memset(data_read, 0, 0);
        wait(10);        
    }
}

/*
void Change(void) {
    switch(ind) {
        
    case 0:
        data_write[0] = 'l';
        pc.printf("Envoi : %c\r\n", data_write[0]);
        i2c.write(Arduino_add, data_write, 1, 1); // no stop
        i2c.read(Arduino_add, data_read, 1, 0);
        pc.printf("Recu : %c \r\n", data_read[0]);
        memset(data_read, 0, 0);
        wait(3);
        ind++;
        break;
        
    case 1:
        data_write[0] = 'h';
        pc.printf("Envoi : %c\r\n", data_write[0]);
        i2c.write(Arduino_add, data_write, 1, 1); // no stop
        i2c.read(Arduino_add, data_read, 1, 0);
        pc.printf("Recu : %c \r\n", data_read[0]);
        memset(data_read, 0, 0);
        wait(3);
        ind--;
        break;
    
    default :
        break;
    }
}
 */
