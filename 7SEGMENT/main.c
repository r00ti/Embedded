// CONFIG

#pragma config  RETEN = ON,INTOSCSEL = LOW, SOSCSEL = DIG,  XINST = OFF	//CONFIG1L
#pragma config  FOSC = INTIO2, PLLCFG = ON, FCMEN = OFF, IESO = ON 		//CONFIG1H
#pragma config PWRTEN = OFF, BOREN = OFF , BORV = 3, BORPWR = ZPBORMV	// CONFIG2L
#pragma config WDTEN = OFF, WDTPS = 128									// CONFIG2H
#pragma config MCLRE = ON, MSSPMSK = MSK7, CANMX = PORTC				// CONFIG3H
#pragma config BBSIZ = BB1K,  STVREN = ON								// CONFIG4L
#pragma config CP0 = OFF, CP1 = OFF, CP2 = OFF, CP3 = OFF                   // CONFIG5L
#pragma config CPB = OFF, CPD = OFF                                         // CONFIG5H
#pragma config WRT0 = OFF, WRT1 = OFF, WRT2 = OFF, WRT3 = OFF               // CONFIG6L
#pragma config WRTB = OFF, WRTC = OFF, WRTD = OFF                          // CONFIG6H
#pragma config EBTR0 = OFF, EBTR1 = OFF, EBTR2 = OFF, EBTR3 = OFF           // CONFIG7L
#pragma config EBTRB = OFF												// CONFIG7H

#include <p18lf46k80.h>

#define BUTTON PORTDbits.RD7
#define FCPU 500000             // oscillator speed (with PLL enabled, 8Mhz x 4 = 32Mhz)
void delay_us(int us){
	unsigned long i=((FCPU/100000000.0)*us)/4;
	for (;i>0;--i);
}

void delay_ms(int ms){
	unsigned i;
	for (i=0;i<ms;++i)delay_us(998);
}

void delay_s(int s){
	unsigned i;
	for (i=0;i<s;++i)delay_ms(1000);
}

void delay()
 {
   unsigned int i;
   for(i=0;i<100;i++);
}

int j;

void main()
{

unsigned short result;
int a1,b1,iValue, CentTemp,i2;
  // 
// TRISCbits.TRISC2=0;
unsigned int a,b,c,d,e,f,g,h; //just variables
int i = 0; //the 4-digit value that is to be displayed
int flag =0; //for creating delay
unsigned int seg[]={0Xc0, //Hex value to display the number 0
                    0Xf9, //Hex value to display the number 1
                    0Xa4, //Hex value to display the number 2
                    0Xb0, //Hex value to display the number 3
                    0X99, //Hex value to display the number 4
                    0X92, //Hex value to display the number 5
                    0X82, //Hex value to display the number 6
                    0Xf8, //Hex value to display the number 7
                    0X80, //Hex value to display the number 8
                    0X90  //Hex value to display the number 9
                   }; //End of Array for displaying numbers from 0 to 9
//*****I/O Configuration****//
TRISD=0X00;
//PORTD=0X00;
TRISB=0x00;
PORTB=0X00;
TRISDbits.TRISD7=1; // PIN RB1 as input (0-output 1-input)

TRISA=0x01;
ADCON0 = 0x81;               //Turn ON ADC and Clock Selection
ADCON1 = 0x00;               //All pins as Analog Input and setting Reference Voltages

while(1)
{
	if(!BUTTON){		//if buton pressed increese variable whitch shifting PORTD
		for(j=0;j<200;++j);  //delay debouncing
		if(!BUTTON)++i;	
	}
	while (!BUTTON);
	if(i>9){
		PORTB=seg[i/10];PORTD|=0b1<<0;
		delay_ms(10);PORTD&=~0b1<<0;
	}
	PORTB=seg[i%10];PORTD|=0b1<<1;
	delay_ms(5);PORTD&=~0b1<<1;
	if(i>99) i=0;
	} 
}