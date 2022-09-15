/******************** APLICACION DE ELECTROESTIMULADOR ************************
************************ USANDO PIC16F877A  **********************************/
#ifndef APP_ELECTROESTIMULADOR_H
#define APP_ELECTROESTIMULADOR_H

#include "system.c"

/****************** DECLARACIÓN DE PROTOTIPOS ********************************/
void App_Electro(int opcion, int16 HIGH, int16 LOW);

/****************** DEFINICION DE PROTOTIPOS *********************************/
void App_Electro(int opcion, int16 HIGH, int16 LOW)
{
   switch(opcion)
   {
      case 0:
         
               Output_On(OUTPUT_CH1);  
               delay_us(HIGH);                           //400 us
               Output_Off(OUTPUT_CH1);
               delay_us(LOW);
      break;
      
      case 1:
      break;
   }   
}

#endif  APP_ELECTROESTIMULADOR_H
