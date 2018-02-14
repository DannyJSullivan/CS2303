//Danny Sullivan - PA2

#include <stdio.h>
#include <stdlib.h>
#include "life.h"

int rows, cols;
int gens;
char pause, print;

int main(int argc, char *argv[]) {
	FILE *f;

	rows = atoi(argv[1]);
	cols = atoi(argv[2]);
	gens = atoi(argv[3]);
	f = fopen(argv[4], "r");
	print = argv[5][0];
	pause = argv[6][0];

	if(argc < 7) {
		printf("Not enough arguments.\n");
		return 0;
	}
	if(argc > 7) {
		printf("Too many arguments.\n");
		return 0;
	}
	if(rows <= 0) {
		printf("Not enough rows.\n");
		return 0;
	}
	if(cols <= 0) {
		printf("Not enough columns.\n");
		return 0;
	}
	if(!f) {
		printf("Invalid input file.\n");
		return 0;
	}

	int **curBoard = (int **)malloc(sizeof(int*)*rows);
	for(int i = 0; i < rows; i++) {
		curBoard[i] = (int*)malloc(cols * sizeof(int));
	}

	int c;
	int curRow = 0;
	int curCol = 0;

	while(1) {
		c = fgetc(f);

		if(feof(f)) {
			break;
		}

		if(c == 13) {
			continue;
		}

		if(c == '\n') {
			curRow++;
			curCol = 0;
		}
		else {
			curBoard[curRow][curCol] = (c == 'x');
			curCol++;
		}
	}

	printStep(rows, cols, curBoard);

	playOne(rows, cols, curBoard, curBoard, gens);

	for(int i = 0; i < rows; i++) {
		free(curBoard[i]);
	}

	free(curBoard);

	return 0;
}
