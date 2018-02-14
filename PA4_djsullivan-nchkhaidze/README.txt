README.txt for PA4 - Nugzar Chkhaidze & Daniel Sullivan

This program runs a simulation on a bank throughout a given amount of time, 
tellers, customers, and an optional average transaction time. It creates a 
new document (a.out) with all the statistics reported, such as number of 
customers and tellers, total simulation time, average transaction time, total 
idle time and times idle for tellers, and the total time spent in the bank and 
average waiting time for customers. All time in the program is based on seconds. 
The program runs a simulation for two different kinds of lines. The first runs
the simulation for one line of customers. The second runs for a line of 
customers for every teller. To run the program, the file must be made. To do 
this, in the Linux command shell, type "make all" in the directory with the
program. Then, type ./qSim followed by the number of customers (int), the number
of tellers(int), the length of the desired simulation(int), and optionally an 
average transaction time (double). Idle time for the tellers is randomized 
from 1-500 seconds and transaction time is randomized from 1-600 seconds. 
These numbers are then used in both simulations and printed out at the end in 
a separate text file. 

We are using a class of customer and tellers as subclasses of the class Event.
They are united in the Event class. We also have EventQueue and TellerQueue
which are used to store the data using priority queue. Virtual functions
are used for the objects that have different subclass functions which should
be treated differently. 

Our code uses priority queue to store the data. Inserting and
retrieving an object in the priority queue takes O(logn)operations. 
If we used a linked list, it would take a linear time to add a single object 
to the list. Therefore, using priority queue is more efficient than using a 
linked list.