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
	string type;
	char charValue;
	int intValue;
	CharacterType *next;
};
class StackClass {
public:
	StackClass();
	void push(CharacterType);
	void clear();
	CharacterType pop();
	bool isEmpty();
private:
	CharacterType *StartPtr;
};
//*****************************************************************************************************
StackClass::StackClass() {
	// Initialize the start Ptr to NULL
	StartPtr = NULL;
}
//*****************************************************************************************************
inline void StackClass::clear() {
		// Receives – Nothing
		// Task - Clear all values from the stack
		// Returns - Nothing
	while (StartPtr != NULL) {
		pop();
	}
}
inline void StackClass::push(CharacterType character)
{
		// Receives – One structure of type CharacterType
		// Task - Add the received structure to the front of the stack
		// Returns - Nothing

		// Read in the received character to a new pointer.
	CharacterType *CurrentPtr, *newPtr;
	newPtr = new(CharacterType);
	newPtr->type = character.type;
	newPtr->charValue = character.charValue;
	newPtr->intValue = character.intValue;

		// Save the position of the start pointer
	CurrentPtr = StartPtr;
		// If there are no nodes in stack, put this one at the beginning and return
	if (StartPtr == NULL) {
		StartPtr = newPtr;
		newPtr->next = NULL;
		return;
	}
	else {	// Insert the new character at the top of the stack
		StartPtr = newPtr;
		StartPtr->next = CurrentPtr;
	}
}
//*****************************************************************************************************
inline CharacterType StackClass::pop()
{
		// Receives – Nothing
		// Task - Remove one node from front of the stack
		// Returns - The removed node.
	CharacterType *TempPtr;
	TempPtr = StartPtr;
	StartPtr = StartPtr->next;
	return *TempPtr;
}
//*****************************************************************************************************
inline bool StackClass::isEmpty()
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
