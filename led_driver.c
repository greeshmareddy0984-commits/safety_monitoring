
#include <lpc21xx.h>
   
  #include "headers.h"
  
  #define LED_GREEN    (1 << 17)
  #define LED_YELLOW   (1 << 18)
  #define LED_RED      (1 << 19)
  
  
  void led_init(void)
  {
      IODIR0 |= (LED_GREEN | LED_YELLOW | LED_RED);
          IOCLR0 = (LED_GREEN | LED_YELLOW | LED_RED);
  }
  void led_off(void)
  {
      IOCLR0 = (LED_GREEN | LED_YELLOW | LED_RED);
  }
  void led_green(void)
  {
      led_off();
      IOSET0 = LED_GREEN;
  }
  void led_yellow(void)
  {
      led_off();
      IOSET0 = LED_YELLOW;
  }
  void led_red(void)
 {
      led_off();
  
      IOSET0 = LED_RED;
  }
  
  
  void led_update(unsigned char worker, unsigned char fire)
  {
      if(fire)
     {
          led_red();
      }
      else if(worker)
      {
          led_yellow();
     }
     else
      {
         led_green();
     }
 }
  

