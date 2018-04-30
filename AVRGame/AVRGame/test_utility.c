/*
 * AVR GAME - UNIT TESTING
 * test_utility.c
 *
 * Created: 30.04.2018
 *  Author: Tor & Faizan
 */ 

#include "test_utility.h"
#include <stdlib.h>

static char* test_randomNumbers()
{
	bool test_fail = false;
	int i0, i1, i2, i3, i4, i5, i6, i7;
	
	utility_t* u = utility_create();
	u->level = 10000;
	u->sequence = calloc((u->level + 2), sizeof(int));
	generateRandomNumbers(u);
	
	//int i;
	for(int i = 0; i < (u->level + 2); i++)
	{
		int randomNumber = u->sequence[i];
		
		if(randomNumber == 0) i0++;
		if(randomNumber == 1) i1++;
		if(randomNumber == 2) i2++;
		if(randomNumber == 3) i3++;
		if(randomNumber == 4) i4++;
		if(randomNumber == 5) i5++;
		if(randomNumber == 6) i6++;
		if(randomNumber == 7) i7++;
		else{ 
			mu_assert("Random number not between 0 and 7", 0);
			utility_destroy(u);
			return 0;
		}
	}
	
	if(i0 <= 1200 && i0 >= 1300) test_fail = true;
	if(i1 <= 1200 && i1 >= 1300) test_fail = true;
	if(i2 <= 1200 && i2 >= 1300) test_fail = true;
	if(i3 <= 1200 && i3 >= 1300) test_fail = true;
	if(i4 <= 1200 && i4 >= 1300) test_fail = true;
	if(i5 <= 1200 && i5 >= 1300) test_fail = true;
	if(i6 <= 1200 && i6 >= 1300) test_fail = true;
	if(i7 <= 1200 && i7 >= 1300) test_fail = true;
	
	mu_assert("Numbers are not random", !test_fail);
	
	utility_destroy(u);	
	return 0;
}

static char* test_increaseLevel()
{
	utility_t* u = utility_create();
	bool test_fail = false;
	
	for(int i=2; i<10; i++)
	{
		increaseLevel(u);
		if(u->level != i) test_fail = true;		
	}
	
	mu_assert("Increase level failed", !test_fail);
	utility_destroy(u);
	return 0;
}

static char* test_resetLevel()
{
	utility_t* u = utility_create();
	
	increaseLevel(u);
	increaseLevel(u);
	increaseLevel(u);
	//Level == 4
	
	resetLevel(u);
	
	mu_assert("Reset level failed", u->level == 0);
	utility_destroy(u);
	return 0;
}

static char* test_compareValues()
{
	int a = 1, b = 1;
	
	mu_assert("a != b", compareValues(a, b));
	
	b = 2;
	mu_assert("Reset level failed", !compareValues(a, b));

	a = 3;
	mu_assert("Reset level failed", !compareValues(a, b));
	
	return 0;
}

static char* test_getInputValue()
{
	PINB = 127;
	mu_assert("Input != 7 ", getInputValue() == 7);
	
	PINB = 191;
	mu_assert("Input != 6 ", getInputValue() == 6);
	
	PINB = 223;
	mu_assert("Input != 5 ", getInputValue() == 5);
	
	PINB = 239;
	mu_assert("Input != 4 ", getInputValue() == 4);
	
	PINB = 247;
	mu_assert("Input != 3 ", getInputValue() == 3);
	
	PINB = 251;
	mu_assert("Input != 2 ", getInputValue() == 2);
	
	PINB = 253;
	mu_assert("Input != 1 ", getInputValue() == 1);
	
	PINB = 254;
	mu_assert("Input != 0 ", getInputValue() == 0);
	
	PINB = 123;
	mu_assert("Input != -1 ", getInputValue() == -1);
	
	return 0;
}


char * utility_tests()
{
	mu_run_test(test_randomNumbers);
	mu_run_test(test_increaseLevel);
	mu_run_test(test_resetLevel);
	mu_run_test(test_compareValues);
	mu_run_test(test_getInputValue);
	return 0;
}
