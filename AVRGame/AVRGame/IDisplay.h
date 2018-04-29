/*
 * IDisplay.h
 *
 * Created: 4/26/2018 10:02:56 AM
 *  Author: SpaceCampBoy
 */ 


#ifndef IDISPLAY_H_
#define IDISPLAY_H_

typedef struct display_t * display_t;
display_t display_create();
void display_destroy(display_t self);

void displayRandomSequence(int *sequence, int level);
void displayWelcomeSequence();
void displayRoundWon();
void displayGameLost();
void displayGameWon();
void displaySingleValue(int value);
void displayLevel(int level);
void displaySequenceEnd();

#endif /* INCFILE1_H_ */