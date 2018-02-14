/*
 *  tree.h
 *
 *  Created on: Feb 2, 2017
 *      Author: Nugzar Chkhaidze & Danniel Sullivan
 */

#ifndef TREE_H_
#define TREE_H_


int Total;	//used to count the total words
struct bst_vertex{ // struct for a node
	int count;
	char *node_word;

	struct bst_vertex *Left;
	struct bst_vertex *Right;
};
typedef struct bst_vertex node;	// redefining avl_vertex as node

node* add(node *now,char *word);	// adds given node and word to the tree

void  print_words(node *x);	// prints the words from the tree to the created document
							// from first left node to last right node

int compare(char *A,char*B);	// compares two strings, returns -1 if B is longer or alphabetically after
								// A, returns 1 if A is longer or alphabetically after B, returns 0 if
								// the strings are the same

#endif /* TREE_H_ */
