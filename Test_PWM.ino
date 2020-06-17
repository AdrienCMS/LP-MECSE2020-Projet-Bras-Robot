#include <Wire.h>

#define Add 0x36

const int led1 = 5;
const int led2 = 6;
char ch;
int i = 0;



void PWMled(int led);

void setup () {

  Wire.begin(Add);
  Serial.begin(115200);
  Serial.println("Lancement du programme !!!");
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  Wire.onRequest(requestEvents);
  Wire.onReceive(receiveEvents);
}

void loop (){}

int n = 0;
char cmd;
uint8_t res;

void requestEvents()
{
  Serial.println(F("---> recieved request"));
  Serial.print(F("sending value : "));
  Serial.println(res);
  Wire.write(res);
}

void receiveEvents(int numBytes)
{  
  Serial.println(F("---> recieved events"));
  //for (i = 0; i < 2; i++) {
    n = Wire.read();
    cmd = char(n);
  //}
  
  Serial.println(F("bytes recieved"));
  Serial.print(F("recieved value : "));
  Serial.println(cmd);

  if (cmd == 'O') {
      res = 0x59;
  }
  else if (cmd == 'l') {
    PWMled(5);
    res = 0x4C;
  }
  else if (cmd == 'h') {
    PWMled(6);
    res = 0x48;
  }
}

void PWMled(int led) {

  if (led == 5) {
    for(i=0;i<=255;i++){
      analogWrite(led1, i);
      delay(5);
    }
    for(i=255;i>=0;i--){
      analogWrite(led1, i);
      delay(5);
    }
  }
  else if (led == 6) {
    for(i=0;i<=255;i++){
      analogWrite(led2, i);
      delay(5);
    }
    for(i=255;i>=0;i--){
      analogWrite(led2, i);
      delay(5);
    }
  }
}
