/*
 * AVRGame.c
 *
 * Created: 19.04.2018 11:34:44
 * Author : Tor
 */ 

#include <avr/io.h>
#include <stdio.h>
#include <util/delay.h>

int main(void)
{
	timerFinishedSequence();
    /* Replace with your application code */
    while (1) 
    {
		
    }
	
}

void displayGameWonSequence(){
	DDRA = 0xFF;
	for(int i=0; i<10; i++){
		for(int j=0; j<=8; j++){
			PORTA = ~(1 << j) & ~(1 << 7-j);
			_delay_ms(350);
		}
	}
	PORTA = 0xFF;
}

