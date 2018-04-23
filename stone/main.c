/*

	*	PROJEKT STEROWNIKA DO MASZYNY CI�CIA KAMIENIA  *
			*		F_CPU 11059200 	     	 *
			*		CPU atmega128  			 *
			* 	FUSE - CKOPT,BOOTSZ1,
				BOOTSZ0,BODLEVEL,BODEN,STU1	 *

	*	AUTOR : in�. A.Rutkowski && mgr in�. A.Zo�	*
	*	DATA : 09.02.2017  *

*/


//ENKODER 10 krok�w na 1mm - resolution 0.1mm

#include "head.h"			//definicje funkcji i nag��wki
//#include "DS1305.h"			//zegar
#include "i2c_twi.h"		//i2c
#include <avr/iom128.h>
#include <avr/interrupt.h>	//przerwania

void Selftest(void);
//void ADCRefresh(void);
void Clock(void);
void ClockSet(void);
void SystemInit(void);
//void test(void);
//void pauza(void);
void send_info(void);

int main(void){
/*
- pozycja pocz�tkowa punkt 0,0,0 - manualnie naje�dzamy i w�aczamy sterownik
- ustawinia s� zerowane i rozpoczyna si� praca je�li przycisk cyklu START/STOP w pozycji START
- je�li w pozycji STOP maszyna czeka na start
*/
SystemInit();
sei();
adr=0x01;
usart_ini();
ilepasow = tablica_pasow[0];	//pierwszy element tablicy - ile pas�w
gleb_pily=20;	//konfiguracja - jak g��boko pi�a tnie
s_width=5;		//konfiguracja - szeroko�c pasa/pi�y - skok mostu w prawo
next_step=1;
koniec=0;
z_abs=0;		//aktualna pozycja Z z enkodera1 - przerwanie - 0..3000 (0-300.0mm) - rozdzielczo�� 0.1 lub 0.2mm
y_abs=0;		//aktualna pozycja Y z enkodera2 - przerwanie - 0..20000 (0-2000.0mm) - rozdzielczo�� 0.1 lub 0.2mm
z_temp=0;
y_temp=0;
i=0;
bit_tyl=1;	//rozpocz�cie od 0,0,0 pi�a z ty�u
bit_przod=0;
pause=0;
settings=0;
templatee=0;

while(1){
	Transmition_check();
	//obs�uga przycisku/prze�acznika START/STOP cyklu - zatrzymanie ruchu maszyny / kontynuacja ci�cia
	//
	Led1Tog;
	_delay_ms(100);
	if (Start) pause=1;
	if((settings==1)&&(templatee==1)){     //rozpocznie si� program dopiero po otrzymaniu ramki z ustawieniami i programem.
	Led1On;
	Led2On;
//*************************************
		if((next_step==1)&&(pause==0)){					//nast�pny pas do ci�cia
		Led3On;
			if(i<ilepasow){
				z_depth=tablica_pasow[i]; //pobierz g��boko�c kolejnego pasa z tablicy
				i++;
				next_step=0;
				reszta_z=z_depth;
			}
			else{
				Led3Off;
				Led4On;
				} 						//zatrzymanie pracy, odjazd, STOP - koniec tablicy
		}
//**************************************
		if((KRT_on)&&(bit_tyl==1)){ 		//maszyna na KRT, b�dzie jazda do przodu
			tyl=0;							//stop ruchu ty�
			przod=0;						//stop ruchu prz�d
			if(reszta_z==0){				//koniec pasa - b�dzie nast�pny do ci�cia
				koniec=1;
				gora=1;						//wyjazd do g�ry
				z_temp=0;					//wsp�rz�dna odjazdowa z=0
			}
			if(reszta_z>0){					//zosta�o jeszcze ci�cie pasa
				if(reszta_z>=gleb_pily){				//je�li zosta�o wi�cejlub = ni� gleboko�c pi�y
					z_temp=z_abs+gleb_pily;			//nowa wsp�rz�dna przesuni�ta o g��boko�c pi�y
					reszta_z=reszta_z-gleb_pily;	//aktualizuj reszt� materia�u
					koniec=0;
				}
				if(reszta_z<gleb_pily){					//je�li zosta�o mniej ni� g��boko�c pi�y
					z_temp=z_abs+reszta_z;			//nowa wsp�rz�dna przesuni�ta o reszt�
					reszta_z=0;						//pozosta�o 0 do ci�cia
					koniec=1;
				}
			dol=1;		//jazda w d�
			gora=0;
			bit_przod=1;
			bit_tyl=0;
			}
		}
//**************************************
		if((KRP_on)&(bit_przod==1)){		//maszyna na KRP, b�dzie jazda do ty�u
			tyl=0;							//stop ruchu ty�
			przod=0;						//stop ruchu prz�d
			if(reszta_z==0){				//koniec pasa - b�dzie nast�pny do ci�cia
				koniec=1;
				gora=1;						//wyjazd do g�ry
				z_temp=0;					//wsp�rz�dna odjazdowa z=0
			}
			if(reszta_z>0){					//zosta�o jeszcze ci�cie pasa
				if(reszta_z>=gleb_pily){				//je�li zosta�o wi�cej ni� gleboko�c pi�y
					z_temp=z_abs+gleb_pily;			//nowa wsp�rz�dna przesuni�ta o g�eboko�c pi�y
					reszta_z=reszta_z-gleb_pily;	//aktualizuj reszte do ci�cia
					koniec=0;
				}
				if(reszta_z<gleb_pily){				//je�li zosta�o mniej ni� g��boko�c pi�y
					z_temp=z_abs+reszta_z;		//nowa wsp�rz�dna przesuni�ta o reszt�
					reszta_z=0;					//pozostao do ci�cia 0
					koniec=1;
				}
			dol=1;		//jazda w d�
			gora=0;
			bit_przod=0;
			bit_tyl=1;
			}

		}
//**************************************
		if((dol==1)&(z_temp>=z_abs)){		//zatrzymanie ruchu w d� gdy osi�gni�ta pozycja z_temp
			dol=0;							//stop ruchu d�
			if(bit_przod==1){
				przod=1;		//jazda do przodu
				tyl=0;
			}
			if(bit_tyl==1){
				przod=0;		//jazda do tylu
				tyl=1;
			}
		}
//**************************************
		if((gora==1)&(z_temp<=z_abs)){ //osi�gni�ta g�ra z=0
			gora=0;						//zatrzymaj ruch do g�ry
			prawo=1;					//jed� na kolejny pas
			y_temp=y_abs+s_width;		//nast�pna pozycja pasa
		}
//**************************************
		if((prawo==1)&(y_temp>=y_abs)){ 	//osi�gni�to nast�pny pas
			prawo=0;						//zatrzymaj ruch prawo
			next_step=1;					//nst�pny pas z tablicy do ci�cia
		}
//***********************************************************************************************************
		if(przod==1){
			_delay_ms(500);			//przed ruchem odczeka� op�nienie - timer
			Vx_on;
			PRZOD_on;
		}
		if(przod==0){
			PRZOD_off;
		}
//**************************************
		if(tyl==1){
			_delay_ms(500);
			Vx_on;
			TYL_on;
		}
		if(tyl==0){
			TYL_off;
		}
//*************************************
		if(prawo==1){
			_delay_ms(500);
			Vy_on;
			PRAWO_on;
		}
		if(prawo==0){
			PRAWO_off;
		}
//*************************************
		if(lewo==1){
			_delay_ms(500);
			Vy_on;
			LEWO_on;
		}
		if(lewo==0){
			LEWO_off;
		}
//*************************************
		if(gora==1){
			_delay_ms(500);
			Vz_on;
			GORA_on;
		}
		if(gora==0){
			GORA_off;
		}
//************************************
		if(dol==1){
			_delay_ms(500);
			Vz_on;
			DOL_on;
		}
		if(dol==0){
			DOL_off;
		}
//************************************
	}
	}

}

//*************************************************************************************************************
void Selftest(void){

}
//*************************************************************************************************************

void SystemInit(void){			//system init

//----------USTAWIENIE PORT�W JAKO WEJ�CIA-------------------------------------//
In1;In2;In4;
In5;In6;In7;In8;
In9;In10;In11;In12;
In13;In14;In15;In16;

//----------------------------------------------PRZERWANIA-----------------------------------------------------------/

EICRB |= ((1<<ISC40)|(1<<ISC50)|(1<<ISC60)|(1<<ISC70));   //ZBOCZE NARASTAJACE
EIMSK |= (1<<INT4)|(1<<INT5)|(1<<INT6)|(1<<INT7);	//WLACZENIE PRZERWAN
EIFR |= (1<<INTF4)|(1<<INTF5)|(1<<INTF6)|(1<<INTF7);
DDRE &= ~ (1<<PE4)|(1<<PE5)|(1<<PE6)|(1<<PE7);          //USTAWIENIE WEJSC NA 1

}
//***************************************************************************************************************
void Clock(void){
unsigned char b0,b1,b2,b3,b4,b5,b6,b7,b8,b9,b10,b11,b12;

hours=DS1305_read_byte(0x02);		// read hours
minutes=DS1305_read_byte(0x01);    // read minutes
seconds=DS1305_read_byte(0x00);	// read seconds
day=DS1305_read_byte(0x03);		//read day
date=DS1305_read_byte(0x04);		//read date
month=DS1305_read_byte(0x05);		//read month
year=DS1305_read_byte(0x06);		//read year
_delay_ms(10);

b0=(seconds & 0x0F)+16;
b1=(seconds & 0x70);b1=b1/16+16;
b2=(minutes & 0x0F)+16;
b3=(minutes & 0x70);b3=b3/16+16;
b4=(hours & 0x0F)+16;
b5=(hours & 0x30);b5=b5/16+16;
b6=(day & 0x0F)+16;
b7=(date & 0x0F)+16;
b8=(date & 0x30);b8=b8/16+16;
b9=(month & 0x0F)+16;
b10=(month & 0x30);b10=b10/16+16;
b11=(year & 0x0F)+16;
b12=(year & 0xF0);b12=b12/16+16;

}
//****************************************************************************************************************

//------------------------ nastawianie zegara --------//
void ClockSet(void){
DS1305_write_byte(0x86,0x06);	//year
DS1305_write_byte(0x85,0x04); 	//month
DS1305_write_byte(0x84,0x18);	//date
DS1305_write_byte(0x83,0x02); 	//day
DS1305_write_byte(0x82,0x07); 	//hours
DS1305_write_byte(0x81,0x54); 	//minutes
DS1305_write_byte(0x80,0x00); 	//seconds
}

void send_info(void){

/*je�li nie ma obs�ugi przewa� g�ra i prawo - wy�lij aktualne parametry:
	adr
	ilepasow  	- �acznie do ci�cia
	i+1 		- aktualnie ci�ty pas
	z_depth		- aktualna g��boko�c do ci�cia
	z_abs		- pozycja Z aktualna
	y_abs		- pozycja Y aktualna
*/
unsigned short crc;
	rozmiar=8;
	ramka[0] =0x01;
	ramka[1]= ilepasow;
	ramka[2]=i;
	ramka[3]=z_depth;
	ramka[4]=z_abs;
	ramka[5]=y_abs;
	crc = ModbusCRC(ramka, rozmiar-2);
	ramka[rozmiar-2]= crc;
	crc >>= 8;
	ramka[rozmiar-1]= crc;
	wyslij();
}
//-------------PRZERWANIA ZEWNETRZNE--------------------//

ISR (INT4_vect){
send_info();
static uint8_t dir;
if ( ! (PINE & (1<<PE4)))
	dir= (PINE & (1<<PE5));
	else {
		if (dir != (PINE & (1<<PE5))){
			if (dir) {
				z_abs++;
				Led4Tog;
			}
			else {
				z_abs--;
			}
		}
	}
}
//-------------STOP----------------------//
ISR (INT5_vect){
static uint8_t dir;
if ( ! (PINE & (1<<PE5)))
	dir= (PINE & (1<<PE4));
	else {
		if (dir != (PINE & (1<<PE5))){
			if (dir) {
				z_abs++;
			}
			else {
				z_abs--;
			}
		}
	}

}
//-------------O� Y----------------------//
ISR (INT6_vect){
static uint8_t dir;
if ( ! (PINE & (1<<PE4)))
	dir= (PINE & (1<<PE5));
	else {
		if (dir != (PINE & (1<<PE5))){
			if (dir) {
				z_abs++;
				Led3Tog;
			}
			else {
				z_abs--;
			}
		}
	}
}
//-------------O� Z----------------------//

ISR (INT7_vect){
static uint8_t dir;
if ( ! (PINE & (1<<PE4)))
	dir= (PINE & (1<<PE5));
	else {
		if (dir != (PINE & (1<<PE5))){
			if (dir) {
				z_abs++;
			}
			else {
				z_abs--;
			}
		}
	}


}
