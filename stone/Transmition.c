#include "head.h"
#include <avr/iom128.h>

//pola w buforze RS-a
#define max_data			6
#define ramka_protokol		4
#define max_buff			25500

#define 	UDR 		UDR1
#define 	UCSRB 		UCSR1B
#define 	UCSRC 		UCSR1C 
#define 	UBRRL 		UBRR1L
#define 	UBRRH 		UBRR1H

#define Tx_Rx_PORT	PORTG				//wpisaŠ za x port steruj¦cy kierunkiem PD7 w mk300
#define Tx_Rx_DDR	DDRG			// jak powy¬ej
#define Tx_Rx		PG2			//x - jak powy¬ej; y - numer wyprowadzenia na porcie


char spr_ramke(void);
void answer_to_sender(void);
void usart_rec_en(void);


volatile struct{
	unsigned char nr;											//okreœla numer bajtu który ma byæ wys³any z ramka (1 - to pierwszybajt)
	unsigned int is_frame		:1;
}UART;

///////////////////////////////////////////////////////////////////////////////
void usart_ini(void){		//inicjalizacja bez odblokowania usarta i przerwa½
	UCSRC= (1<<USBS1) | (1<<UCSZ11)| (1<<UCSZ10);
	UBRRH= 0;
	//UBRRL= 71;				//z g³ównego menu
	UBRRL= 35;				//z g³ównego menu
	Tx_Rx_DDR |= (1<<Tx_Rx);
	Tx_Rx_PORT &= ~(1<<Tx_Rx);
	rozmiar=0;
	UCSRB = (1<<TXCIE) | (1<<RXCIE);
	usart_rec_en();							//odblokowanie odbiornika
	UART.nr= 0;
	sei();
}

///////////////////////////////////////////////////////////////////////////////
void usart_rec_en(void){
 UCSRB = (1<<RXEN)| (1<<RXCIE);//odblokowanie odbiornika	
}

///////////////////////////////////////////////////////////////////////////////
void usart_rec_dn(void){
	UCSRB = (1<<RXEN) | (1<<RXCIE);	//zablokowanie przerwania odbiornika
}

///////////////////////////////////////////////////////////////////////////////
void wyslij(void){
	UART.nr= 0;
	usart_rec_dn();								//zablokowanie odbiornika
	UCSRB = (1<<TXEN) | (1<<UDRIE);		//odblokowanie nadawania
	Tx_Rx_PORT |= (1<<Tx_Rx);				//TXEn485 pin na "1" czyli RS485 jako nadajnik
}

///////////////////////////////////////////////////////////////////////////////
//Przerwanie od Pustego bufora transmisji - wysy³amy nastêpn¹ lub koñczymy transmisje
ISR (USART1_UDRE_vect){
	if(UART.nr >= rozmiar){														//nie ma ju¬ nic do wys-ania
		UCSRB = (0<<UDRIE) | (1<<TXCIE);					//zablokowanie przerwania od UDRE- Bufor nadajnika pusty		
	}
	else{
		UDR= ramka[UART.nr];	
		++UART.nr;
	}
}

///////////////////////////////////////////////////////////////////////////////
//Przerwanie od Receive Komplet
ISR (USART1_RX_vect){
	char odcz;
	odcz= UDR;
	if(((rozmiar > 0))||((rozmiar == 0)&(odcz == adr))){
		ramka[rozmiar] = odcz;
		++rozmiar;
	}
	if(! spr_ramke()){
		UART.is_frame= 1;
	}
}
///////////////////////////////////////////////////////////////////////////////////
//Przerwanie od zako½czenia transmisji - no to ustawiamy sià na odbi¡r
ISR (USART1_TX_vect){
	Tx_Rx_PORT &= ~ (1<<Tx_Rx);		//TXEn485 pin na "0" czyli RS485 jako odbiornik
    UCSRB = (0<<TXCIE) | (0<<TXEN);				//zablokowanie przerwania od TXC- Transmisja kompletna
	UART.nr= 0;
	rozmiar=0;
	usart_rec_en();								//odblokowanie odbiornika
}
void answer_to_sender(void){
	unsigned short crc = 0;
	unsigned char odp = 0;
	unsigned char startMSB,startLSB,ileMSB,ileLSB,funkcja,rozkaz;
	unsigned int m,n,koniec,suma;
	
	tablica[0]=ilepasow;
	tablica[1]=z_depth;
	tablica[2]=reszta_z;
	tablica[3]=s_width;
	tablica[4]=gleb_pily;
	tablica[5]=z_abs;
	tablica[6]=y_abs;
	
	adr=ramka[0];		
	funkcja=ramka[1];
	rozkaz=ramka[1];	
	startMSB=ramka[2];	
	startLSB=ramka[3];
	ileMSB=ramka[4];
	ileLSB=ramka[5];

	n=startMSB;	
	n=n<<8; 
	n=n+startLSB;
	n=n*2;							//pocz¹tek adresu 

	suma=ileMSB;
	suma=suma<<8;
	suma=suma+ileLSB;
	suma=suma*2;					//ile bajtów		
	koniec=n+suma;					//koniec adresu

if((funkcja !=0x03)&(funkcja !=0x06)&(funkcja !=0x10)&(funkcja !=0xF0)&(funkcja !=0xF1)&(funkcja !=0xF4)&(funkcja !=0xF5)) {rozkaz=0xF2;}	//jeœli inna funkcja
if((funkcja==0x03)&(koniec>18)) {rozkaz=0xF3;}  								//jeœli pocz¹tek > ni¿ iloœæ rejestrów 8*2 
if((funkcja==0x06)&(n<8)) {rozkaz=0xF3;}
if((funkcja==0x06)&(n>16)) {rozkaz=0xF3;}

	switch(rozkaz){
		case 0xF2:	//nieprawid³owa funkcja
			odp=1;
			rozmiar=5;
			ramka[0]=adr;
			ramka[1]=funkcja+0x80;
			ramka[2]=0x01;
			break;	
		case 0xF3:	//nieprawid³owy adres
			odp=1;
			rozmiar=5;
			ramka[0]=adr;
			ramka[1]=funkcja+0x80;
			ramka[2]=0x02;
			break;
		case 0x03:	
			odp=1;
			rozmiar=2*ileLSB+5;//data + 2 bajty CRC + adr + funkcja + byte count
			ramka[0]= adr;
			ramka[1]= 0x03;		
			ramka[2]= ileLSB*2;				//byte count
				for(m=0;m<=suma;m++){
					ramka[m+3]=tablica[m+n];
				}	
			break;
		case 0x10:

			odp=1;
			rozmiar=0x06;
			ramka[0]=adr;
			ramka[1]=0x10;
			ramka[2]=0x00;				//byte count
			/*
			if (ramka[3]==0x01){
				for(m=0;m<=8;m++){
					tablica[4+m]=ramka[4+m];
				}
				s_width=tablica[4];
				gleb_pily=tablica[5];
				settings=1;
				ramka[4]=0x01;  //potwierdzenie
			}
			*/
			if (ramka[2]==0x00){
			//	for(m=0;m<=suma;m++){
				//	tablica_pasow[m]=ramka[4+m];
				//}
				templatee=1;
				settings=1;
				ramka[4]=0x01;   //potwierdzenie
			}
			break;
	}
	if(odp==1){	
		crc = ModbusCRC(ramka, rozmiar-2); 
		ramka[rozmiar-2]= crc;
		crc >>= 8;
		ramka[rozmiar-1]= crc;
		wyslij();		//odsy³amy odpowiedŸ
	}
}
////////////////////////////////////////////////sprawdza sumê kontroln¹///////////////////////////////////////
char spr_ramke(void){

unsigned short crc;
unsigned char msb,lsb;
unsigned int wynik=0;
unsigned char funkcja,ileb;
ileb=ramka[5];
funkcja=ramka[1];

if(funkcja==0x10) rozmiar2=ileb+9;  //odbior tylko poprawnych ramek
else rozmiar2=8;


if((rozmiar>7)&&(ramka[0]==adr)){

	crc = ModbusCRC(ramka, rozmiar2-2);
	lsb=crc;
	crc >>= 8;
	msb=crc;
	if (ramka[rozmiar2-2]==lsb){         	// wyzszy bajt CRC poprawny
		if (ramka[rozmiar2-1]==msb){     	// nizszy bajt CRC poprawny
			wynik=0;
			rozmiar=0;
			rozmiar2=0;
			}
		else{
			wynik=1;					//b³¹d CRC
			rozmiar2=0;
			rozmiar=0;
		}
		}
	else{
		wynik=1;		
		rozmiar2=0;			//b³¹d CRC
		rozmiar=0;
		}
		//}
	

}
else wynik=1;	//ramka nie kompletna

return wynik;
}
//CRC16 - http://www.lammertbies.nl/comm/info/crc-calculation.html?crc=75b993c3b088e57f56670d42c943b7e5&method=hex

///////////////////////////////////////////CRC/////////////////////////////////////////////////////////////////
unsigned short ModbusCRC(unsigned char * buf, int size){
   unsigned short crc = 0xffff;     
   int i;
    while(size--)   {     
		crc ^= *buf;
		buf++;
		for(i=0; i<8; i++){               
			if(crc & 1){
				crc >>= 1;
				crc ^= 0xA001;
			}
			else{
				crc >>= 1;
			}
		}     
	}     
	return crc;       
} 
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//sprawdza w g³ównej pêtli czy nie przysz³o pytanie a jak tak to inicjuje odpowiedŸ
void Transmition_check(void){
	if(UART.is_frame){
		UART.is_frame= 0;
		_delay_ms(3);	// czas potrzebny do przejscia z odbierania do nadawania
		answer_to_sender();
	}
}
