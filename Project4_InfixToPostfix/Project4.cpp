//************************************  PROGRAM IDENTIFICATION  ***************************************
//*                                                                                                   *
//*   PROGRAM FILE NAME:  Project4.cpp          ASSIGNMENT #:  4            Grade: _________          *
//*                                                                                                   *
//*   PROGRAM AUTHOR:     __________________________________________                                  *
//*                                     Micaiah Skolnick                                              *
//*                                                                                                   *
//*   COURSE #:  CSC 36000 11                            DUE DATE:  March 10, 2017                    *
//*                                                                                                   *
//*****************************************************************************************************
//***********************************  PROGRAM DESCRIPTION  *******************************************
//*                                                                                                   *
//*   PROCESS: 


//*							NEED TO FILL THIS IN

//*                                                                                                   *
//*   USER DEFINED                                                                                    *
//*    MODULES     : Footer - Prints a footer to signify end of program output                        *
//*                  Header - Prints a header to signify start of program output                      *
//*                  processData - Data from the input file is read into the program and processed    *
//*                  main - Variables are declared, functions are called, and headers are printed     *
//*                  printResults - Read each Op code character and perform the subsequent action.    *
//*                                                                                                   *
//*****************************************************************************************************
#include <iostream>
#include <fstream>
#include <iomanip>
#include <ctype.h>
#include <locale>
#include <string>
#include <sstream>
#include "CharacterStack.h"
using namespace std;
int lineCount = 0; // Declare and initialize a line counter
//*************************************  FUNCTION HEADER  *********************************************
void Header(ofstream &Outfile)
{       // Receives – the output file
		// Task - Prints the output preamble
		// Returns - Nothing
	Outfile << setw(30) << "Micaiah Skolnick ";
	Outfile << setw(17) << "CSC 36000";
	Outfile << setw(15) << "Section 11" << endl;
	Outfile << setw(27) << "Spring 2017";
	Outfile << setw(30) << "Assignment #4" << endl;
	Outfile << setw(35) << "---------------------------------- - ";
	Outfile << setw(35) << "---------------------------------- - " << endl << endl;
	lineCount += 4;
	return;
}
//************************************* END OF FUNCTION HEADER  ***************************************
//*************************************  FUNCTION FOOTER  *********************************************
void Footer(ofstream &Outfile)
{
	// Receives – the output file
	// Task - Prints the output salutation
	// Returns - Nothing
	Outfile << endl;
	Outfile << setw(35) << "-------------------------------- - " << endl;
	Outfile << setw(35) << " | END OF PROGRAM OUTPUT | " << endl;
	Outfile << setw(35) << "-------------------------------- - " << endl;
	return;
}
//************************************* END OF FUNCTION FOOTER  ***************************************
void newPage(ofstream&dataOUT) {
		// Receives – the output file
		// Task - Skip to the top of the next page
		// Returns - Nothing

		// Insert lines until the end of the page is reached
	while (lineCount < 40) { 
		dataOUT << endl;
		lineCount++;
	}
		// Reset line counter to 0
	lineCount = 0;
}
//*****************************************************************************************************
StackClass invertStack(StackClass stack1) {
	// Receives – One Stack
	// Task - Invert stack to oposite order
	// Returns - The inverted stack

	StackClass stack2;

	while (!stack1.isEmpty()) {
		stack2.push(stack1.pop());
	}

	return stack2;
}
//*****************************************************************************************************
bool getLine(ifstream&dataIN, StackClass &infixStack) {
		// Receives – The input and output files
		// Task - Process each data record/op code.
		// Returns - Nothing

		// Declare local variables
	bool firstPrint = true;
	CharacterType character;
	char newLine[31];
	dataIN >> ws >> newLine >> ws; // Get line
	if (newLine[0] != 'X') {  // As long as there is another line, read it in
		int i = 0;
			// Read in each character of the line as a separate node
		while (newLine[i] != '\0') { // Stop once a blank space is reached
			int b = 2;
			character.charValue = newLine[i];
			if (isdigit(newLine[i])) {
				character.intValue = newLine[i] - '0';
				character.type = "operand";
			}
			else {
				character.intValue = NULL;
				character.type = "operator";
			}
			infixStack.push(character);
			i++;
		}
			// The line is now in reverse order, so invert it
		infixStack = invertStack(infixStack);
		return true; // If a line was read in, return true
	}
	return false; // If no line was read, return false
}
//*****************************************************************************************************
void printStack(ofstream&dataOUT, StackClass stack) {
		// Receives – The output file and a stack
		// Task - Print a stack
		// Returns - Nothing
	string stackString = "";
	if (stack.isEmpty()) {	// If the stack is empty, print "Empty"
		dataOUT << "Empty";
		return;
	}
	//while (!stack.isEmpty()) { // While there is another value in the stack, print it
	//	dataOUT << stack.pop().charValue;
		//dataOUT << " ";
	//}
	while (!stack.isEmpty()) { // While there is another value in the stack, add it to the string
		stackString += stack.pop().charValue;
	}
	dataOUT << stackString;
}
void printResults(ofstream&dataOUT, StackClass infixStack, int answer) {
		// Receives – The output file, the infix stack and the evaluated answer
		// Task - Print the infix stack and the numerical answer
		// Returns - Nothing	
	dataOUT << "ORIGINAL EXPRESSION AND THE ANSWER:" << endl;
	lineCount++;
	dataOUT << "            "; // Insert some blank space before infix expression
	printStack(dataOUT, infixStack);
	dataOUT << " = " << answer << endl;
	lineCount++;
}
//*****************************************************************************************************
void printTitle1(ofstream&dataOUT) {
	dataOUT << setw(50) << "CONVERSION DISPLAY" << endl;
	dataOUT << "Infix Expression" << setw(28) << "POSTFIX Expression" << setw(28) << "Stack Contents";
	dataOUT << endl << setw(73) << "(Top to Bottom)" << endl;
	lineCount += 3;
}
//*****************************************************************************************************
void printTitle2(ofstream&dataOUT) {
	dataOUT << setw(50) << "Evaluation DISPLAY" << endl;
	dataOUT << setw(28) << "POSTFIX Expression" << setw(38) << "Stack Contents";
	dataOUT << endl << setw(67) << "(Top to Bottom)" << endl;
	lineCount += 3;
}
//*****************************************************************************************************
int convertInfixToPostfix(ofstream&dataOUT, StackClass infixStack,StackClass &postfixStack) {
		// Receives – The output file, the infix stack and the postfixStack
		// Task - Convert the infix expression to a postfix expression
		// Returns - Nothing
	StackClass operandStack;
	CharacterType charToMove;

	printTitle1(dataOUT); // Print title for conversion steps
	int loopCount = 0;

	while (!infixStack.isEmpty()) {

		dataOUT << left; // Set left justified
		for (int i = 0; i < loopCount; i++) {
			dataOUT << " ";
		}
		dataOUT << setw(30-loopCount);
		printStack(dataOUT, infixStack); // Print the infix stack
		dataOUT << setw(20);
		printStack(dataOUT, invertStack(postfixStack)); // Print the Postfix stack
		dataOUT << setw(60);
		printStack(dataOUT, operandStack); // Print the operand stack
		dataOUT << endl;
		lineCount++;
		

		charToMove = infixStack.pop();
		if (charToMove.type == "operator") {
			operandStack.push(charToMove);
		}
		else {
			postfixStack.push(charToMove);
		}
		loopCount++;
	}
	dataOUT << right << endl; // Return output to right justified
	lineCount++;


	printTitle2(dataOUT); // Print title for evaluation steps
	

	return 0;
}
//*****************************************************************************************************
int main() {
	// Receives – Nothing
	// Task - Call each necessary function of the program in order
	// Returns - Nothing
	// Declare variables used in program.	 
	ifstream dataIN;
	ofstream dataOUT;
	StackClass infixStack, postfixStack;

	dataIN.open("stack_in.txt"); // Open the file containing data.
	dataOUT.open("dataOUT.doc"); // Create and open the file to write data to.		
	Header(dataOUT); // Print data header.
	while (getLine(dataIN, infixStack)) { // While an expression is available, process it
			// Process each line of data from the input file.
		int answer = convertInfixToPostfix(dataOUT, infixStack, postfixStack); 
		printResults(dataOUT, infixStack, answer);

			// Reset both infix and postfix stacks
		infixStack.clear();
		postfixStack.clear();
			// Start on a new page
		newPage(dataOUT);
	}
	Footer(dataOUT); // Print footer. 
	dataIN.close(); // Close input data file. 
	dataOUT.close(); // Close output data file.
	return 0;
}