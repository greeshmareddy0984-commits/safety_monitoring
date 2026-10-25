#include <lpc21xx.h>
   #include"headers.h"
  
  float temperature_read(void)
   {
   
   unsigned int adc_value;
  float temp;
  
  adc_value = adc_read(1); 
  temp =(adc_value * 3.3 / 1023.0) * 100.0;
  return temp;
  }
  
  
  
  int main(void)
  {
      float temperature;
      
      
      unsigned char worker;
      unsigned char fire;
  
      char *status;
      
  
      lcd_init();
 
      uart0_init(9600);
 
      adc_init();
 
      pir_init();
  
     flame_init();
 
     led_init();
  
      lcd_string("Safety Monitor");
  
      delay_ms(500);
      
      lcd_cmd(0x01);
      while(1)
      {
          temperature = temperature_read();
  
          worker = pir_read();
  
          fire = flame_read();
  
  
         if(fire)
          {   
              status = "ALERT";
         }
          else if(temperature > 40.0)
          {   
              status = "HOT";
          }
         else
          {   
              status = "SAFE";
          }
  
  
  
          lcd_cmd(0x80);
  
          lcd_float(temperature);
  
          lcd_cmd(0xc0);
  
          lcd_string("STATUS:");
  
          lcd_string(status);
          led_update(worker, fire);
 
          uart0_tx_string("temperature      : ");
          uart0_float(temperature);  
          uart0_tx_string("\r\nWorker      : ");
          if(worker)
              uart0_tx_string("YES\r\n");
          else
              uart0_tx_string("NO\r\n");
  
 
         uart0_tx_string("Fire        : ");
 
          if(fire)
              uart0_tx_string("YES\r\n");
          else
              uart0_tx_string("NO\r\n");
  
 
         uart0_tx_string("Status      : ");
 
         uart0_tx_string(status);
 
         uart0_tx_string("\r\n\r\n");
   
         delay_ms(1000);
 
     
     
     }
 }
 




 