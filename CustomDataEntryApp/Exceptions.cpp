//Inheritance.
//
//Name: Ludovic
#include "Production_Worker.h"
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

void outputHelpText();
bool confirmYN(string promptText);

int main() {	
	outputHelpText();
	ProductionWorker* pw_ptr = nullptr; // Pointer to dynamically allocate

	string command;
	bool keepRunning = true;   


	while (keepRunning == true) {
		
		cout << "\nEnter command (or 'h' for help): ";
		getline(cin, command);
		cin.clear();

		if (command == "") {
			
		}
		else if (command == "c") {
			if (pw_ptr != nullptr)
			{
				delete pw_ptr;
				pw_ptr = nullptr;
			}
			
			pw_ptr = ProductionWorker::createNewProductionWorker();

		}
		else if (command == "h") {
			outputHelpText();
		}
		else if (command == "p") {

			if (pw_ptr != nullptr)
			{
				pw_ptr->printWorkerData();
			}
			cout << endl;
		}
		else if (command == "q") {
			
			keepRunning = !confirmYN("Are you sure that you want to exit the program? ");
		}
		else {
			cout << "Invalid command:  " << command << endl;
		}
	}
	cout << "Exit the program." << endl;
	return 0;
}

void outputHelpText() {   // Output help text
	cout << "Supported commands: " << endl;
	cout << "     c    Add latest result to input." << endl;
	cout << "     h    Clear the result variable (set to zero)." << endl;
	cout << "     p    Divide latest result by input." << endl;
	cout << "     q    Print this help text." << endl;
}


bool confirmYN(string promptText)
{
	string inputString;
	bool confirmationValue = false;
	bool inputIsOK = false;

	do
	{ 
		cout << promptText;
		getline(cin, inputString);

		if (inputString == "y" || inputString == "Y")
		{
			confirmationValue = true;
			inputIsOK = true;
		}
		else if (inputString == "n" || inputString == "N")
		{
			confirmationValue = false;
			inputIsOK = true;
		}
		else
		{
			cout << "Invalid input:  " << inputString << ".  Please input y or n." << endl;
		}
	} while (inputIsOK == false);
	return confirmationValue;
} 