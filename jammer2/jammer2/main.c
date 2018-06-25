/*
* main.c
*
*  Created on: 2018-06-22
*       Autor: arutkowski
*
*/
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define  KEY1 (1<<PC4)
#define  KEY2 (1<<PC5)
#define  KEY3 (1<<PC6)
#define  KEY4 (1<<PC7)
#define  KEY5 (1<<PA7)
#define  KEY6 (1<<PA6)
#define  KEY7 (1<<PA5)
#define  KEY8 (1<<PA4)

void USART_Init(void);
void uart_transmit (unsigned char data);
int randomValue(int min, int max);
void delay_ms(uint16_t count);

int main(void) {

	USART_Init();			// inicjalizacja UART
	DDRB |= (1<<PB0) | (1<<PB1);
	//----------WEJSCIA---------------------------------
	DDRA &= ~ KEY5| KEY6| KEY7| KEY8;
	DDRC &= ~  KEY1 | KEY2| KEY3| KEY4;
	PORTA |= KEY5| KEY6| KEY7| KEY8;
	PORTC |= KEY1 | KEY2| KEY3| KEY4;
	//-----------STROBE-----------------------------------
	DDRD |= (1<<PD2);
	//-----------------LICZBY PSEUDOLOSOWE---------------------
	int count;
	int delayChange=1;
	time_t tt;
	count = time(&tt);
	srand(count);
	uint8_t randomSize,licznik;
	sei();
	
	while(1) {
		if (!(PINC & KEY1)) delayChange= 2;
		else if (!(PINC & KEY2)) delayChange= 3;
		else if (!(PINC & KEY3)) delayChange= 4;
		else if (!(PINC & KEY4)) delayChange= 5;
		else if (!(PINA & KEY5)) delayChange= 6;
		else if (!(PINA & KEY6)) delayChange= 7;
		else if (!(PINA & KEY7)) delayChange= 8;
		else if (!(PINA & KEY8)) delayChange= 9;
		else {
			delayChange=1;
		}
		
		randomSize=randomValue(1,10);
		for(int i=0;i <randomSize ; i++){
			licznik=rand();
			uart_transmit(licznik);
		}
		delay_ms(delayChange *1000);
	}
}

void USART_Init(void)
{
	/* Set baud rate */
	//UBRRH = (unsigned char)(ubrr>>8);
	//UBRRL = (unsigned char)ubrr;
	UBRRH = 0;
	//UBRRL = 35;		//19200
	UBRRL = 5;  //9600
	/* Enable receiver and transmitter */
	UCSRB = (1<<RXEN)|(1<<TXEN);


	DDRD |= (1<<PD2);
	PORTD &= ~ (1<<PD2);
	/* Set frame format: 8data, 2stop bit */
	UCSRC = (1<<URSEL)|(1<<UCSZ0) |(1<<UCSZ1);
}


// function to send data - NOT REQUIRED FOR THIS PROGRAM IMPLEMENTATION
void uart_transmit (unsigned char data)
{
	PORTD |= (1<<PD2);
	_delay_ms(10);

	while (!( UCSRA & (1<<UDRE)));            // wait while register is free
	UDR = data;
	_delay_ms(10);

	PORTD &= ~ (1<<PD2);                            // load data in the register
}
int randomValue(int min, int max)
{
	int tmp;
	if (max>=min)
	max-= min;
	else
	{
		tmp= min - max;
		min= max;
		max= tmp;
	}
	return max ? (rand() % max + min) : min;
}

void delay_ms(uint16_t count) {
	while(count--) {
		_delay_ms(1);
	}
}
