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
#include "ItemStack.h"
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
	lineCount += 4; // Increment the line count
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
	lineCount += 4; // Increment the line counter
	return;
}
//************************************* END OF FUNCTION FOOTER  ***************************************
void newPage(ofstream&dataOUT) {
		// Receives – the output file
		// Task - Skip to the top of the next page
		// Returns - Nothing
		// Insert lines until the end of the page is reached
	int MAXPAGELINES = 50;
	while (lineCount < MAXPAGELINES) {
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
bool getLine(ifstream&dataIN, StackClass &infixExp) {
		// Receives – The input file and the infixExp
		// Task - Read in a line of data.
		// Returns - A stack filled with one line of data, and true/false for successful operation
		// Declare local variables
	bool firstPrint = true;
	ItemType character;
	char newLine[31];
	dataIN >> ws >> newLine >> ws; // Get line
	if (newLine[0] != 'X') {  // If there is another line, read it in
		int i = 0; // Declare an initialize variable to keep track of line position
			// Read in each character of the line as a separate node
		while (newLine[i] != '\0') { // Stop once a blank space is reached
			character.strValue = newLine[i];
			character.priority = 0;	// Initialize the priority of the item to 0
				// If the item is a digit, read it as an operand
			if (isdigit(newLine[i])) {
				character.intValue = newLine[i] - '0';
				character.type = "operand";
			}
				// If the item is not a digit, read it as an operator
			else{
				if (newLine[i] == '+' || newLine[i] == '-') {
					character.priority = 1; // If the item is a '+' or '-' set priority to 1
				}
				if (newLine[i] == '*' || newLine[i] == '/') {
					character.priority = 2; // If the item is a '*' or '/' set priority to 2
				}
				character.intValue = NULL;	// Set the integer value for operators to NULL
				character.type = "operator";
			}
			infixExp.push(character);	// Push the new item onto the infix stack
			i++;
		}
			// The line was pushed onto stack in reverse order, so invert it
		infixExp = invertStack(infixExp);
		return true; // If a line was read in, return true
	}
	return false; // If no line was read, return false
}
//*****************************************************************************************************
void printStack(ofstream&dataOUT, StackClass stack) {
		// Receives – The output file and a stack
		// Task - Print a stack
		// Returns - Nothing
	string stackString = ""; // Initialize string to hold items of stack
	if (stack.isEmpty()) {	// If the stack is empty, print "Empty"
		dataOUT << "Empty";
		return;
	}
	while (!stack.isEmpty()) { // While there is another item in the stack, add it to the string
		stackString += stack.pop().strValue; 
	}
	dataOUT << stackString; // Print the string which now holds the entire stack
}
//*****************************************************************************************************
void printResults(ofstream&dataOUT, StackClass infixExp, int answer) {
		// Receives – The output file, the original infix stack and the evaluated answer
		// Task - Print the infix stack and the numerical answer
		// Returns - Nothing	
		// Print a data header
	dataOUT << "ORIGINAL EXPRESSION AND THE ANSWER:" << endl;
	dataOUT << "            "; // Insert some blank space before infix expression
		// Print the original infix expression
	printStack(dataOUT, infixExp);
		// Print the answer to the expression
	dataOUT << " = " << answer << endl << endl;
	lineCount+=3; // Increment the line counter
}
//*****************************************************************************************************
void printTitleConversion(ofstream&dataOUT) {
		// Receives – The output file
		// Task - Print data titles for conversion display
		// Returns - Nothing	
	dataOUT << setw(50) << "CONVERSION DISPLAY" << endl;
	dataOUT << "Infix Expression" << setw(28) << "POSTFIX Expression" << setw(28) << "Stack Contents";
	dataOUT << endl << setw(73) << "(Top to Bottom)" << endl;
	lineCount += 3; // increment the line counter
}
//*****************************************************************************************************
void printTitleEvaluation(ofstream&dataOUT) {
		// Receives – The output file
		// Task - Print data titles for evaluation display
		// Returns - Nothing	
	dataOUT << setw(50) << "Evaluation DISPLAY" << endl;
	dataOUT << setw(28) << "POSTFIX Expression" << setw(38) << "Stack Contents";
	dataOUT << endl << setw(67) << "(Top to Bottom)" << endl;
	lineCount += 3; // Increment the line counter
}
//*****************************************************************************************************
void printAllStacks(ofstream &dataOUT, StackClass infixExp,
	StackClass postfixExp, StackClass opStack) {
		// Receives – The output file, each expression and the opstack
		// Task - Print each expression and the opstack
		// Returns - Nothing	
	dataOUT << right; // Set output right justified	
	dataOUT << setw(20); // Set width for infix expression
	printStack(dataOUT, infixExp); // Print the infix stack
	dataOUT << left << "              " << setw(30); // Add some space between postfix
	printStack(dataOUT, postfixExp); // Print the Postfix expression
	dataOUT << setw(10);
	printStack(dataOUT, opStack); // Print the operand stack
	dataOUT << right << endl; // Return output to right justified
	lineCount ++; // Increment the line counter
}
//*****************************************************************************************************
void printPostAndOpStack(ofstream&dataOUT, StackClass postfixExp, StackClass opStack){
		// Receives – The output file, postfix expression and the opstack
		// Task - Print each expression and the opstack
		// Returns - Nothing	
	dataOUT << right; // Set output right justified
	dataOUT << setw(20);
	printStack(dataOUT, postfixExp); // Print the Postfix stack
	dataOUT << left << "                                    " << setw(15);
	printStack(dataOUT, opStack); // Print the op stack
	dataOUT << right << endl; // Return output to right justified
	lineCount ++; // Increment the line counter
}
//*****************************************************************************************************
void convertInfixToPostfix(ofstream&dataOUT, StackClass infixExp, StackClass &postfixExp) {
		// Receives – The output file, the infix expression and the postfix expression
		// Task - Convert the infix expression to a postfix expression / print log
		// Returns - Nothing
	StackClass opStack;
	ItemType item1, item2;
	printTitleConversion(dataOUT); // Print title for conversion steps
	while (!infixExp.isEmpty()) { // Keep converting until the infix expression is empty
			// Print the contents of each espression and opstack
		printAllStacks(dataOUT, infixExp, invertStack(postfixExp), opStack); 
			// Pop the first item from the infix expression
		item1 = infixExp.pop();
			// If the item is an operand, push it to postfix and restart
		if (item1.type == "operand") {
			postfixExp.push(item1);
			continue;
		}
		if (item1.type == "operator") {			
				// If the item is an operator, and opstack is empty, push it to opstack
			if (opStack.isEmpty()) {
				opStack.push(item1);
				continue;
			}
				// If the item is a left perenthesis, or of greater priority than next stack item,
				// push both to stack
			item2 = opStack.pop();
			if (item1.strValue == ")") {

				while (item2.strValue != "(") {
					postfixExp.push(item2);
					item2 = opStack.pop();
				}
				continue;
			}
			if (item1.strValue == "(" || item1.priority > item2.priority) {
				opStack.push(item2);
				opStack.push(item1);
				continue;
			}
			if (opStack.isEmpty()) { // If stack is empty, put popped operator in postfix
				postfixExp.push(item2);
				opStack.push(item1); // Put operator from infix in opstack
				continue;
			}
			if (item2.priority >= item1.priority) {
				postfixExp.push(item2);
				opStack.push(item1);
				continue;
			}			
			else {
				postfixExp.push(item1);
			}
		}
	}
		// Print all stacks one last time before checking opstack contents
	printAllStacks(dataOUT, infixExp, invertStack(postfixExp), opStack);
	// After infix expression has been emptied, finish removing operators from stack
	while (!opStack.isEmpty()) {
		postfixExp.push(opStack.pop());
		printAllStacks(dataOUT, infixExp, invertStack(postfixExp), opStack);
	}
	postfixExp = invertStack(postfixExp); // Invert postfix stack so it's in correct order
	dataOUT << endl; // Place a space between Conversion and Evaluation displays
	lineCount++;
}
//*****************************************************************************************************
int evaluatePostfix(ofstream&dataOUT, StackClass postfixExp) {


	int answer = 0,result = 0;

	StackClass opStack;
	ItemType char1, char2, char3,resultChar;

	printTitleEvaluation(dataOUT); // Print title for evaluation steps

	while (!postfixExp.isEmpty()) {
		
		printPostAndOpStack(dataOUT, postfixExp, opStack);


		char1 = postfixExp.pop();

		if (char1.type == "operand") {
			opStack.push(char1);
			continue;
		}
		if (char1.type == "operator") {
			char2 = opStack.pop();
			char3 = opStack.pop();

			if (char1.strValue == "/") {
				answer = (char3.intValue / char2.intValue);
				resultChar.priority = 2;
			}
			if (char1.strValue == "*") {
				answer = (char3.intValue * char2.intValue);
				resultChar.priority = 2;
			}
			if (char1.strValue == "+") {
				answer = (char3.intValue + char2.intValue);
				resultChar.priority = 1;
			}
			if (char1.strValue == "-") {
				answer = (char3.intValue - char2.intValue);
				resultChar.priority = 1;
			}

			resultChar.intValue = answer;
			resultChar.strValue = to_string(answer);
			resultChar.type = "operand";
			
			opStack.push(resultChar);
		}
	
	}

		// Print postfix stack and opstack
	printPostAndOpStack(dataOUT, postfixExp, opStack);

		// if answer is still in opstack, remove it, then print one last time
	if (!opStack.isEmpty()) {
		opStack.clear();
		printPostAndOpStack(dataOUT, postfixExp, opStack);
	}


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
	StackClass infixExp, postfixExp;

	dataIN.open("stack_in.txt"); // Open the file containing data.
	dataOUT.open("dataOUT.doc"); // Create and open the file to write data to.		
	Header(dataOUT); // Print data header.
	while (getLine(dataIN, infixExp)) { // While an expression is available, process it
			// Process each line of data from the input file.
		convertInfixToPostfix(dataOUT, infixExp, postfixExp);
		int answer = evaluatePostfix(dataOUT, postfixExp);
		printResults(dataOUT, infixExp, answer);

			// Reset both infix and postfix stacks
		infixExp.clear();
		postfixExp.clear();
			// Start on a new page
		newPage(dataOUT);
	}
	Footer(dataOUT); // Print footer. 
	dataIN.close(); // Close input data file. 
	dataOUT.close(); // Close output data file.
	return 0;
}
//*****************************************************************************************************