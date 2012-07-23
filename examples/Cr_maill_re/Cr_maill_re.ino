
/* 
   Code d'exemple pour le moteur couran continu de la crémaillere
   Auteurs : Jeremy et Aurélien
   Derniere modif : 23/07/2012 par Jérémy
*/

#include "AFMotor.h"
#include "motor.h"

void setup() 
{                
  initialisation();
}

// the loop routine runs over and over again forever:
void loop() 
{
  if(paf()==true)
  {  
     while(1);
  }
}
