#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

void init_io(void)
{
	// 1 = output, 0 = input
	DDRB = 0b11111111; // All outputs
	DDRC = 0b11111111; // All outputs
	DDRD = 0b11111110; // PORTD (RX on PD0). Just for demo
}

void init_timers(void)
{
	OCR1A = 53333;
	OCR1B = 10000;
	TIMSK1 = (1<< OCIE1A)| (1<< OCIE1B);

	TCCR1B = (1<<WGM12)|(1<<CS10);
	sei();
}

ISR(TIMER1_COMPA_vect)
{	
	PORTB |= (1 << PB5);
}

ISR(TIMER1_COMPB_vect)
{
	PORTB &= ~(1 << PB5);
}


int main(void)
{
	init_io();
	init_timers();
	uint8_t dir = 0;
	
	while (1)
	{	
		if(dir>0){
			OCR1B++;
			if(OCR1B == OCR1A){
				dir = 0;
			}
		}else{
			OCR1B--;
			if(OCR1B==0){
				dir = 1;
			}
		}
		_delay_us(10);
		
	}

	return 0;
}
