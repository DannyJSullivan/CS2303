/*
 *  process.h
 *
 *  Created on: Feb 2, 2017
 *      Author: Nugzar Chkhaidze & Daniel Sullivan
 */

#ifndef PROCESS_H_
#define PROCESS_H_

char* final;	// the final version of the word that is put into the node

int check(char c);	// finds the word and includes all characters, numbers, hyphens in the middle of words
					// and apostrophes

void change(char* word);	// takes in a word separated by check and removes characters at the beginning
							// and the end of that word and returns a final word

void process(char ***words,int n,int *wordsize,FILE *out);	// goes through the tree and adds the elements
															// of the tree to an array. Those elements
															// are then printed out to the new document.
															// Then, the total number of unique words and
															// the total number of words are printed out.

#endif /* PROCESS_H_ */
