This program simulates a predator-prey relationship between doodlebugs and ants. The
doodlebugs eat the ants. If the doodblebugs do not eat an ant within 3 turns, it dies.
If the doodlebug survives 8 turns, it breeds. If an ant survives 3 turns, it breeds.
Both organisms move to a new location every turn if they are able to. However, if there
is nowhere to move, the organism does not move. If the organism is able to breed but is
surrounded, it waits until there is an open position and will move and then give birth. 
All organisms will move before giving birth. Doodlebugs will move before ants, therefore
can eat ants before their turn begins. Doodlebugs will also give birth before ants. To 
run this program, you must go to the file directory in the terminal and type "make all". 
This will make the executable. Then you must type "./PA6 gridSize #doodlebugs #ants 
#time_steps seed pause" where all the variables are expecting integer values. The grid
size creates a square grid using the integer value given there. The #doodlebugs and 
#ants is the integer value of the number of doodlebugs and ants on the grid. #time_steps
is the number of steps of the simulation in an integer value that are gone through. The
seed indicates the seed for the random number used to place the ants and doodlebugs. If 
it is 0, it defaults to 1. Pause is an optional argument. If it is zero or blank, the 
grid will not print or pause. If a nonnegative integer is placed there, then it will
print all grids for how ever many steps the integer is and then will pause and require
a keystroke.