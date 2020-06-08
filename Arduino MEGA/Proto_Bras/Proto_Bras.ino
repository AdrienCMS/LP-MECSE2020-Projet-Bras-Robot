/*
* Manipulation des moteurs de la main
* Programme permettant de manipuler les moteurs à courant continu de la main
* Carte Arduino MEGA
*/

//Pin Moteur 1 Pouce
int INT11 = 2; //PWM pouce
int INT21 = 3; //PWM pouce

//Pin Moteur 1 Pouce
int INT12 = 4; //PWM index
int INT22 = 5; //PWM index

//Pin Moteur 1 Pouce
int INT13 = 6; //PWM majeur
int INT23 = 7; //PWM majeur

//Pin Moteur 1 Pouce
int INT14 = 8; //PWM annulaire
int INT24 = 9; //PWM annulaire

//Pin Moteur 1 Pouce
int INT15 = 10; //PWM auriculaire
int INT25 = 11; //PWM auriculaire

//Configuration

void setup()
{
  //On configure les broches en sorties
  //Configuration broches MOT1
  pinMode(INT11,OUTPUT);
  pinMode(INT21,OUTPUT);
  
  //Configuration broches MOT2
  pinMode(INT12,OUTPUT);
  pinMode(INT22,OUTPUT);
  
  //Configuration broches MOT3
  pinMode(INT13,OUTPUT);
  pinMode(INT23,OUTPUT);
  
  //Configuration broches MOT4
  pinMode(INT14,OUTPUT);
  pinMode(INT24,OUTPUT);
  
  //Configuration broches MOT5
  pinMode(INT15,OUTPUT);
  pinMode(INT25,OUTPUT);
}

void loop()
{

  actionMoteur(5,-1,12);
  delay(5000);
  actionMoteur(5,1,255);
  delay(5000);
  actionMoteur(5,-1,250);
  delay(5000);
  actionMoteur(5,1,12);
  delay(5000);
  

}

//Gestion du mouvement des moteurs

void actionMoteur (int moteur, int sens, int pourcentage)
{
  int pin1, pin2, pinS, puissance;

      switch (moteur)
      {
    
      case 1:
    
      pin1 = INT11;
      pinS = INT21;
      break;
      
      case 2:
    
      pin1 = INT12;
      pinS = INT22;
      break;
      
      case 3:
    
      pin1 = INT13;
      pinS = INT23;
      break;
      
      case 4:
    
      pin1 = INT14;
      pinS = INT24;
      break;
      
      case 5:
    
      pin1 = INT15;
      pinS = INT25;
      break;
    }
  
  if (sens == -1)
  {
    pin2 = pin1;
    pin1 = pinS;
    pinS = pin2;
  }
  
  
  pourcentage = 100 - pourcentage;
  
  puissance = map(pourcentage,0,100,0,255);
  analogWrite(pinS,255);
  analogWrite(pin1,puissance);
}
