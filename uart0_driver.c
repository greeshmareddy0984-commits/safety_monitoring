 #include <lpc21xx.h>
 #include"headers.h"
 
 void uart0_init(unsigned int baud)
 {
 unsigned int result=0, pclk;
 if(VPBDIV==0x0)
       pclk=15000000;
 else if (VPBDIV==0x01)
       pclk=60000000;
 else if (VPBDIV==0x02)
       pclk=30000000;
 result=pclk/(16*baud);
 PINSEL0|=0x05;
 //PINSEL0=(PINSEL0&~0x0f)|0x05;
 U0LCR=0x83;
 U0DLL=result&0xff;
 U0DLM=(result>>8)&0xff;
 U0LCR=0x03;
 }
 #define THRE ((U0LSR>>5)&1) 
 void uart0_tx(unsigned char data)
 {
         U0THR=data;
         while(THRE==0);
 }
 #define RDR (U0LSR&1)
 unsigned char uart0_rx()
 {
         while(RDR==0);
         return U0RBR;
 }
 
 void uart0_tx_string(char *ptr)
 {
         while(*ptr!=0)
         {
                 uart0_tx(*ptr);
                 ptr++;
         }
 }
 void uart0_binary(int num)
 {
         int pos, temp;
         for(pos=7;pos>=0;pos--)
         {
                 temp=((num>>pos)&1);
                uart0_tx(temp+48);
         }
 }
 
 
 void uart0_integer(int num)
 {
         int a[10],i=0;
         if(num==0)
         {
                 uart0_tx('0');
                 return;
         }
         if(num<0)
         {
                 num=-num;
                 uart0_tx('-');
        }
         while(num>0)
         {
                 a[i]=num%10+48;
                 num=num/10;
                 i++;
         }
         for(i=i-1;i>=0;i--)
         {
                 uart0_tx(a[i]);
         }
 }
 
 
 void uart0_float(float num)
 {
 
 int a,b;
 if(num==0)
 uart0_tx('0');
 if(num<0)
 {
 num=-num;
 uart0_tx('-');
 }
 a=(int)num;
 b=(num-a)*1000000;
 
 uart0_integer(a);
 uart0_tx('.');
 
 uart0_integer(b);
 }

