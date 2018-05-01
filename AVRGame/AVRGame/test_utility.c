/*
 * AVR GAME - UNIT TESTING
 * test_utility.c
 *
 * Created: 30.04.2018
 *  Author: Tor & Faizan
 */ 

#include "test_utility.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

static char* test_randomNumbers()
{
	bool test_fail = false;
	int i0=0, i1=0, i2=0, i3=0, i4=0, i5=0, i6=0, i7=0;
	


	//Level is increase to 1000 and the sequence array is filled with random numbers.
	utility_t* u = utility_create();
	u->level = 1000;
	u->sequence = calloc((u->level + 2), sizeof(int));
	generateRandomNumbers(u);

	//int i;
	for(int i = 0; i < (u->level + 2); i++)
	{
		int randomNumber = u->sequence[i];
		
		if(randomNumber == 0) i0++;
		else if(randomNumber == 1) i1++;
		else if(randomNumber == 2) i2++;
		else if(randomNumber == 3) i3++;
		else if(randomNumber == 4) i4++;
		else if(randomNumber == 5) i5++;
		else if(randomNumber == 6) i6++;
		else if(randomNumber == 7) i7++;
		else{
			mu_assert("Random number not between 0 and 7", 0);
			utility_destroy(u);
			return 0;
		}
	}

	//Checking that the random numbers are equally distributed between the numbers 0 and 7.
	if(i0 <= 100 && i0 >= 150) test_fail = true;
	if(i1 <= 100 && i1 >= 150) test_fail = true;
	if(i2 <= 100 && i2 >= 150) test_fail = true;
	if(i3 <= 100 && i3 >= 150) test_fail = true;
	if(i4 <= 100 && i4 >= 150) test_fail = true;
	if(i5 <= 100 && i5 >= 150) test_fail = true;
	if(i6 <= 100 && i6 >= 150) test_fail = true;
	if(i7 <= 100 && i7 >= 150) test_fail = true;
	
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
	
	mu_assert("Reset level failed", u->level == 1);
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

char * utility_tests()
{
	mu_run_test(test_randomNumbers);
	mu_run_test(test_increaseLevel);
	mu_run_test(test_resetLevel);
	mu_run_test(test_compareValues);
	return 0;
}
