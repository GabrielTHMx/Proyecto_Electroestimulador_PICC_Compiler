/************* CONFIGURACION DE SISTEMA EN ELECTROESTIMULADOR *****************
************************ USANDO PIC16F877A  **********************************/
#ifndef SYSTEM_H
#define SYSTEM_H

#include "IOMapping.c"

typedef enum
{
   SYSTEM_ENABLE,
   SYSTEM_INTERRUPTS
}SYSTEM_STATE;

/****************** DECLARACIÓN DE PROTOTIPOS ********************************/
void SYSTEM_Initialize(SYSTEM_STATE state);

/****************** DEFINICION DE PROTOTIPOS *********************************/
void SYSTEM_Initialize(SYSTEM_STATE state)
{
   switch(state)
   {
      case SYSTEM_ENABLE:
         
         LCD_Enable();
         Led_Enable(LED_CH1);
         Led_Enable(LED_CH2);
         Button_Enable();
         Interrupts_Enable();
         Output_Enable(OUTPUT_RC5);
         Output_Enable(OUTPUT_RC3);
      break;
      
      case SYSTEM_INTERRUPTS:
         
      break;
   }
}
#endif SYSTEM_H
