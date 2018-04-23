#ifndef ADC_LIBH
#define ADC_LIBH
//created by Barcella Pietro
//to use on a PIC18F4580 devices, other compatibilities not checked
//this is a simplified library that contains functions to use the ADC converter in pics
//to setup the adc, you can select how many channels you want by modifyng lines;
void adc_setup(char lines);
// call this function to use or not the upper reference voltage, seto sel to 0 if not(it use the supply voltage),else yes
void adc_ext_up_voltage(char sel);
// call this function to use or not the lower reference voltage, seto sel to 0 if not(it use the ground voltage),else yes
void adc_ext_do_voltage(char sel);
// this function returns the voltage red on the channel chan, providing a number from 0 to 1024,
// that number multiplied per delta voltage frome the references, divided by 1024 and to it summed the lower reference voltage, can give you the actual voltage
int adc_read(char chan);
#endif // ADC_LIB
