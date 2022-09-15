/***************** APLICACION DE LCD EN ELECTROESTIMULADOR ********************
************************ USANDO PIC16F877A  **********************************/
#ifndef APP_LCD_H
#define APP_LCD_H

#include "system.c"

/****************** DECLARACIÓN DE PROTOTIPOS ********************************/
void LCD_Display(int opcion);

/****************** DEFINICION DE PROTOTIPOS *********************************/
void LCD_Display(int opcion)
{
   switch(opcion)
   {
      case 0:
         lcd_putc("\f OPCION 1\n");
         lcd_putc("FREQ. VARIABLE");
      break;
      
      case 1:
         lcd_putc("\f OPCION 2\n");
         lcd_putc(" FREQ. BURST");
      break;
      
   }
}

#endif  APP_LCD_H
