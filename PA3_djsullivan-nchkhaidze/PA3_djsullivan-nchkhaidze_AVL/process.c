/*
 *  process.c
 *
 *  Created on: Feb 2, 2017
 *      Author: Nugzar Chkhaidze & Danniel Sullivan
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "process.h"
#include "tree.h"

node* root;
char* final;
int unique_words;
int check(char c){
	return (('a'<=c && c<='z') ||
			   ('A'<=c && c<='Z') ||
			   ('0'<=c && c<='9'));
}
void change(char* word){
	free(final);
	int len=strlen(word);
	if(len==0)return;
	int counter1=-1,counter2=-1;

	for(int i=0;i<len;i++){	// goes through document, checks for words, adds counter for every word
		if(check(word[i])){
			counter1=i;
			break;
		}
	}
	for(int i=len-1;i>=0;i--){	// goes through document a second time, checks if any words were removed
		if(check(word[i])){
			counter2=i;
			break;
		}
	}
	final=(char*)malloc((counter2-counter1+1)*sizeof(char));

	if(counter1==-1 || counter2==-1){word[0]='\0';return ;}
	int n=0;

	for(int i=counter1;i<=counter2;i++){	// makes all the words in document lower case
		final[n++]=tolower(word[i]);
	}
	final[n]='\0';
	for(int i=0;i<=n;i++)word[i]=final[i];	// adds all the words (now changed) to a final array
	return;
}
void process(char ***words,int n,int *wordsize,FILE *out){
	for(int i=0;i<n;i++){
		for(int j=0;j<wordsize[i];j++){	// adds all the elements from the array to root
			root=add(root,words[i][j]);
		}
	}
	print_words(root);
	fprintf(out,"-------------\n");
	fprintf(out,"%6d\t",unique_words);
	fprintf(out,"Distinct words\n");

	fprintf(out,"%6d\t",Total);
	fprintf(out,"Total words counted (including duplicates)\n");
	fprintf(out,"%d\n",getBalance(root));
}
