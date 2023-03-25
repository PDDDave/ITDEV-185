#include "LinkedList.h"

/*
* This is the implementation file for the LinkedList class.
*/


//Constructor sets the head and tail pointers to null
LinkedList::LinkedList() {
	headPtr = nullptr;
	tailPtr = nullptr;
}

//This method takes PersonNode pointer and adds it to the linked list 
void LinkedList::addLink(PersonNode* newNode) {

	newNode->setNext(findInsertSpot(newNode)); //sets the next of the new node to point to the next item on list.
}


//This method returns a PersonNode pointer with the position at which the next node should be inserted.
PersonNode* LinkedList::findInsertSpot(PersonNode* newNode) {
	PersonNode* previousPtr = headPtr;
	PersonNode* nodePtr;

	PersonNode* inPosition = nullptr;


	//if list is empty or newNode lName is of higher order
	if (headPtr == nullptr || headPtr->getLName().compare(newNode->getLName()) > 0) { //> 0 would mean that new name is lower than old

		nodePtr = nullptr;
		//newNode->setNext(previousPtr);  //sets the next pointer of the new first node to point to what was first, either a PersonNode or nullptr
		//headPtr = newNode; //sets the LinkedList's headPointer to the address of the new Node.
	}
	else {
		//if list is not empty
		nodePtr = headPtr->getNext();
		while (nodePtr != nullptr && nodePtr->getLName().compare(newNode->getLName()) > 0) { //while list isnt null and the current node's name is of lower order

			//Step along list by setting the previous pointer to current, and advancing current to next, repeat loop
			previousPtr = nodePtr;
			nodePtr = nodePtr->getNext();
		}
	}



	//change previous to point to new
	previousPtr->setNext(newNode);

	return nodePtr;
}

//Accessor
PersonNode* LinkedList::getHead() {
	return headPtr;
}
