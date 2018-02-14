/*
 * event.h
 *
 *  Created on: Feb 13, 2017
 *      Author: Nugzar Chkhaidze & Daniel Sullivan
 */


#ifndef EVENT_H_
#define EVENT_H_

#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<queue>

using namespace std;

class Event{
public:
	int lineNumber;
	Event(){}
	virtual Event* add ()
	      { return NULL; }// end add
	virtual int gettime ()
	      { return (0); }// end gettime
	virtual int getidle()
	      { return (0); }// end getidle
	virtual void Action ()
	      {return ; }// end action
	virtual void Action2 ()
	      {return ; }// end aciton2
	virtual void addtimeto (int trans_time)
	      { return ; }//end addtimeto



	virtual ~Event(){}
};

struct cmp {
    bool operator()(Event *a, Event *b)
    {
        return (a->gettime()>b->gettime());
    }// end bool
};// end cmp

class EventQueue{
public:
	std::priority_queue<Event *,std::vector<Event *>,cmp> thequeue;
	EventQueue(){}
	void getnew();
	void getnew2();
	Event* TOP();
	void REMOVE();
	void ADD(Event *a);

};// end event queue



#endif /* EVENT_H_ */
