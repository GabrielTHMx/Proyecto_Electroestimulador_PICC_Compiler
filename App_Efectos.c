#ifndef  APP_EFECTOS_H
#define  APP_EFECTOS_H

#include "system.c"
#include "App_LCD.c"

typedef enum
{
   START_SESION,
   END_SESION,
   PAUSE_SESION,
   CURRENT_SESION
}EFECTOS_t;

void App_Efectos(EFECTOS_t opcion);

void App_Efectos(EFECTOS_t opcion)
{
   switch(opcion)
   {
      case START_SESION:
         disable_interrupts(int_rb);                         //Desabilita uso de boton de cambio de opcion
         
         PULSE_HIGH = 400;                                   //T_ON = 400 us
         PULSE_LOW = 13885;
         LCD_FRECUENCIA = 60;
         FREQ = 0;
         
         lcd_putc("\f INICIANDO SESION :\n");
         for(int i = 3; i > 0; i --)
         {
            lcd_gotoxy(8,2);
            printf(lcd_putc,"%d", i);
            delay_ms(999);
         } 
         
         delay_ms(20);
         
         Output_On(OUTPUT_BUZZER);
         delay_ms(1000);
         Output_Off(OUTPUT_BUZZER);
  
         Led_On_(LED_CH1);                            //Enciende LED indicador de CH1
         setup_timer_2(T2_DIV_BY_4, 250, 10);         //10,000 us = 10 ms   
         
         lcd_putc("\f    FRECUENCIA :");

      break;
      
      case END_SESION:
      
         lcd_putc("\f FIN DE SESION :\n");
         lcd_gotoxy(8,2);
         lcd_putc("=)");
         delay_ms(1500);
         lcd_putc("\f SALIENDO");
         
         for(int i = 10; i <= 14; i ++)
         {
            lcd_gotoxy(i,1);
            lcd_putc(".");
            delay_ms(500);
         } 
         
         setup_timer_2(T2_DISABLED, 250, 10);                //TIMER 2 deshabilitado   
         Led_Off_(LED_CH1);                                  //LED CH1 apagado = FIN DE SESION             
         TIME = 0;                                           //Tiempo = 0
         LCD_FRECUENCIA = 60;
         FREQ = 0;
         enable_interrupts(int_rb);                          //Habilitacion de uso de boton de cambio de opcion
         FLAG_START = 0;                                     //BANDERA = 0 que Sale de ciclo while
         LCD_Display(LCD_OPCION);
      break;
      
      case PAUSE_SESION:
         
         lcd_putc("\f  SESION EN\n");
         lcd_putc("   PAUSA....");
      break;
      
      case CURRENT_SESION:
         
         lcd_gotoxy(8,2);
         printf(lcd_putc, "    %d", LCD_FRECUENCIA );
         
      break;
   }
}

#endif   APP_EFECTOS_H
