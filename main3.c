//Trying out the khbit() condition to store the word while the motor is turning
#Include <18F4550.h>
#Fuses INTRC,NOPROTECT, NOWDT, CPUDIV1, PLL1
#Use Delay(Clock=8M)
#Include <string.h>
#Use RS232(RCV=PIN_C7, XMIT=PIN_C6, Baud=9600, Bits=8, Stream = BTH)
#Use RS232(RCV=PIN_B5, XMIT=PIN_B4, Baud=9600, Bits=8, Stream = TTL)

//Registros del puerto D.
#BYTE TRISD = 0xF95
#BYTE PORTD = 0xF83

//Declaracion de los vectores de cada letra.
Int Letra_A[7]={0B00111111, 0B01001000, 0B10001000, 0B01001000, 0B00111111, 0B00000000, 0B00000000};
Int Letra_B[7]={0B11111111, 0B10010001, 0B10010001, 0B10101001, 0B01000110, 0B00000000, 0B00000000};
Int Letra_C[7]={0B11111111, 0B10000001, 0B10000001, 0B10000001, 0B11000011, 0B00000000, 0B00000000};
Int Letra_D[7]={0B11111111, 0B10000001, 0B10000001, 0B01000010, 0B00111100, 0B00000000, 0B00000000};
Int Letra_E[7]={0B11111111, 0B10010001, 0B10010001, 0B10010001, 0B10000001, 0B00000000, 0B00000000};
Int Letra_F[7]={0B11111111, 0B10010000, 0B10010000, 0B10000000, 0B10000000, 0B00000000, 0B00000000};
Int Letra_G[7]={0B11111111, 0B10010001, 0B10010001, 0B10010001, 0B10011111, 0B00000000, 0B00000000};
Int Letra_H[7]={0B11111111, 0B00010000, 0B00010000, 0B00010000, 0B11111111, 0B00000000, 0B00000000};
Int Letra_I[7]={0B10000001, 0B10000001, 0B11111111, 0B10000001, 0B10000001, 0B00000000, 0B00000000};
Int Letra_J[7]={0B10000111, 0B10000001, 0B10000001, 0B10000001, 0B11111111, 0B00000000, 0B00000000};
Int Letra_K[7]={0B11111111, 0B00010000, 0B00101000, 0B01000100, 0B10000011, 0B00000000, 0B00000000};
Int Letra_L[7]={0B11111111, 0B00000001, 0B00000001, 0B00000001, 0B00000001, 0B00000000, 0B00000000};
Int Letra_M[7]={0B11111111, 0B01000000, 0B00100000, 0B01000000, 0B11111111, 0B00000000, 0B00000000};
Int Letra_N[7]={0B11111111, 0B00110000, 0B00011000, 0B00001100, 0B11111111, 0B00000000, 0B00000000};
Int Letra_O[7]={0B01111110, 0B10000001, 0B10000001, 0B10000001, 0B01111110, 0B00000000, 0B00000000};
Int Letra_P[7]={0B11111111, 0B10001000, 0B10001000, 0B10001000, 0B01110000, 0B00000000, 0B00000000};
Int Letra_Q[7]={0B01111110, 0B10001001, 0B10000101, 0B10000011, 0B01111110, 0B00000000, 0B00000000};
Int Letra_R[7]={0B11111111, 0B10001000, 0B10001100, 0B10001010, 0B01110001, 0B00000000, 0B00000000};
Int Letra_S[7]={0B11110011, 0B10001001, 0B10001001, 0B10001001, 0B11000111, 0B00000000, 0B00000000};
Int Letra_T[7]={0B10000000, 0B10000000, 0B11111111, 0B10000000, 0B10000000, 0B00000000, 0B00000000};
Int Letra_U[7]={0B11111110, 0B00000001, 0B00000001, 0B00000001, 0B11111110, 0B00000000, 0B00000000};
Int Letra_V[7]={0B11111100, 0B00000010, 0B00000001, 0B00000010, 0B11111100, 0B00000000, 0B00000000};
Int Letra_W[7]={0B11111111, 0B00000010, 0B00000100, 0B00000010, 0B11111111, 0B00000000, 0B00000000};
Int Letra_X[7]={0B11000111, 0B00101000, 0B00010000, 0B00101000, 0B11000111, 0B00000000, 0B00000000};
Int Letra_Y[7]={0B11000000, 0B00100000, 0B00011111, 0B00100000, 0B11000000, 0B00000000, 0B00000000};
Int Letra_Z[7]={0B11000111, 0B10001001, 0B10010001, 0B10100001, 0B11000011, 0B00000000, 0B00000000};
//Int Espacio[5]={0B00000000, 0B00000000, 0B00000000, 0B00000000, 0B00000000};

//Declaramos una variable para el tiempo.
Int8 Tiempo = 2;

int8 i=0, j = 0,k=0;
char letter;
char word[100];
char wordreal[100];
int counter  = 0;
int counterLoop = 0;

Void Limpiar_palabra();
void print();

#Int_ext
Void Texto()
{
   PORTD=0x00;
   Print();
   PORTD=0x00;
}

Void main()
{
   TRISD=0x00;
   Fprintf(TTL, "READY TO GO\r\n");
   //letter = fgetc(BTH);
   Limpiar_palabra();
   Enable_interrupts(GLOBAL);
   Enable_interrupts(int_ext);
   PORTD=0x00;
   //Delay_ms(200);
      regreso: 
      
      while(!input(pin_e2)){
      For(i=0; i<8; i++)
      {
         Letter = Fgetc(BTH);
         Delay_us(10);
         Output_high(PIN_A1);
         If(letter == '.')
            Goto Imprimir;
         Word[i] = Letter;
      }
      
      Imprimir:
      delay_us(50);
      for(int y=0;y<8;y++)
      {
         wordreal[y] = word[y];
      }
      
      fprintf(TTL, "[1er registro] La palabra es: \r\n");
      for(j=0;j<8;j++)
      {
         fprintf(TTL, "%c", wordreal[j]);
      }
      
    delay_ms(500);
    output_low(pin_a1);
    //limpiar_palabra();
   
     
   }
   //Rompe el ciclo while cuando el motor empieza a girar (cuando el sensor de vibracion detecta movimiento)
   
   //Si el motor se esta moviendo:
   if(input(pin_e2))
   {
               do{
            //Si se detecta una entrada de datos mediante kbhit()
               if(kbhit(BTH))
               {
                  //limpiar_palabra();
                  output_high(pin_a2);
                  //"Guardar" la palabra que se detecta en la variable word
                 
                  For(int h=0; h<8; h++)
                  {
                     Letter = Fgetc(BTH);
                     Delay_us(10);
                     Output_high(PIN_A1);
                     If(letter == '.')
                        Goto Imprimir1;
                     Word[h] = Letter;
                  }
                  
                  Imprimir1:
                  delay_us(50);
                  output_low(pin_a2);
               }
               else //input(pin_e2) and kbhit()==0 (Kbhit doesn't register a new word coming in)
               {
                  fprintf(TTL, "El motor esta girando y no hay registro de palabra!!: \r\n");
               
               }
                  }while(input(pin_e2)); //Se rompe este ciclo solo hasta que se detiene el motor
   
   
                  fprintf(TTL, "El motor ha parado, ahora hara el intercambio de palabra\r\n");
                  //Al romperse este ciclo, (al pararse el motor) entonces procede intercambiar la palabra
                  //word por wordreal, es decir, ahora si hace el registro de la palabra que se va a mostrar en 
                  //el propeller solo cuando el motor llega a un paro y no cuando esta girando.
                  for(int f=0;f<8;f++)
                  {
                     wordreal[f] = word[f];
                  }
                  fprintf(TTL, "[2do registro] La palabra es: \r\n");
                  for(int t=0;t<8;t++)
                  {
                     fprintf(TTL, "%c", wordreal[t]);
                  }
                  
                  goto regreso;
           
   }
   
   else
      goto regreso;
   
} //Main.

Void Limpiar_palabra()
{
   For(K=0; K<8; K++)
      {
         Word[k] = 0;
      }
}


Void Print()
{
   For(i=0; i<8; i++)
   {
      letter = wordreal[i];
      Switch(letter)
      {
         Case 'A': Case 'a':
         {
            for(j=0;j<7;j++)
            {
               PORTD = Letra_A[j];
               delay_ms(Tiempo);
            }
            //Delay_ms(5);
            Break;
         }
         Case 'B': Case 'b':
         {
            for(j=0;j<7;j++)
            {
               PORTD = Letra_B[j];
               delay_ms(Tiempo);
            }
            Break;
         }
         Case 'C': Case 'c':
         {
            for(j=0;j<7;j++)
            {
               PORTD = Letra_C[j];
               delay_ms(Tiempo);
            }
            Break;
         }
         Case 'D': Case 'd':
         {
            for(j=0;j<7;j++)
            {
               PORTD = Letra_D[j];
               delay_ms(Tiempo);
            }
            Break;
         }
         Case 'E': Case 'e':
         {
            for(j=0;j<7;j++)
            {
               PORTD = Letra_E[j];
               delay_ms(Tiempo);
            }
            Break;
         }
         Case 'F': Case 'f':
         {
            for(j=0;j<7;j++)
            {
               PORTD = Letra_F[j];
               delay_ms(Tiempo);
            }
            Break;
         }
         Case 'G': Case 'g':
         {
            for(j=0;j<7;j++)
            {
               PORTD = Letra_G[j];
               delay_ms(Tiempo);
            }
            Break;
         }
         Case 'H': Case 'h':
         {
            for(j=0;j<7;j++)
            {
               PORTD = Letra_H[j];
               delay_ms(Tiempo);
            }
            Break;
         }
         Case 'I': Case 'i':
         {
            for(j=0;j<7;j++)
            {
               PORTD = Letra_I[j];
               delay_ms(Tiempo);
            }
            Break;
         }
         Case 'J': Case 'j':
         {
            for(j=0;j<7;j++)
            {
               PORTD = Letra_J[j];
               delay_ms(Tiempo);
            }
            Break;
         }
         Case 'K': Case 'k':
         {
            for(j=0;j<7;j++)
            {
               PORTD = Letra_K[j];
               delay_ms(Tiempo);
            }
            Break;
         }
         Case 'L': Case 'l':
         {
            for(j=0;j<7;j++)
            {
               PORTD = Letra_L[j];
               delay_ms(Tiempo);
            }
            Break;
         }
         Case 'M': Case 'm':
         {
            for(j=0;j<7;j++)
            {
               PORTD = Letra_M[j];
               delay_ms(Tiempo);
            }
            //Delay_ms(5);
            Break;
         }
         Case 'N': Case 'n':
         {
            for(j=0;j<7;j++)
            {
               PORTD = Letra_N[j];
               delay_ms(Tiempo);
            }
            Break;
         }
         Case 'O': Case 'o':
         {
            for(j=0;j<7;j++)
            {
               PORTD = Letra_O[j];
               delay_ms(Tiempo);
            }
            Break;
         }
         Case 'P': Case 'p':
         {
            for(j=0;j<7;j++)
            {
               PORTD = Letra_P[j];
               delay_ms(Tiempo);
            }
            Break;
         }
         Case 'Q': Case 'q':
         {
            for(j=0;j<7;j++)
            {
               PORTD = Letra_Q[j];
               delay_ms(Tiempo);
            }
            Break;
         }
         Case 'R': Case 'r':
         {
            for(j=0;j<7;j++)
            {
               PORTD = Letra_R[j];
               delay_ms(Tiempo);
            }
            Break;
         }
         Case 'S': Case 's':
         {
            for(j=0;j<7;j++)
            {
               PORTD = Letra_S[j];
               delay_ms(Tiempo);
            }
            Break;
         }
         Case 'T': Case 't':
         {
            for(j=0;j<7;j++)
            {
               PORTD = Letra_T[j];
               delay_ms(Tiempo);
            }
            Break;
         }
         Case 'U': Case 'u':
         {
            for(j=0;j<7;j++)
            {
               PORTD = Letra_U[j];
               delay_ms(Tiempo);
            }
            //Delay_ms(5);
            Break;
         }
         Case 'V': Case 'v':
         {
            for(j=0;j<7;j++)
            {
               PORTD = Letra_V[j];
               delay_ms(Tiempo);
            }
            Break;
         }
         Case 'W': Case 'w':
         {
            for(j=0;j<7;j++)
            {
               PORTD = Letra_W[j];
               delay_ms(Tiempo);
            }
            Break;
         }
         Case 'X': Case 'x':
         {
            for(j=0;j<7;j++)
            {
               PORTD = Letra_X[j];
               delay_ms(Tiempo);
            }
            Break;
         }
         Case 'Y': Case 'y':
         {
            for(j=0;j<7;j++)
            {
               PORTD = Letra_Y[j];
               delay_ms(Tiempo);
            }
            Break;
         }
         Case 'Z': Case 'z':
         {
            for(j=0;j<7;j++)
            {
               PORTD = Letra_Z[j];
               delay_ms(Tiempo);
            }
            Break;
         }
      }//Aquí se cierra el Switch.
      
   } //Aquí se cierra el For.
} //Aquí se cierra la función.
