/*
 * event.cpp
 *
 *  Created on: Feb 13, 2017
 *      Author: Nugzar Chkhaidze & Daniel Sullivan
 */

#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<queue>

#include "event.h"


void EventQueue::getnew(){
	Event *now=thequeue.top();
	thequeue.pop();

	now->Action();
}// end getnew
void EventQueue::getnew2(){

	Event *now=thequeue.top();
	thequeue.pop();

	now->Action2();
}//end getnew2
Event* EventQueue::TOP(){
	return thequeue.top();
}// end top
void EventQueue::REMOVE(){
	thequeue.pop();
}// end remove
void EventQueue::ADD(Event *a){
	thequeue.push(a);
}// end add

