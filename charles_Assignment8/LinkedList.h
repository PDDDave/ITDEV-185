#pragma once
#include "PersonNode.h"

/*
* This is the header LinkedList Class
*/
class LinkedList
{
	private:
		//member variables
		PersonNode *headPtr;
		PersonNode *tailPtr;

	public:
	    //function deffinitions 
	  
		
		LinkedList(); //constuctor

		
		void addLink(PersonNode*);
		PersonNode *findInsertSpot(PersonNode* newNode);
		PersonNode *getHead();
};

