/*
 * AVR GAME - UNIT TESTING
 * test.c
 *
 * Created: 30.04.2018
 *  Author: Tor & Faizan
 */ 
#ifdef TEST

#define F_CPU 10000000L

#include <util/delay.h>
#include "minunit.h"
#include "test_utility.h"

#include <avr/io.h>
#include <stdio.h>
#include <avr/interrupt.h>
#include "atmega2560_drivers.h"
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

static char * all_tests()
{
	mu_run_suite(utility_tests);
	return 0;
}

int main()
//int main(void)
{
	    init_stdio(0, 10000000L);
	    sei();
	    printf("Initiating AVR GAME Unit Test...\n");
		
		char *result = all_tests();
		if (result != 0) {
			printf("Error: %s\n", result);
		}
		else {
			printf("ALL UTILITY TESTS PASSED\n");
		}
		
		return 0;
}
#endif