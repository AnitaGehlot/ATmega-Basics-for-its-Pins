#include<avr/io.h>
#include<util/delay.h>

void main()
{
unsigned char data;

DDRB=0xFF;
DDRC=0x00; // DDRC&=(~(1<<0))|(~(1<<1))
DDRC=0x00;
while(1)
{
if(PINC&0b11011111)// if(PINC&(1<<5)), read Vcc input from switch
	{ 				// if(!(PINC&(1<<5))), read ground from switch at that time PORTB|=(1<<5)
	DDRB=DDRB&~(1<<5);
	if(PIND&0b11011111)
	{
	PORTB=1;
	}
	else
	PORTB=0;
}
	
else 
	{
	DDRB=DDRB|(1<<5);
	
	PORTB=2;
	
	}
	}
return 0;
}
