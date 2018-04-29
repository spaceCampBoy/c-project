/*
 * AVRGame.c
 *
 * Created: 19.04.2018 11:34:44
 * Author : Tor
 */ 

#include <avr/io.h>
#include <stdio.h>
#include "IDisplay.h"
#include "IUtility.h"
#include <avr/interrupt.h>
#include "atmega2560_drivers.h"
#include <stdlib.h>
#include <time.h>


int main(void)
{
	init_stdio(0, 10000000L);
	sei();
	PINB = 0;
	srand (time(NULL));
	utility_t* u;
	
    while(1) //Game Main Loop
    {
		u = utility_create();
		displayWelcomeSequence();
		bool gameLost = false;
		
		while(!gameLost)
		{
			displayLevel(u->level);
			printf("\n");
			generateRandomNumbers(u);
			displayRandomSequence(u->sequence, u->level);
			displaySequenceEnd();
			
			for(int i = 0; i < (u->level + 2); i++)
			{
				int a = u->sequence[i];
				int b = getInputValue();
				displaySingleValue(b);
				if(!compareValues(a,b))
				{
					displayGameLost();
					gameLost = true;
					break;
				}
			}
			if(gameLost)
			{
				break;
			}
			displayRoundWon();
			if(u->level == 8)
			{
				displayGameWon();
				break;
			}
			increaseLevel(u);
			
		}
		
		
		
    }
	
}

