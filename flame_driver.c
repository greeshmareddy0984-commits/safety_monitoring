 #include"headers.h"
 #define FLAME_PIN   (1 << 5)
 
 
 void flame_init(void)
 {
      IODIR0 &= ~FLAME_PIN;
 }

 
 unsigned char flame_read(void)
 {
     if(IOPIN0 & FLAME_PIN)
         return 0;
     else
         return 1;
 }
 

 
 
