//Code reads and stores word in second variable so the original can be erased. 
#include <18F4550.h>
#fuses INTRC, NOPROTECT, NOWDT, NOLVP, CPUDIV1, PLL1        
#use delay (clock = 8M)

#use rs232(rcv=pin_C7, xmit=pin_C6, baud=9600, bits=8, parity=n, stream = BTH)
#use rs232(rcv=pin_B5, xmit=pin_B4, baud=9600, bits=8, parity=n, stream = TTL)

#BYTE TRISD = 0xF95
#BYTE PORTD = 0xF83

int8 i=0, j = 0,k=0;
char letter;
char word[100];
char wordreal[100];
int counter  = 0;
int counterLoop = 0;

void limpiar_palabra();

void main()
{
   fprintf(TTL, "READY TO GO\r\n");
   //letter = fgetc(BTH);
   limpiar_palabra();
   while(True)
   {
      
      for(i=0;i<8;i++)
      {
         letter = fgetc(BTH);
         delay_us(10);
         output_high(pin_a1);
         if(letter == '.')
            //counterLoop = i;
            goto Imprimir;
         word[i] = letter;
         //counter++;
      }
      
      Imprimir:
      delay_us(50);
      for(int y=0;y<8;y++)
      {
         wordreal[y] = word[y];
      }
      
      fprintf(TTL, "La palabra es: \r\n");
      for(j=0;j<8;j++)
      {
         fprintf(TTL, "%c", wordreal[j]);
      }
      
    delay_ms(1500);
    output_low(pin_a1);
    limpiar_palabra();
    fprintf(TTL, "Palabra vieja: \r\n");
    for(int u=0;u<8;u++)
      {
         fprintf(TTL, "%c", word[u]);
      }
}
   
   }
   
   
void limpiar_palabra()
{
   for(k=0;k<8;k++)
      {
         word[k] = 0;
      }
}
