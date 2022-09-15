/***************** APLICACION DE INTERRUPCION DE RB EN ************************
********************ELECTROESTIMULADOR USANDO PIC16F877A  ********************/
#ifndef APP_INT_RB_H
#define APP_INT_RB_H

#include "system.c"
#include "App_LCD.c"
#include "App_Timer2.c"

/****************** DEFINICION DE INTERRUPCION RB ****************************/
#int_rb
void rb_isr()
{
   delay_ms(20);
   if(Button_Is_Pressed(BUTTON_INCREMENT) == true)    //SELECCION DE OPCION
      {
         LCD_OPCION ++;
         
         if(LCD_OPCION > 1) LCD_OPCION = 0;
         LCD_Display(LCD_OPCION);
         
      }
    if(Button_Is_Pressed(BUTTON_START) == true)       //BOTON DE COMIENZO
      {
         FLAG_START = 1;                              //Bandera de comienzo activada
      }
}

#endif  APP_INT_RB_H
