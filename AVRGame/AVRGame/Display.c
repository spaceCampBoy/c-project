/*
 * Display.c
 *
 * Created: 4/26/2018 10:10:41 AM
 *  Author: SpaceCampBoy
 */ 
#define F_CPU	10000000L	// processor speed 10MHz
#include "IDisplay.h"
#include <avr/io.h>
#include <stdio.h>
#include <util/delay.h>
#include <stdlib.h>

struct display_t
{};
	
	
display_t display_create()
{	display_t new_display = (display_t)malloc(sizeof(struct display_t));
	return new_display; 
}

void display_destroy(display_t self)
{
	free(self);
}

void all_led_on()
{
	DDRA = 0xFF;
	PORTA = 0x00;
	return;
}

void all_led_off()
{
	DDRA = 0xFF;
	PORTA = 0xFF;
	return;
}

void led_on(int led_no)
{
	DDRA = 0xFF;
	PORTA = 0xFF;
	PORTA &= ~(1<<led_no);
	return;
}

void led_off(int led_no)
{
	DDRA = 0xFF;
	PORTA = 0xFF;
	PORTA |= ~(1<<led_no);
	return;
}

void displayRandomSequence(int *sequence, int level)
{
	int i;
	for(i = 0; i < (level + 2); i++)
	{
		displaySingleValue(sequence[i]);
	}
}

void displayWelcomeSequence()
{
	for(int i=0; i<5; i++)
	{
		all_led_on();
		_delay_ms(300);	// delay
		all_led_off();
		_delay_ms(300);	// delay
	}
}

void displayRoundWon()
{
	for(int i=0; i<3; i++){
		for(int j=0; j<8; j++){
			led_on(j);
			_delay_ms(100);	// delay
		}
	}
}

void displayGameLost()
{
	for(int i=0; i<10; i++)
	{
		all_led_on();
		_delay_ms(500);	// delay
	}
}


void displayGameWon()
{
	DDRA = 0xFF;
	for(int i=0; i<15; i++){
		for(int j=0; j<=8; j++){
			PORTA = ~(1 << j) & ~(1 << (7-j));
			_delay_ms(50);
		}
	}
	PORTA = 0xFF;
}

void displaySingleValue(int value)
{
	led_on(value);
	_delay_ms(500);	// delay
	led_off(value);
	_delay_ms(500);	// delay
}

void displaySequenceEnd()
{
	all_led_on();
	_delay_ms(500);	// delay
	all_led_off();
	_delay_ms(500);	// delay
}

void displayLevel(int level)
{
	while(PINB == 0xFF)
	{
		displaySingleValue((level-1));
	}
}