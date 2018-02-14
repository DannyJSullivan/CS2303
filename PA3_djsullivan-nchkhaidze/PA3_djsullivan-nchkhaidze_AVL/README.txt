Danny Sullivan and Nugzar Chkaidze - PA3 README.txt

This program is run by typing "make all" in the directory to build the project. Then, type "./PA3" followed by the
name of the text file you wish to create, followed by as many other text files as you wish. The program will then 
open up each file and read all the words. It will exclude periods, exclamation points, question marks, and other
parts of words that are part of the word. Hyphens (combining two words) and apostrophes will be left in. Each word
is stored in a node of a binary search tree. If the next word is alphabetically earlier than the previous, then
the word will go down the left node and be placed there. If that word comes after the compared word alphabetically,
it will go to the right node and be placed there. If the same word is encountered in the text file, the counter of
the node will be incremented. If it is not, it will follow the previous rules to find a place to place the word and
create a new node. The program does this for all the text files given. The words are then printed to the text 
document that is created in alphabetical order, from the first left node to the final right node. Beside each word,
the amount of time the word was counted is written. The total number of distinct words and the total number of words
are then printed out under all the words and their frequencies. Our code expects that punctuation is correct with proper
white spaces and therefore will not handle words such as "some...words" or "Moby,Dick" because it does not have white space. 
It will consider those as one word. 