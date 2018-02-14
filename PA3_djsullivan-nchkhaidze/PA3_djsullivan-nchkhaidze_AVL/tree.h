/*
 *  tree.h
 *
 *  Created on: Feb 2, 2017
 *      Author: Nugzar Chkhaidze & Daniel Sullivan
 */

#ifndef TREE_H_
#define TREE_H_


int Total;	//used to count the total words
struct avl_vertex{	// struct for a node
	int count,height;
	char *node_word;

	struct avl_vertex *Left;
	struct avl_vertex *Right;
};
typedef struct avl_vertex node; // redefining avl_vertex as node

node* add(node *now,char *word);	// adds given node and word to the tree

void  print_words(node *x);	// prints the words from the tree to the created document
							// from first left node to last right node

int compare(char *A,char*B);	// compares two strings, returns -1 if B is longer or alphabetically after
								// A, returns 1 if A is longer or alphabetically after B, returns 0 if
								// the strings are the same

node *rightRotate(node *y);	// A utility function to right rotate subtree rooted with y

node *leftRotate(node *x);	// A utility function to left rotate subtree rooted with x

int getBalance(node *N);	// Get Balance factor of node N, returns height left minus height right

int height(node *N);		// returns the height of the tree

#endif /* TREE_H_ */
