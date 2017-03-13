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
	while (lineCount < 50) { 
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

		// Invert the stack passed in
	StackClass stack2;
	while (!stack1.isEmpty()) {
		stack2.push(stack1.pop());
	}
		// Return the inverted stack
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
			character.charValue = newLine[i];
			character.priority = 0;
			if (isdigit(newLine[i])) {
				character.intValue = newLine[i] - '0';
				character.type = "operand";
			}
			else{
				if (newLine[i] == '+' || newLine[i] == '-') {
					character.priority = 1;
				}
				if (newLine[i] == '*' || newLine[i] == '/') {
					character.priority = 2;
				}
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
	string stackString = ""; // Initialize string to hold characters in stack
	if (stack.isEmpty()) {	// If the stack is empty, print "Empty"
		dataOUT << "Empty";
		return;
	}
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
	dataOUT << "            "; // Insert some blank space before infix expression
	printStack(dataOUT, infixStack);
	dataOUT << " = " << answer << endl << endl;
	lineCount+=3;
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
void printAllStacks(ofstream &dataOUT, StackClass infixStack,
	StackClass postfixStack, StackClass operatorStack, int&loopCount) {
	dataOUT << right; // Set output right justified
	
	dataOUT << setw(20);
	printStack(dataOUT, infixStack); // Print the infix stack
	dataOUT << left;
	dataOUT << "              " << setw(30);
	printStack(dataOUT, postfixStack); // Print the Postfix stack
	dataOUT << setw(10);
	printStack(dataOUT, operatorStack); // Print the operand stack
	dataOUT << right << endl; // Return output to right justified
	lineCount += 2;
	loopCount++; // Increment the count of how many times stacks have been printed
}
void printPostAndOpStack(ofstream&dataOUT, StackClass postfixStack, StackClass opStack, int&loopCount){



	dataOUT << right; // Set output right justified
	dataOUT << setw(20);
	printStack(dataOUT, postfixStack); // Print the Postfix stack
	dataOUT << left << "                                    " << setw(15);
	printStack(dataOUT, opStack); // Print the operand stack
	dataOUT << right << endl; // Return output to right justified
	lineCount += 2;
	loopCount++; // Increment the count of how many times stacks have been printed
}
void convertInfixToPostfix(ofstream&dataOUT, StackClass infixStack, StackClass &postfixStack) {
	// Receives – The output file, the infix stack and the postfixStack
	// Task - Convert the infix expression to a postfix expression
	// Returns - Nothing
	StackClass opStack;
	CharacterType char1, char2;

	printTitle1(dataOUT); // Print title for conversion steps
	int loopCount = 0;

	while (!infixStack.isEmpty()) {

		printAllStacks(dataOUT, infixStack, invertStack(postfixStack), opStack, loopCount);

		// pop the first character from the infix expression
		char1 = infixStack.pop();
		// If the item is an operand, push it to postfix and restart
		if (char1.type == "operand") {
			postfixStack.push(char1);
			continue;
		}

		if (char1.type == "operator") {
			// If the item is an operator, and opstack is empty, push it to opstack
			
			if (opStack.isEmpty()) {
				opStack.push(char1);
				continue;
			}
			// If the item is a left perenthesis, or of greater priority than next stack item,
			// push both to stack
			char2 = opStack.pop();
			if (char1.charValue == ')') {

				while (char2.charValue != '(') {
					postfixStack.push(char2);
					char2 = opStack.pop();
				}
				continue;
			}
			if (char1.charValue == '(' || char1.priority > char2.priority) {
				opStack.push(char2);
				opStack.push(char1);
				continue;
			}
			if (opStack.isEmpty()) { // If stack is empty, put popped operator in postfix
				postfixStack.push(char2);
				opStack.push(char1); // Put operator from infix in opstack
				continue;
			}
			if (char2.priority >= char1.priority) {
				postfixStack.push(char2);
				continue;
			}			
			else {
				postfixStack.push(char1);
			}
		}
	}
		// Print all stacks one last time before checking opstack contents
	printAllStacks(dataOUT, infixStack, invertStack(postfixStack), opStack, loopCount);
	// After infix expression has been emptied, finish removing operators from stack
	while (!opStack.isEmpty()) {
		postfixStack.push(opStack.pop());
		printAllStacks(dataOUT, infixStack, invertStack(postfixStack), opStack, loopCount);
	}
	postfixStack = invertStack(postfixStack); // Invert postfix stack so it's in correct order
	dataOUT << endl; // Place a space between Conversion and Evaluation displays
	lineCount++;
}
int evaluatePostfix(ofstream&dataOUT, StackClass postfixStack) {


	int answer = 0,result = 0;

	StackClass opStack;
	CharacterType char1, char2, char3;

	printTitle2(dataOUT); // Print title for evaluation steps
	int loopCount = 0;

	while (!postfixStack.isEmpty()) {
		
		printPostAndOpStack(dataOUT, postfixStack, opStack, loopCount);


		char1 = postfixStack.pop();

		if (char1.type == "operand") {
			opStack.push(char1);
			continue;
		}
		if (char1.type == "operator") {
			char2 = opStack.pop();
			char3 = opStack.pop();

			switch (char1.charValue){
			case '/': answer = (char3.intValue / char2.intValue);
				break;
			case '*': answer = (char3.intValue * char2.intValue);
				break;
			case '+': answer = (char3.intValue + char2.intValue);
				break;
			case '-': answer = (char3.intValue - char2.intValue);				
				break;
			}

			char2.intValue = answer;
			char2.charValue = answer;
			opStack.push(char2);
		}
	
	}

	printPostAndOpStack(dataOUT, postfixStack, opStack, loopCount);


	return answer;
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
		convertInfixToPostfix(dataOUT, infixStack, postfixStack);
		int answer = evaluatePostfix(dataOUT, postfixStack);
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