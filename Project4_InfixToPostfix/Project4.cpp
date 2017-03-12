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
#include <string>
#include <sstream>
#include "CharacterStack.h"
using namespace std;
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

void getData(ifstream&dataIN, CharacterStackClass &infixStack) {
	// Receives – The input and output files
	// Task - Process each data record/op code.
	// Returns - Nothing

	// Declare local variables
	int currentTime = 0;
	CharacterStackClass List1, List2, List3;
	bool firstPrint = true;
	CharacterType customer;
	int fieldNumber;
	string newValue;
	int code;
	dataIN >> ws >> code >> ws; // seed read first code
	while (code != 'X') {  // As long as there is another code, read it in
		customer.tArrival = code;
		








		dataIN >> ws >> code >> ws; // Read in the next code
	}
	
}
//*****************************************************************************************************
void printResults(ofstream&dataOUT, CharacterStackClass infixStack, int answer) {
	// Receives – The output file, order of customer arrival, and exit.
	// Task - Print each list of customers
	// Returns - Nothing	
	dataOUT << "ORIGINAL EXPRESSION AND THE ANSWER:" << endl;
	while (!infixStack.isEmpty()) {
		dataOUT << setw(12) << infixStack.pop().name;
		dataOUT << " ";
	}
	dataOUT << answer << endl;
}
//*****************************************************************************************************
int main() {
	// Receives – Nothing
	// Task - Call each necessary function of the program in order
	// Returns - Nothing
	// Declare variables used in program.	 
	ifstream dataIN;
	ofstream dataOUT;
	CharacterStackClass infixStack, postfixStack;

	dataIN.open("queue_in.txt"); // Open the file containing data.
	dataOUT.open("dataOUT.doc"); // Create and open the file to write data to.		
	Header(dataOUT); // Print data header.
	getData(dataIN, infixStack); // Read in the first infix expression
	int answer = convertInfixToPostfix(infixStack, postfixStack); // Process each section of data from the input file.
	printResults(dataOUT, infixStack, answer);
	Footer(dataOUT); // Print footer. 
	dataIN.close(); // Close input data file. 
	dataOUT.close(); // Close output data file.
	return 0;
}