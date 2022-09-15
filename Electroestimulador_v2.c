#include <16f877a.h>
#fuses xt, nowdt                        //Uso de crystal externo
#use delay(clock = 4M)

#include "system.c"
#include "App_main.c"

void main()
{
   SYSTEM_Initialize(SYSTEM_ENABLE);
   
   while(1)
   {
     App_main();
   }
}
