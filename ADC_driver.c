#include <lpc21xx.h>
  #include"headers.h"
  #define DONE ((ADDR >> 31) & 1)
  
	void adc_init(void)
   {
       PINSEL1 = 0x1540000;
       ADCR   = 0x00200400;
   }
	 
  
	 unsigned int adc_read(unsigned int ch_num)
  {
      unsigned int result = 0;
      ADCR |= (1 << ch_num);
      ADCR |= (1 << 24);
      while (DONE == 0);
      ADCR ^= (1 << 24);
            ADCR ^= (1 << ch_num);
      result = (ADDR >> 6) & 0x3FF;
      return result;
  }
	
	
	