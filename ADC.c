#include <xc.h>


void selectChannel(unsigned int channelNo) { // 0~7
    if (channelNo < 8) { // 00000001| 00000000
        ADMUX &= ~(7 << 0); // 00000111  11111000
        ADMUX |= channelNo;
    } else {
        //# warning ""
    }
}
void ADC_init_0() {
    ADMUX = 0x00; // Channel 0
    SFIOR |= (1<<ADTS1);
    ADCSRA |= (1 << ADEN) | (1<<ADATE)|(1 << ADIE) | (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);
    
}
void ADC_init_1() {
    ADMUX = 0x01; // Channel 1
    SFIOR |= (1<<ADTS1);
    ADCSRA |= (1 << ADEN) | (1<<ADATE)|(1 << ADIE) | (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);
    
}


void startConv() {
    ADCSRA |= (1 << ADSC);
}

int getADCdata() {
    int data = 0;
    data = ADCL;
    data |= (ADCH << 8);

    return data;
}

int getADCdataL() {
    int data = 0;
    data = (ADCH << 2);
    return data;
}
