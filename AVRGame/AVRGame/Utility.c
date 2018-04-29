/*
 * Utility.c
 *
 * Created: 4/26/2018 9:44:22 PM
 *  Author: SpaceCampBoy
 */ 

#include "IUtility.h"
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
#include <avr/io.h>
#include <unistd.h>

utility_t* utility_create()
{	
	utility_t* new_utility = (utility_t*)malloc(sizeof(struct utility_t));
	new_utility->level = 1;
	new_utility->sequence = calloc((new_utility->level + 2), sizeof(int));
	return new_utility;
}

void utility_destroy(utility_t *self)
{
	free(self);
}

int randomNumber()
{
	
	int n = rand() % 8;
	printf(" %d", n);
	return n;
	
}

void generateRandomNumbers(utility_t *self)
{
	int *sequence = self->sequence;
	int i;
	for(i = 0; i < (self->level + 2); i++)
	{
		sequence[i] = randomNumber();
	}
}

void increaseLevel(utility_t *self)
{
	self->level++;
	free(self->sequence);
	self->sequence = calloc((self->level + 2), sizeof(int));
}

void resetLevel(utility_t *self)
{
	self->level = 0;
	free(self->sequence);
	self->sequence = calloc((self->level + 2), sizeof(int));
}

bool compareValues(int a, int b)
{
	if(a == b)
	{
		return true;
	}
	return false;
}

int convertPINBValue(int value)
{
	if(value == 127)
	{
		return 7;
	}
	else if (value == 191)
	{
		return 6;
	}
	else if (value == 223)
	{
		return 5;
	}
	else if (value == 239)
	{
		return 4;
	}
	else if (value == 247)
	{
		return 3;
	}
	else if (value == 251)
	{
		return 2;
	}
	else if (value == 253)
	{
		return 1;
	}
	else if (value == 254)
	{
		return 0;
	}
	else
	{
		return -1;
	}
}

int getInputValue()
{	
	while(PINB == 0xFF){}
	int m = PINB;
	m = convertPINBValue(m);
	printf("PINB %d", m);
	return m;
}

