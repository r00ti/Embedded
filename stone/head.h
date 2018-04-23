#include <util/delay.h>
#include <stdlib.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/iom128.h>
#include <string.h>
#include <avr/pgmspace.h>
#include <avr/eeprom.h>
#include <stdio.h>
#include <ctype.h>   
#include <compat/deprecated.h> 

#define     DS1305_CS_BIT        PL1            			// DS1305 CS strobe
#define     DS1305_CS_PORT       PORTL      
#define     DS1305_CS_PORT_DIR   DDRL 

volatile unsigned char hours,minutes,seconds,date,month,year,day;
unsigned char rozmiar2;
volatile unsigned int m;
volatile int enkoder,enkoder2;
volatile int flaga;
volatile unsigned char adr,adr1, rozmiar;

//*******************************************************************************************************************
unsigned int tablica_pasow[255]; 	//tablica g³êbokoœci pasów do ciêcia - max 254 pasy o wysokoœci 0..3000 (0-300.0mm)
unsigned int tablica_pasow2[255]; 	//tablica g³êbokoœci pasów do ciêcia - max 254 pasy o wysokoœci 0..3000 (0-300.0mm)
unsigned char ilepasow;				//iloœc pasów do ciêcia
unsigned char ilepasow2;				//iloœc pasów do ciêcia
unsigned int z_depth;				//g³êbokoœc aktualnego pasa
unsigned int reszta_z;				//reszta g³êbokoœci do przeciêcia
unsigned int s_width;				//szerokoœæ pasa / skok pi³y
unsigned int gleb_pily;				//g³êbokoœc ciêcia
unsigned int z_abs,y_abs,z_temp,y_temp;				//absolutne pomiary po resecie - wspó³rzêdne i pomocnicze
unsigned char bit_przod,bit_tyl,koniec,nextstep;				//bity pomocnicze
unsigned char tyl,przod,gora,dol,prawo,lewo;		//bity pomocnicze
unsigned int next_step;				//nastêpny pas do ciêcia 
unsigned i;
unsigned char pause,templatee,templatee2,settings;

//********************************************************************************************************************

/*********************************WYJSCIA PRZEKAZNIKOWE****************************/
/*
Vx_on, Vy_off, Vz_off- ustaw prêdkoœæ falownika w osi X  przekaŸnik K1 wy1
Vx_off, Vy_on, Vz_off- ustaw prêdkoœæ falownika w osi Y  przekaŸnik K2 wy2
Vx_off, Vy_off, Vz_on- ustaw prêdkoœæ falownika w osi Z  przekaŸnik K3 wy3

PRZOD_on - ruch do przodu przeka¿nik K4
PRZOD_off - ruch do przodu przeka¿nik K4
TYL_on - ruch do ty³u przekaŸnik K5
TYL_off - ruch do ty³u przkaŸnik K5
PRAWO_on - ruch w prawo przekaŸnik K6
PRAWO_off - ruch w prawo przekaŸnik K6
LEWO_on - ruch w lewo przekaŸnik K7
LEWO_off - ruch w lewo przekaŸnik K7
GORA_on	- ruch do góry przekaŸnik K8
GORA_off - ruch do gory przekaŸnik K8
DOL_on - ruch w do³ przekaŸnik K9
DOL_off - ruch w do³ przkaŸnik K9
*/

#define Vx_on     DDRA|=(1<<PA7); PORTA &= ~ (1<<PA7)  	//WY1ON
#define Vx_off    DDRA|=(1<<PA7); PORTA |= (1<<PA7)  	//WY1OFF
#define Vy_on     DDRA|=(1<<PA6); PORTA &= ~ (1<<PA6)  	//WY2ON
#define Vy_off    DDRA|=(1<<PA6); PORTA |= (1<<PA6)  	//WY2OFF
#define Vz_on     DDRA|=(1<<PA5); PORTA &= ~ (1<<PA5)  	//WY3ON
#define Vz_off    DDRA|=(1<<PA5); PORTA |= (1<<PA5)  	//WY3OFF
#define PRZOD_on  DDRA|=(1<<PA4); PORTA &= ~ (1<<PA4)  	//WY4ON
#define PRZOD_off DDRA|=(1<<PA4); PORTA |= (1<<PA4)  	//WY4OFF
#define TYL_on    DDRA|=(1<<PA3); PORTA &= ~ (1<<PA3)  	//WY5ON
#define TYL_off   DDRA|=(1<<PA3); PORTA |= (1<<PA3)  	//WY5OFF
#define PRAWO_on  DDRA|=(1<<PA2); PORTA &= ~ (1<<PA2)  	//WY6ON
#define PRAWO_off DDRA|=(1<<PA2); PORTA |= (1<<PA2)  	//WY6OFF
#define LEWO_on   DDRA|=(1<<PA1); PORTA &= ~ (1<<PA1)  	//WY7ON
#define LEWO_off  DDRA|=(1<<PA1); PORTA |= (1<<PA1)  	//WY7OFF
#define GORA_on   DDRA|=(1<<PA0); PORTA &= ~ (1<<PA0)  	//WY8ON
#define GORA_off  DDRA|=(1<<PA0); PORTA |= (1<<PA0)  	//WY8OFF
#define DOL_on    DDRF|=(1<<PF7); PORTF &= ~ (1<<PF7)  	//WY9ON
#define DOL_off   DDRF|=(1<<PF7); PORTF |= (1<<PF7)  	//WY9OFF

#define Out1On   DDRF|=(1<<PF6); PORTF &= ~ (1<<PF6)  	//WY10ON
#define Out1Off  DDRF|=(1<<PF6); PORTF |= (1<<PF6)  	//WY10OFF
#define Out2On   DDRF|=(1<<PF5); PORTF &= ~ (1<<PF5)  	//WY11ON
#define Out2Off  DDRF|=(1<<PF5); PORTF |= (1<<PF5)  	//WY11OFF
#define Out3On   DDRF|=(1<<PF4); PORTF &= ~ (1<<PF4)  	//WY12ON
#define Out3Off  DDRF|=(1<<PF4); PORTF |= (1<<PF4)  	//WY12OFF
#define Out4On   DDRF|=(1<<PF3); PORTF &= ~ (1<<PF3)  	//WY13ON
#define Out4Off  DDRF|=(1<<PF3); PORTF |= (1<<PF3)  	//WY13OFF
#define Out5On   DDRF|=(1<<PF2); PORTF &= ~ (1<<PF2)  	//WY14ON
#define Out5Off  DDRF|=(1<<PF2); PORTF |= (1<<PF2)  	//WY14OFF
#define Out6On   DDRF|=(1<<PF1); PORTF &= ~ (1<<PF1)  	//WY15ON
#define Out6Off  DDRF|=(1<<PF1); PORTF |= (1<<PF1)  	//WY15OFF
#define Out7On   DDRF|=(1<<PF0); PORTF &= ~ (1<<PF0)  	//WY16ON
#define Out7Off  DDRF|=(1<<PF0); PORTF |= (1<<PF0)  	//WY16OFF

/************************************************************************************/
/**************************WEJŒCIA CYFROWE*******************************************/
/*
KRT_on - krañcówka ty³ aktywna/naciœniêta - lewa strona mostu maszyny
KRT_off - kranæowka ty³ nieaktywna/ zwolniona
KRP_on - krañcówka przod aktywna/naciœniêta - prawa strona mostu maszyny
KRP_off - kranæowka przod nieaktywna/ zwolniona
KRL_on - krañcówka lewo aktywna/naciœniêta - strona bliska od operatora
KRL_off - kranæowka lewo nieaktywna/ zwolniona 
KRR_on - krañcówka prawo aktywna/naciœniêta - strona daleka od operatora
KRR_off - kranæowka prawo nieaktywna/ zwolniona
KRG_on - krañcówka góra aktywna/naciœniêta - pi³a w górze
KRG_off - kranæowka gora nieaktywna/ zwolniona
KRD_on - krañcówka do³ aktywna/naciœniêta - pi³a w dole
KRD_off - kranæowka do³ nieaktywna/ zwolniona
*/ 
#define KRT_on  !(PING & 1<<PG0) 	
#define KRT_off !(PING & 1<<PG1) 	
#define KRP_on  !(PING & 1<<PG3) 	
#define KRP_off !(PIND & 1<<PD4) 	
#define KRL_on  !(PIND & 1<<PD5)	
#define KRL_off !(PIND & 1<<PD6) 	
#define KRR_on  !(PIND & 1<<PD7) 	
#define KRR_off !(PINC & 1<<PC0) 	
#define KRG_on  !(PINC & 1<<PC1) 	
#define KRG_off !(PINC & 1<<PC2) 	
#define KRD_on  !(PINC & 1<<PC3) 	
#define KRD_off !(PINC & 1<<PC4) 	
#define Start   !(PINC & 1<<PC5)


#define In1  DDRG &= ~(1<<PG0); PING |= (1<<PG0) 	//WEJ1
#define In2  DDRG &= ~(1<<PG1); PING |= (1<<PG1) 	//WEJ2
#define In3  DDRG &= ~(1<<PG3); PING |= (1<<PG3) 	//WEJ3
#define In4  DDRD &= ~(1<<PD4); PIND |= (1<<PD4) 	//WEJ4
#define In5  DDRD &= ~(1<<PD5); PIND |= (1<<PD5) 	//WEJ5
#define In6  DDRD &= ~(1<<PD6); PIND |= (1<<PD6) 	//WEJ6
#define In7  DDRD &= ~(1<<PD7); PIND |= (1<<PD7) 	//WEJ7
#define In8  DDRC &= ~(1<<PC0); PINC |= (1<<PC0) 	//WEJ8
#define In9  DDRC &= ~(1<<PC1); PINC |= (1<<PC1) 	//WEJ9
#define In10 DDRC &= ~(1<<PC2); PINC |= (1<<PC2) 	//WEJ10
#define In11 DDRC &= ~(1<<PC3); PINC |= (1<<PC3) 	//WEJ11
#define In12 DDRC &= ~(1<<PC4); PINC |= (1<<PC4) 	//WEJ12
#define In13 DDRC &= ~(1<<PC5); PINC |= (1<<PC5) 	//WEJ13
#define In14 DDRC &= ~(1<<PC5); PINC |= (1<<PC5) 	//WEJ14
#define In15 DDRC &= ~(1<<PC6); PINC |= (1<<PC6) 	//WEJ15
#define In16 DDRC &= ~(1<<PC7); PINC |= (1<<PC7) 	//WEJ16


/************************************************************************************/
/**********************DIODY SYGNALIZUJACE*******************************************/

#define Led1On  DDRB |= (1<<PB4); PORTB &= ~(1<<PB4) //LED1ON
#define Led1Off DDRB |= (1<<PB4); PORTB |=(1<<PB4)	 //LED1OFF
#define Led1Tog DDRB|=(1<<PB4);   PORTB ^=(1<<PB4)	 //LED1TOG
#define Led2On  DDRB |= (1<<PB5); PORTB &= ~(1<<PB5) //LED2ON
#define Led2Off DDRB |= (1<<PB5); PORTB |=(1<<PB5)	 //LED2OFF
#define Led2Tog DDRB|=(1<<PB5);   PORTB ^=(1<<PB5)	 //LED2TOG
#define Led3On  DDRB |= (1<<PB6); PORTB &= ~(1<<PB6) //LED3ON
#define Led3Off DDRB |= (1<<PB6); PORTB |=(1<<PB6)	 //LED3OFF
#define Led3Tog DDRB|=(1<<PB6);   PORTB ^=(1<<PB6)	 //LED3TOG
#define Led4On  DDRB |= (1<<PB7); PORTB &= ~(1<<PB7) //LED4ON
#define Led4Off DDRB |= (1<<PB7); PORTB |=(1<<PB7)	 //LED4OFF
#define Led4Tog DDRB|=(1<<PB7);   PORTB ^=(1<<PB7)	 //LED4TOG

/************************************************************************************/
/**********************************INNE WYJSCIA*************************************/

#define BuzzOn DDRE |= (1<<PE3);PORTE |= (1<<PE3)	 //BUZZERON
#define BuzzOff DDRE |= (1<<PE3);PORTE &~ =(1<<PE3)	 //BUZZEROFF

/************************************************************************************/
//******************************TRANSMISJA RS 485************************************/
unsigned short ModbusCRC(unsigned char * buf, int size);

void Transmition_check(void);
void usart_ini(void);
char spr_ramke(void);
void answer_to_sender(void);
void usart_rec_en(void);
void usart_rec_dn(void);
void wyslij(void);

unsigned char tablica2[500];
unsigned char tablica[500];			
unsigned char ramka[500];
unsigned char uh,ul;
unsigned char jednostka;


/************************************************************************************/