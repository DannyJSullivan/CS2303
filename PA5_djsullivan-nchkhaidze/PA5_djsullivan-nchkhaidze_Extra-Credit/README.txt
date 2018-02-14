README.txt - PA5 - Danny Sullivan & Nugzar Chkhaidze

This program is used to perform mathematical functions on whole numbers and fractions.
These different functions include +, -, *, /, <, >, <=, >=, and ==. To run this program, 
in the  directory of the files, you should type "make all" into the command line. This 
will compile the program, creating the executable file PA5. Then type into the command line
./PA5 'someFile.txt' 'someOtherFile.txt' ... where "someFile.txt" and "someOtherFile.txt"
are text files in the directory. There may be as many text files input as the user wishes,
as long as there is at least one. The program will then run through each function and 
produce an answer in the command shell. If there is an empty line in the document,
the program will produce "empty line" aligned to the left. If there is an error, such as
a character, no numbers, dividing by zero, or performing multiple functions that cannot
be performed together (such as 1 3 < 4 +), the program will produce "error" aligned to 
the right of the printed screen. Otherwise, the program will print the simplified fraction
aligned to the right, followed by that fraction in decimal form. For comparison operators, 
this program will produce either "true" or "false" aligned to the right. The stack is used to 
store the rational numbers. The stack works as in first in, last out data structure. The functions
.top(), .pop(), and .push() can all be used from this built in structure. .top() is used to get
the data at the top. .pop() is used to remove the top data from the stack. .push() adds the data 
to the stack. This stack stores the data in the form of a hashmap, where each string is assigned
a rational. 

The functions for the extra credit have been created and are located in the Rational.cpp
file. This project works with variables.