/* 
   Fonctions gérant le mouvement de la crémaillere 
   Auteurs : Jeremy et Aurélien
   Derniere modif : 22/07/2012
*/

#include "motor.h"
#include "AFMotor.h"
#include <Arduino.h>

AF_DCMotor moteur (PIN_CREMAILLERE);

// Avance la crémaillere
void avancerCremaillere()
{
    moteur.run(FORWARD);
}

// rentre la crémaillere
void reculerCremaillere()
{
    moteur.run(BACKWARD);
}

//arrête le moteur
void Stop()
{
  moteur.run(RELEASE);
}
// a ajouter a l'initialisation
void initialisation()
{
    moteur.setSpeed(SPEED);
    pinMode(A0, INPUT);
    digitalWrite(A0, HIGH);
    pinMode(A5, INPUT);
    digitalWrite(A5, HIGH);// pull up sur pin 2
}

bool paf()
{
  static  int etat = 0;
  switch(etat)
  {
    case 0:
    avancerCremaillere();
    etat=1;
    break;
    
    case 1:
    if(digitalRead(A0)==LOW)
    {
      etat=2;
    }
    break;
    
    case 2:
    reculerCremaillere();
    etat=3;
    break;
    
    case 3:
    etat = 4;
    break;
    
    case 4:
    if(digitalRead(A5)==LOW)
    { 
      etat=0;
      Stop();
      return true;
    }
    break;
    
   
  }
  return false;
}
