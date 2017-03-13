//************************************  PROGRAM IDENTIFICATION  ***************************************
//*                                                                                                   *
//*   PROGRAM FILE NAME:  ItemStack.h               ASSIGNMENT #: 4                                   *
//*                                                                                                   *
//*                                                                                                   *
//*   USER DEFINED                                                                                    *
//*    MODULES     : push - Insert one item to the front of the stack                                 *
//*                  pop - Remove and return one item from the front of the stack                     *
//*                  isEmpty - Check to see whether the stack is empty                                *
//*                  clear - Clear each of the items from the stack                                   *
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
struct ItemType {
		// The structure "ItemType" holds each item of the stack
	string type, strValue;
	int intValue, priority;
	ItemType *next;
};
class StackClass {
public:
	StackClass();
	void push(ItemType);
	void clear();
	ItemType pop();
	bool isEmpty();
private:
	ItemType *StartPtr;
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
inline void StackClass::push(ItemType character)
{
		// Receives – One structure of type CharacterType
		// Task - Add the received structure to the front of the stack
		// Returns - Nothing
		// Read in the received character to a new pointer.
	ItemType *CurrentPtr, *newPtr;
	newPtr = new(ItemType);
	newPtr->type = character.type;
	newPtr->strValue = character.strValue;
	newPtr->intValue = character.intValue;
	newPtr->priority = character.priority;
		// Save the position of the start pointer
	CurrentPtr = StartPtr;
		// If there are no nodes in stack, put new one at the beginning and return
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
inline ItemType StackClass::pop()
{
		// Receives – Nothing
		// Task - Remove one node from front of the stack
		// Returns - The removed node.
	if (StartPtr == NULL) {
		return *StartPtr;
	}
	ItemType *TempPtr;
	TempPtr = StartPtr;
	StartPtr = StartPtr->next;
	return *TempPtr;
}
//*****************************************************************************************************
inline bool StackClass::isEmpty()
{
		// Receives – Nothing
		// Task - Check whether the stack is empty
		// Returns - true or false signifying whether the list is empty or not.
	if (StartPtr == NULL) {
		return true;
	}
	else {
		return false;
	}
}
