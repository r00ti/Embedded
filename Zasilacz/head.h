#include <compat/deprecated.h> 
#include <util/delay.h>

#define BUZZERON DDRC |= (1<<PC4) ; PORTC &= ~(1<<PC4)
#define BUZZEROFF DDRC |= (1<<PC4); PORTC |= (1<<PC4)
#define BUZZERTOG DDRC |= (1<<PC4); PORTC ^= (1<<PC4)
#define FANOFF DDRC |= (1<<PC5); PORTC &= ~(1<<PC5)
#define FANON DDRC |= (1<<PC5); PORTC |= (1<<PC5)

#define LED1ON DDRD |= (1<<PD3); PORTD &= ~(1<<PD3)
#define LED1OFF DDRD |= (1<<PD3); PORTD |= (1<<PD3)
#define LED1TOG DDRD |= (1<<PD3); PORTD ^= (1<<PD3)

#define LED2ON DDRD |= (1<<PD2); PORTD &= ~(1<<PD2)
#define LED2OFF DDRD |= (1<<PD2); PORTD |= (1<<PD2)
#define LED2TOG DDRD |= (1<<PD2); PORTD ^= (1<<PD2)

#define LED3ON DDRD |= (1<<PD1); PORTD &= ~(1<<PD1)
#define LED3OFF DDRD |= (1<<PD1); PORTD |= (1<<PD1)
#define LED3TOG DDRD |= (1<<PD1); PORTD ^= (1<<PD1)

#define LED4ON DDRD |= (1<<PD0); PORTD &= ~(1<<PD0)
#define LED4OFF DDRD |= (1<<PD0); PORTD |= (1<<PD0)
#define LED4TOG DDRD |= (1<<PD0); PORTD ^= (1<<PD0)


#define SetTimer0 TCCR0=0x05; TIMSK|=(1<<TOIE0)
#define ADCIN PC1
#define HIS_UP 2
#define HIS_DOWN 2

uint8_t fan,actual,time_sek, sekunda, flaga,reset_time;
uint8_t subzero,cel,cel_fract_bits,czujniki_cnt;
unsigned int value;
int zlicz;






