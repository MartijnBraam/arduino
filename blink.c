#include <avr/io.h>
#include <avr/interrupt.h>

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
	PORTB = 255;
	PORTC = 255;
	PORTD = 255;
}

ISR(TIMER1_COMPB_vect)
{
	PORTB = 0;
	PORTC = 0;
	PORTD = 0;
}


int main(void)
{
	init_io();
	init_timers();

	while (1)
	{
	}

	return 0;
}
