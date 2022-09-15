/*********************** APLICACION PRINCIPAL EN ******************************
******************** ELECTROESTIMULADOR USANDO PIC16F877A  *******************/
#ifndef  APP_MAIN_H
#define  APP_MAIN_H

#include "system.c"
#include "App_Electroestimulador.c"
#include "App_Int_rb.c"
#include "App_Timer2.c"
#include "App_Efectos.c"
#include "App_Int_Ext.c"

typedef struct
{
   int bandera_estado;
}MAIN_t;
/********************** DECLARACION DE PROTOTIPO *****************************/

void App_main(void);

/********************** DEFINICION DE PROTOTIPO ******************************/
void App_main(void)
{
     while(FLAG_START == 1)
     {
         MAIN_t main; 
         delay_ms(20);

         App_Efectos(START_SESION);                          //Efecto de Iniciando sesion + cuenta regresiva

         While(TIME < 6)                                    //TIEMPO DE 60 s
         {
            App_Efectos(CURRENT_SESION);
            App_Electro(LCD_OPCION, PULSE_HIGH, PULSE_LOW);
            main.bandera_estado = 0;
            
            while(FLAG_EXTERN == 1)
            { 
               if(main.bandera_estado == 0) 
               {
                  App_Efectos(PAUSE_SESION);
                  main.bandera_estado = 1;
               }
               setup_timer_2(T2_DISABLED, 250, 10);                //TIMER 2 deshabilitado
               //SYSTEM_Initialize(SYSTEM_INTERRUPTS);
            }
         }
         
         App_Efectos(END_SESION);                           //Efecto de fin de sesion       
     }
}
#endif  APP_MAIN_H
