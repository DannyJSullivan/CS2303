//Danny Sullivan - PA2

/*
 * life.h
 *
 *  Created on: Jan 30, 2017
 *      Author: djsully
 */

#ifndef LIFE_H_
#define LIFE_H_
#include <stdio.h>

char print, pause;

void printStep(int rows, int cols, int *oldBoard[]);
void startGame(int rows, int cols, int *oldBoard[]);
void playOne(int rows, int cols, int *oldBoard[], int *curBoard[], int gens);

#endif /* LIFE_H_ */
