#include<avr/io.h>
#include<util/delay.h>

void main()
{
unsigned char data;

DDRB=0xFF;
DDRD=0xFF;
DDRC=0x00;
PORTC=0;
while(1)
{
data=PINC;
if(data<64)
{
	PORTB=data;
	_delay_ms(10);
}
else
{
   PORTD=data;
	_delay_ms(10);
}
}

return 0;
}
