#include <xc.h>
#include <avr/interrupt.h>

#define ADC0  0
#define AREF 0
#define AVCC 1
#define Internalref 3

void ADC_read(int *pdata){
    *pdata = ADCL;
    *pdata |= (ADCH<<8);
    
}

void ADC_init(char channel,char ref ){
     ADMUX=(channel<<0)|(ref<<6);
     ADCSRA=0x8F; 
}

void ADC_STConv(){
    //Start Conversion
     ADCSRA |=(1<<ADSC);
}
