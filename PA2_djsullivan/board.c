//Danny Sullivan - PA2

#include <stdio.h>
#include <stdlib.h>
#include "life.h"

//char print, pause;

void printStep(int rows, int cols, int *oldBoard[]) {
	for(int i = 0; i < rows; i++) {
		for(int j = 0; j < cols; j++) {
			if(oldBoard[i][j] == 1) {
				printf("x");
			}
			else {
				printf("o");
			}
		}
		printf("\n");
	}
}

void playOne(int rows, int cols, int *oldBoard[], int *curBoard[], int gens) {
	int **newBoard = (int **)malloc(sizeof(int*)*rows);
	int **sur = (int **)malloc(sizeof(int*)*rows);


	if(gens == 0) {
		return;
	}

	for(int i = 0; i < rows; i++) {
		newBoard[i] = malloc(cols * sizeof(int));
	}

	for(int i = 0; i < rows; i++) {
		sur[i] = malloc(cols * sizeof(int));
	}

	for(int i = 0; i < rows; i++) {
		for(int j = 0; j < cols; j++) {
			newBoard[i][j] = sur[i][j] = 0;
		}
	}

	for(int i = 0; i < rows; i++) {
		for(int j = 0; j < cols; j++) {
			if(curBoard[i][j]) {
				if(i > 0) {
					sur[i - 1][j]++;
				}
				if(j > 0) {
					sur[i][j - 1]++;
				}
				if(i + 1 < rows) {
					sur[i + 1][j]++;
				}
				if(j + 1 < cols) {
					sur[i][j + 1]++;
				}
				if(i && j) {
					sur[i - 1][j - 1]++;
				}
				if(i && (j + 1 < cols)) {
					sur[i - 1][j + 1]++;
				}
				if((i + 1 < rows) && j) {
					sur[i + 1][j - 1]++;
				}
				if((i + 1 < rows) && (j + 1 < cols)) {
					sur[i + 1][j + 1]++;
				}
			}
		}
	}

	for(int i = 0; i < rows; i++) {
		for(int j = 0; j < cols; j++) {
			if(sur[i][j] <= 1 || sur[i][j] >= 4) {
				newBoard[i][j] = 0;
			}
			else if(!curBoard[i][j] && sur[i][j] == 3) {
				newBoard[i][j] = 1;
			}
			else if(curBoard[i][j]) {
				newBoard[i][j] = 1;
			}
			else {
				newBoard[i][j] = 0;
			}
		}
	}

	int er1 = 0;
	int er2 = 0;
	int er3 = 0;

	for(int i = 0; i < rows; i++) {
		for(int j = 0; j < cols; j++) {
			if(curBoard[i][j] != newBoard[i][j]) {
				er1 = 1;
			}
		}
	}

	for(int i = 0; i < rows; i++) {
		for(int j = 0; j < cols; j++) {
			if(oldBoard[i][j] != newBoard[i][j]) {
				er2 = 1;
			}
		}
	}

	for(int i = 0; i < rows; i++) {
		for(int j = 0; j < cols; j++) {
			if(newBoard[i][j] > 0) {
				er3 = 1;
			}
		}
	}

	if(!er1 || !er2 || !er3) {
		exit(0);
	}
	if(print == 'y') {
		getchar();
	}

	if(print == 'y') {
		printStep(rows, cols, newBoard);
	}

	if(pause == 'n') {
		printf("\n");
	}
	for(int i = 0; i < rows; i++) {
		free(sur[i]);
	}

	free(sur);

	playOne(rows, cols, curBoard, newBoard, gens - 1);

	for(int i = 0; i < rows; i++) {
		free(newBoard[i]);
	}

	free(newBoard);
}
