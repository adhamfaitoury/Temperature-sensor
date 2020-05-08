/* 
 * File:   main.c
 * Author: M3MO
 *
 * Created on 07 ????, 2020, 04:57 ?
 */

#define F_CPU 16000000UL
#include <xc.h>
#include <avr/interrupt.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"DIO.h"
#include"CONFIG.h"
#include"myADC.h"
#include "lcd.h"


#define ADC0  0
#define AREF 0
#define AVCC 1
#define Internalref 3

int temp;
char str[]="Temp=";
char str2[]="C";
char cl[]="   ";

ISR(ADC_vect){
    ADC_read(&temp);
    temp *=4.9; //1 degree is 4.9 mv
    temp /=10;// in oC
    
    char buffer[20];
    itoa(temp,buffer,10);
    LCD_String_xy(0, 7, cl);
    LCD_String_xy(0, 7, buffer);
    _delay_ms(100);
    ADC_STConv(); //start conversion;
}



int main(void) {
    LCD_Init();
    PORTCas(OUT);
    PORTDas(OUT);
    ADC_init(ADC0,AREF);
    sei();
    LCD_String_xy(0, 0, str);
    LCD_String_xy(0, 10, str2);

   ADC_STConv();

    
    while(1){
        PORTC = (char) temp;
        PORTD = (char) (temp>>8);
       
    }
    return 0;
}
