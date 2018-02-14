/*
 * teller.h
 *
 *  Created on: Feb 13, 2017
 *      Author: Nugzar Chkhaidze & Daniel Sullivan
 */


#ifndef TELLER_H_
#define TELLER_H_

#include "event.h"
class Teller: public Event{
private:
public:
	int idle_time;
	int time;
		Teller(){}
		Teller(int idle_t){
			time = 0;
			idle_time=idle_t;
		}// end Teller struct

	void process_transaction(int line_number);
	void Action();
	void Action2();
	void addtimeto(int trans_time);
	int getidle();
	int gettime();
	Event* add();



	virtual ~Teller(){}
};// end Teller class

class TellerQueue: public EventQueue{
public:
	TellerQueue(){}
};// end TellerQueue


#endif /* TELLER_H_ */
