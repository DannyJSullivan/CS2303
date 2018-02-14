Danny Sullivan and Nugzar Chkaidze - PA3 README.txt

This program is run by typing "make all" in the directory to build the project. Then, type "./PA3" followed by the
name of the text file you wish to create and where your output will be saved, followed by input files as many as you wish. 
The program will then open up each file and read all the words using fscanf. It will exclude periods, exclamation points, 
question marks, and other symbols that are not part of the word. Hyphens (combining two words) and apostrophes will be left in. 
Each word is stored in a node of a binary search tree. If the next word is alphabetically earlier than the previous, then
the word will go down the left node and be placed there. If that word comes after the compared word alphabetically,
it will go to the right node and be placed there. If the same word is encountered in the text file, it will be found in a tree 
and the counter of the node will be incremented. If it is not, it will follow the previous rules to find a place to place the word and
create a new node. The program does this for all the text files given. The words are then printed to the text 
document that is created in alphabetical order, from the first left node to the final right node. Beside each word,
the amount of time the word was counted is written. The total number of distinct words and the total number of words
are then printed out under all the words and their frequencies. Our code expects that punctuation is correct with proper
white spaces and therefore will not handle words such as "some...words" or "Moby,Dick" because it does not have white space. 
It will consider those as one word. 


bst.c
	Argc is total number of arguments, arg[1] is output file. So there are ar-2 input files.
	We store input files in in[] array (first file starting from zero index).
	Using for loop we go through each input file.
		The first while loop counts number of words. Then creates that number of char arrays in word[i]
		Does rewind, fscanf-s words again and stores them in word[i][j]-s, where i-is input files number
		and j is stands for j-th word in i-th input file.
		Both while loops break when fscanf returns 0, as fscanf returns number of input items, if fscanf-s 
		returned number is not 1 it means all words in i-th file has been scanned.
		change function parses the string from the beginning and from the end, and returns what is left in the middle.
		if all symbols where 'bad' symbols our code will not add an empty word in array, rather continue.
	Next our code calls function process.
		Function process goes through all words in words[i][j] and using function add adds them in BST.
	Next print_words is called which traverses the whole BST and print words in alphabetical order with their number of occurrences.
	Finally number of distinct words (number of nodes in BST) and total number of words including duplicates are printed.
	tree.c contains a function compare which is needed during add-function to locate in its right place.
	All nodes have words alphabetically less in its left subtree, and bigger words in its right subtree.
	
	structure node has int count, which is number of occurrences of the word in all input files.
	char * node_word is the actual word. And struct bst_vertex *Left struct bst_vertex *Right left and right child nodes.
	