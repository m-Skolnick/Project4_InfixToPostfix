//************************************  PROGRAM IDENTIFICATION  ***************************************
//*                                                                                                   *
//*   PROGRAM FILE NAME:  CharacterStack.h               ASSIGNMENT #: 4                              *
//*                                                                                                   *
//*                                                                                                   *
//*   USER DEFINED                                                                                    *
//*    MODULES     : add - Insert one record of type CustomerType into list of records                *
//*                  pop - Remove and return one record from the front of the list                    *
//*                  checkForPop - Check to see if the front customer is ready to be popped from list *
//*                  isEmpty - Check to see whether the list is empty                                 *
//*                  getPTime() - Get the total process time for the list of customers
//*                                                                                                   *
//*****************************************************************************************************
#include <iostream>
#include <fstream>
#include <iomanip>
#include <ctype.h>
#include <string>
#include <sstream>
using namespace std;
//*****************************************************************************************************
struct CharacterType {
	// The structure "CustomerType" holds each record file.
	int tArrival, tProcess;
	string name;
	CharacterType *next;
};
class CharacterStackClass {
public:
	CharacterStackClass();
	void add(CharacterType);
	CharacterType pop();
	bool isEmpty();
private:
	CharacterType *StartPtr;
};
//*****************************************************************************************************
CharacterStackClass::CharacterStackClass() {
	// Initialize the start Ptr to NULL
	StartPtr = NULL;
}
//*****************************************************************************************************
inline void CharacterStackClass::add(CharacterType customer)
{
	// Receives – One structure of type CustomerType
	// Task - Add the received structure to the back of customerlist
	// Returns - Nothing

	// Read in the received customer to a new pointer.
	CharacterType *CurrentPtr, *newPtr;
	newPtr = new(CharacterType);
	newPtr->tArrival = customer.tArrival;
	newPtr->name = customer.name;
	newPtr->tProcess = customer.tProcess;


	CurrentPtr = StartPtr;
	// If there are no nodes in list, put this one at the beginning and return
	if (StartPtr == NULL) {
		StartPtr = newPtr;
		newPtr->next = NULL;
		return;
	}
	// Find the end of the list
	while (CurrentPtr->next != NULL) {
		CurrentPtr = CurrentPtr->next;
	}
	// Push to the end of the list
	CurrentPtr->next = newPtr;
	newPtr->next = NULL;
}
//*****************************************************************************************************
inline CharacterType CharacterStackClass::pop()
{
	// Receives – Nothing
	// Task - Remove one node from front of list
	// Returns - The removed node.
	CharacterType *TempPtr;
	TempPtr = StartPtr;
	StartPtr = StartPtr->next;
	return *TempPtr;
}
//*****************************************************************************************************
inline bool CharacterStackClass::isEmpty()
{
	// Receives – Nothing
	// Task - Check whether the list is empty
	// Returns - true or false signifying whether the list is empty or not.
	if (StartPtr == NULL) {
		return true;
	}
	else {
		return false;
	}
}
