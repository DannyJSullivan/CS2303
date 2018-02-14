/*
 *  bst.c
 *
 *  Created on: Feb 2, 2017
 *      Author: Nugzar Chkhaidze & Danniel Sullivan
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "process.h"
extern int Total;
FILE *out;
FILE **in;
int main(int argc, char *argv[]) {

	out=fopen(argv[1],"w");
	in=malloc((argc-2)*sizeof(FILE));

	for(int i=2;i<argc;i++){	// opens the files to read, stores in in-array
		in[i-2]=fopen(argv[i],"r");
	}
	char *word;
	word=malloc(10000*sizeof(char));

	char ***words=(char ***)malloc(sizeof(char**)*(argc-2));
	int *wordsize=malloc(sizeof(int)*(argc-2));

	for(int i=0;i<argc-2;i++){	// runs through input files
		int counter=0,p=1;
		while(1){	// scans for individual words and counts the number of words
			p=fscanf(in[i],"%s",word);// fscanf returns number of scanned variables
			if(p!=1)break;// when nothing is scanned, loop breaks
			change(word);

			if(word[0]!='\0')
				{counter++;Total++;}
		}
		words[i]=(char **)malloc(sizeof(char*)*counter);// creates char array for input words
		wordsize[i]=counter;
		rewind(in[i]);// rewinds to scan words again and store it in array

		int N=0;
		p=1;
		while(1){	// scans the word, removes extraneous characters and adds the word to an array
			p=fscanf(in[i],"%s",word);

			if(p!=1)break;

			change(word);
			if(word[0]=='\0')continue;

			N++;
			words[i][N-1] = strdup(word);
		}
	}
	process(words,argc-2,wordsize,out);

	for(int i=0;i<argc-2;i++){			// frees space of [i] in words
		for(int j=0;j<wordsize[i];j++)	// frees space of [j] in words[i]
			free(words[i][j]);
		free(words[i]);
	}
	free(words);free(word);free(wordsize);

	for(int i=0;i<argc-2;i++)	// frees [i] in in
		free(in[i]);
	free(in);
	free(final);

	return 0;
}
