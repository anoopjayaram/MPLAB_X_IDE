/*
 * File:   10 BIT ADC 7SEG.c
 * Author: anoop
 *
 * Created on 20 April, 2022, 2:41 PM
 */

#define _XTAL_FREQ 20000000 //define crystal frequency to 20MHz
#define VREF 5  //5 Voltage
#include<pic18.h>
#include <stdio.h>
#include <math.h>

void delay(int);
unsigned char pattern[]={0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90};
void SEVEN_SEGMENT(int *arr);
void main()
{
    int i,k;
    int a,c,d,e;char str[80];
    int TEMPERATURE[3];
    float volt ,temp;int b;
    TRISA=0x0F;
    TRISC=0x00;
    TRISB=0x00;
    ADCON0=0x01;
    ADCON1=0x0D;
    ADCON2 = 0x86;  	//ADCON2=0x06; 
while(1)
{
	delay(1);
	GODONE=1;
    while(GODONE==1); 
    a=ADRESL;
    a+=(ADRESH<<8);
//	b=((a/100));
//	c=(((a%100)/10));
//	d=((a%10));
    temp=a; 
    volt=(temp/1023)*VREF;
    volt /=0.01;
 	TEMPERATURE[0]=((volt/100));
    TEMPERATURE[1]=fmod(volt,100);
    TEMPERATURE[1]=TEMPERATURE[1]/10;
    TEMPERATURE[2]=fmod(volt,10);//((volt%10));
//  TEMPERATURE[2]=TEMPERATURE[2]/10;
//     TEMPERATURE[3]=fmod(volt,10);
    SEVEN_SEGMENT(TEMPERATURE);
              

 
        
}
}

void delay(int x)
{
int i,j;
for(i=0;i<=x;i++)
for(j=0;j<=800;j++);
}
void SEVEN_SEGMENT(int *arr)
{
    
        RB4=1;            
                        PORTC = pattern[arr[0]];
                        __delay_ms(2);  
                        RB4=0;
                        
                        RB5=1;
                        PORTC = pattern[arr[1]];
                        __delay_ms(2);  
                        RB5=0;
                        
                         RB6=1;
                        PORTC = pattern[arr[2]];
                        __delay_ms(2);  
                        RB6=0;
                        
//                          RB7=1;
//                        PORTC = pattern[arr[3]];
//                        __delay_ms(2);  
//                        RB7=0;
}
