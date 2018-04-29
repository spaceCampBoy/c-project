/*
 * IUtility.h
 *
 * Created: 4/26/2018 9:10:49 PM
 *  Author: SpaceCampBoy
 */ 


#ifndef IUTILITY_H_
#define IUTILITY_H_
#include <stdbool.h>

typedef struct utility_t
{
	int level;
	int *sequence;
}utility_t;

utility_t* utility_create();
void utility_destroy(utility_t *self);
void generateRandomNumbers(utility_t *self);
void increaseLevel(utility_t *self);
void resetLevel(utility_t *self);
bool compareValues(int a, int b);
int getInputValue();


#endif /* IUTILITY_H_ */