#ifndef  APP_INT_EXT_H
#define  APP_INT_EXT_H

#include "system.c"

#int_ext
void ext_isr()
{
   delay_ms(20);
   FLAG_EXTERN ++;
   
   if(FLAG_EXTERN == 1) 
   {
      Led_On_(LED_CH2);
   }
   
   if(FLAG_EXTERN > 1) 
   {
      FLAG_EXTERN = 0;
      Led_Off_(LED_CH2);
      lcd_putc("\f    FRECUENCIA :\n");
      setup_timer_2(T2_DIV_BY_4, 250, 10);         //10,000 us = 10 ms 
   }
}
#endif   APP_INT_EXT_H
