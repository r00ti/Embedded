#include <head.h>	
#include <stdlib.h>
#include <stdio.h>

#include <string.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/iom8.h>
#include <util/delay.h>
#include "1Wire/ds18x20.h"
#include "LCD/lcd44780.h"
#include <avr/pgmspace.h>
#include <avr/eeprom.h>
#include "ADC_routines.h"


//----------------W£ASNE ZNAKI-----------------------------//
uint8_t znak_term[] PROGMEM = {4,10,10,10,17,31,31,14};
uint8_t znak_stopnie[] PROGMEM = {24,24,0,7,4,4,4,7};
uint8_t znak_logo1[] PROGMEM = {30,19,17,16,24,15,8,24};
uint8_t znak_logo2[] PROGMEM = {0,17,31,31,27,17,0,27};
uint8_t znak_logo3[] PROGMEM = {15,25,17,1,3,30,2,3};
uint8_t znak_logo4[] PROGMEM = {2,2,4,4,24,0,0,0};
uint8_t znak_logo5[] PROGMEM = {27,0,17,14,17,17,14,4};
uint8_t znak_logo6[] PROGMEM = {8,8,4,4,3,0,0,0};
uint8_t znak_went1[]  = {25,17,19,30,10,31,17,19};


void pomiar_temp(void);
void uruchomienie (void);
void alarm (void);
volatile int adc;
int setki,jednosci,dzies;
		

#define VREF 5.05

typedef struct {

uint16_t adc_mid;		//wartosc srednia napiecia
uint16_t ref_adc;		//wartosc ADC odpowiadajaca napieciu srodkowemu
uint16_t ref_v;			//srodkowe napiecie
char v1[3];
char v2[3];
} TVOL;


uint16_t pomiar (uint8_t kanal);
void get_vol (uint16_t adc, TVOL *voltage);
int main(void){
//	LED1ON;
	czujniki_cnt=search_sensors();  //wyszukiwanie podlacoznego czujnika ds18b20
	SetTimer0;
	_delay_ms(20);
	uruchomienie();
	sei();
	
	ADCSRA |= (1<<ADEN)|(1<<ADFR)|(1<<ADIE)| (1<<ADPS0) |(1<<ADSC) 
				|(1<<ADPS1) |(1<<ADPS2);
	ADMUX =7;
	DDRC &=~ (1<<PC1) | (1<<PC2) | (1<<PC3);
	//float value;
while(1){
	pomiar_temp();
	
		
		if (sekunda==3){
	
		flaga=0;
		sekunda=0;				
	}
}
}

//------------------------------TIMER DLA POMIARU TEMPERATURY---------------------------------///

ISR (ADC_vect){
	adc=ADC*VREF/1024;

}



ISR (TIMER0_OVF_vect){  //przerwanie wywolywane co 0.0237sek
	reset_time++;
	time_sek++;
	if (reset_time > 200){	//wysy³anie temp co 5sek //13se
		reset_time = 0;	
	}
	if (time_sek > 100){	//sekunda
		sekunda++;
		flaga=1;
		time_sek=0;
	}
}
//---------------- INTERFEJS GRAFICZNY--------------------//
void uruchomienie (){
	lcd_init();
	lcd_cls();
	lcd_locate(1,5);
	lcd_str("Zasilacz");
	lcd_locate(2,7);
	lcd_str("laboratoryjny.");
	_delay_ms(2000);
	lcd_cls();
	lcd_defchar_P(0x82, znak_logo1);	//ladowanie do pamieci wlasnego znaku
	lcd_defchar_P(0x83, znak_logo2);	//ladowanie do pamieci wlasnego znaku
	lcd_defchar_P(0x84, znak_logo3);	//ladowanie do pamieci wlasnego znaku
	lcd_defchar_P(0x85, znak_logo4);	//ladowanie do pamieci wlasnego znaku
	lcd_defchar_P(0x86, znak_logo5);	//ladowanie do pamieci wlasnego znaku
	lcd_defchar_P(0x87, znak_logo6);	//ladowanie do pamieci wlasnego znaku
	lcd_locate(1,1);
	lcd_str("\x82");
	lcd_locate(1,2);
	lcd_str("\x83");
	lcd_locate(1,3);
	lcd_str("\x84");
	lcd_locate(2,5);
	lcd_str("\x87");
	lcd_locate(2,6);
	lcd_str("\x86");
	lcd_locate(2,7);
	lcd_str("\x85");
	lcd_locate(1,5);
	lcd_str("powered by");
	lcd_locate(2,11);
	lcd_str("r00ti");
	lcd_locate (2,17);
	lcd_locate(3,16);
	lcd_str("v1 03.17");
	_delay_ms(2000);
	lcd_cls();
	BUZZERON; // buzzer
	_delay_ms(100);
	BUZZEROFF;
	lcd_locate(0,0);
	lcd_str("I[A]=");
	lcd_locate(0,9);
	lcd_str("*I[A]=");
	lcd_locate(1,0);
	lcd_str("U[V]=");
	lcd_locate(1,10);
	lcd_str("P[W]=");
	lcd_defchar_P(0x80, znak_term);
	lcd_locate (3,4);
	lcd_str("\x80");
	lcd_locate (3,8);
	lcd_write_data (0xdf);                 //ZNAK STOPNIA CELSJUSZA
	lcd_str("C");
	lcd_defchar(0x81, znak_went1);
	lcd_locate(3,19);
	lcd_str("\x81");
	///ADC_init();	
}

uint16_t pomiar(uint8_t kanal){
	ADMUX= (ADMUX & 0b11111000) | kanal;
	ADCSR |= (1<<ADSC);
	while(ADCSR & (1<<ADSC));
	return ADCW;

}

void get_vol (uint16_t adc, TVOL *voltage){

	uint16_t wynik = (adc*voltage->ref_v)/voltage->ref_adc;
	itoa (wynik/100ul, voltage->v1,10);
	div_t divmod =div(wynik,100);
	divmod.


}
void pomiar_temp(){
czujniki_cnt=search_sensors();  //wyszukiwanie podlacoznego czujnika ds18b20
	if(( sekunda == 1)&&(flaga==1)) {
		DS18X20_start_meas( DS18X20_POWER_EXTERN, NULL );flaga=0;}
	if(( sekunda == 2)&&(flaga==1)) {
		if( DS18X20_OK == DS18X20_read_meas(gSensorIDs[0], &subzero, &cel, &cel_fract_bits) ){
			actual=(cel*10+cel_fract_bits)/10;
			lcd_locate(3,6);
			lcd_int(actual);	
			flaga=0;
		}
		else {
			flaga=0;
			lcd_locate(3,6);
			lcd_str("??");
			
			}
		if (actual+HIS_UP>=30){
			alarm();
			fan=1;
		}
		else if (actual+HIS_DOWN<=29){
			lcd_locate(2,4);
			lcd_str("                    ");
			fan=0;
			//FANOFF;
			BUZZEROFF;
			LED4OFF;
		}
		if (fan) {
			lcd_locate(3,21);
			lcd_str("ON ");	
		}
		else {
			lcd_locate(3,21);
			lcd_str("OFF");
	}
	}
}

void alarm (void){
	BUZZERON;
	lcd_locate(2,5);
	lcd_str("PRZEKROCZONA TEMP!");
	fan=1;
	FANON;
	LED4ON;
}
