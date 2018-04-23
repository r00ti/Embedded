//created by Barcella Pietro
#include <xc.h>
#include "ADC_lib.h"
extern void adc_setup(char lines){
lines=lines%8;
lines=15-lines;
ADCON1=lines;
ADON=1;
ADFM=1;
}
extern void adc_ext_up_voltage(char sel){
VCFG0=sel;
}
extern void adc_ext_do_voltage(char sel){
VCFG1=sel;
}
extern int adc_read(char chan){
    int res;
ADCON0=ADCON0%4;
ADCON0=ADCON0+(chan<<2);
GODONE=1;
while(GODONE);
res=ADRESL+(ADRESH<<8);
return res;
}

