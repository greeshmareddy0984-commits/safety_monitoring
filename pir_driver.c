
#include <lpc21xx.h>
  #include "headers.h"
  
  #define PIR_PIN     (1 << 30)
  
  
  void pir_init(void)
  {
    	IODIR0 &= ~PIR_PIN;
  }
  
  
  unsigned char pir_read(void)
  {
      if(IOPIN0 & PIR_PIN)
          return 1;
      else
          return 0;
  }
  
