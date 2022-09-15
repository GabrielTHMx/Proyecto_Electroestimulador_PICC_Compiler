/***************** APLICACION DE INTERRUPCION DE TIMER 2 EN *******************
********************ELECTROESTIMULADOR USANDO PIC16F877A  ********************/
#ifndef APP_TIMER2_H
#define APP_TIMER2_H

#include "system.c"
#include "App_LCD.c"

typedef struct
{
   int16 FREQUENCY[10];
}FRECUENCIA_t;

int16 Frecuency_Increment(int valor);

/****************** DEFINICION DE INTERRUPCION TIMER 2 ***********************/
#int_timer2
void timer2_isr()
{ 
   CONTADOR_ ++;
   if(CONTADOR_ == 512)       //Cada 10 s aumenta 10 Hz
   {
      FREQ ++;
      LCD_FRECUENCIA += 10;
      /*if(FREQ > 9) 
      {
         FREQ = 0;
      }*/
      
      PULSE_LOW = Frecuency_Increment(FREQ);
      CONTADOR_ = 0;
      TIME ++;    
   }
}

int16 Frecuency_Increment(int valor)
{
   
   FRECUENCIA_t frecuencia = {{13885, 12100, 10711, 8690, 7933, 7933, 7292, 6742, 6266, 6266}};
   
   return frecuencia.frequency[valor];
}
#endif  APP_TIMER2_H
