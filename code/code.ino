/*
 * Smart Water Tank Refill System.c
 *
 * Created: 8/31/2026 10:38:37 PM
 * Author : HP
 */ 
#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	// Configure pins
	DDRC &= ~(1 << PC3);   // PC3 as input (float switch)
	PORTC |= (1 << PC3);   // Enable pull-up resistor

	DDRD |= (1 << PD2) | (1 << PD4);  // PD2 (LED) and PD4 (Relay) as outputs

	while (1)
	{
		// Read float switch
		if (!(PINC & (1 << PC3)))     // Switch closed (tank full)
		{
			PORTD &= ~(1 << PD4);     // Relay OFF (pump OFF)
			PORTD &= ~(1 << PD2);     // LED OFF
		}
		else                          // Switch open (tank low)
		{
			PORTD |= (1 << PD4);      // Relay ON (pump ON)
			PORTD |= (1 << PD2);      // LED ON
		}
		_delay_ms(100);
	}
}

