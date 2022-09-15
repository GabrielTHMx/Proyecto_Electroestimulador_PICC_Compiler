#ifndef IOMAPPING_H
#define IOMAPPING_H

#include "BSP\Led_electro.c"
#include "BSP\Button_electro.c"
#include "BSP\LCD_electro.c"
#include "BSP\Interrupts_electro.c"
#include "BSP\Output_electro.c"

#define LED_CH1            LED_RB6
#define LED_CH2            LED_RB7

#define BUTTON_INCREMENT   BUTTON_RB4
#define BUTTON_START       BUTTON_RB5

#define LCD_OPCION         menu.contador
#define LCD_FRECUENCIA     menu.frecuencia_lcd

#define PULSE_HIGH         interrupt.pulse_h
#define PULSE_LOW          interrupt.pulse_l
#define CONTADOR_          interrupt.contador
#define FREQ               interrupt.contador3
#define TIME               interrupt.contador2
#define FLAG_START         interrupt.bandera_start
#define FLAG_EXTERN        interrupt.bandera_extern

#define OUTPUT_BUZZER      OUTPUT_RC3
#define OUTPUT_CH1         OUTPUT_RC5

#endif IOMAPPING_H
