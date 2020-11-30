#include<avr/io.h>
#include<util/delay.h>

void main()
{
unsigned char data;

DDRB=0xFF;
DDRC=0x00; // DDRC&=(~(1<<0))|(~(1<<1))

while(1)
{
if(PINC&0b11011111)// if(PINC&(1<<5)), read Vcc input from switch
	{ 				// if(!(PINC&(1<<5))), read ground from switch at that time PORTB|=(1<<5)
	PORTB=0x55;
	_delay_ms(10);
	}
else 
	{
	PORTB=0xAA;
	_delay_ms(10);
	}
}
return 0;
}
