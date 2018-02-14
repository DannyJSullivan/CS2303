/*
 * teller.cpp
 *
 *  Created on: Feb 13, 2017
 *      Author: Nugzar Chkhaidze & Daniel Sullivan
 */

#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

#include "teller.h"
#include "event.h"

extern TellerQueue tell_queue;
extern TellerQueue* tell_queues;
extern EventQueue *eq;
extern int Total_time;
extern int Total_idle_time;
extern int Times_idle;
extern int Total_trans_time;
extern int tellers;
extern int* cust_in_line;
extern int simulation_time;
void Teller::Action(){

	tell_queue.thequeue.push(this);

}
void Teller::Action2(){

	if(cust_in_line[lineNumber]==0)
	{
		int flag=0;
		for(int i=0;i<tellers;i++){// go thru teller lines
			if(cust_in_line[i])
				flag=1;	// set flag if customers are in line
		}//end for


		if(!flag){
			this->addtimeto(this->getidle());  // goes idle
			Total_idle_time+=this->getidle();
			Times_idle++;

			if(this->gettime()<=simulation_time)
						eq->ADD(this);
		}else{

				/// gets customer from other line
			int maximum=0,num_of_max=0;

			for(int i=0;i<tellers;i++)
				if(cust_in_line[maximum]<cust_in_line[i])  // find the index of the line
					maximum=i;							// with maximum number of customers

			for(int i=0;i<tellers;i++)					// find number of maximums
			if(cust_in_line[maximum]==cust_in_line[i])
					num_of_max++;

			int randnum=rand()%num_of_max;  // random in which line the customer should go

			for(int i=0;i<tellers;i++)       // add the customer in randnum-th line
				if(cust_in_line[maximum]==cust_in_line[i]){
					if(randnum==0){
						process_transaction(i);  // process transaction from line i
						break;
					}
					randnum--;
				}
			}// end if/else

		return;
	}//end if(cust_in_line...)

	process_transaction(lineNumber); // process transaction from line i


}// end action2
void Teller::process_transaction(int line_number){
	Event* now=tell_queues[line_number].TOP();
	tell_queues[line_number].REMOVE();
	cust_in_line[line_number]--;

	int trans_time=1+rand()%500; // transaction time from 1 second to 500

	addtimeto(trans_time);

	Total_time+=(gettime()-now->gettime());
	Total_trans_time+=trans_time;

	eq->ADD(this);
}// end process_transaction

void Teller::addtimeto(int trans_time){
	this->time+=trans_time;
}// end addtimeto

int Teller::gettime(){
	return time;
}// end gettime
int Teller::getidle(){
	return idle_time;
}// end get idle

Event* Teller::add(){
	int idle=1+rand()%600;
	Event* in=new Teller(idle);
	return in;
}// end add

