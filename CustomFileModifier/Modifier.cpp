//This Program basically goes through files, copy and paste to new files. 
// It also has the feature of modifying the unit value of an element in the list.
//Last, this programs permits to register entries up to 100.
//
//Name: Ludovic
#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include "InventoryItem.h"
#include <cmath>

using namespace std;

void outputHelpText();
bool confirmYN(string promptText);

void openInputNCopyT0Array(string& inputFileName, fstream& inFile,
InventoryItem* ptr, string delimiter);
void openOutputNCopyFromArray(string& outputFileName, ofstream& outFile,
	InventoryItem* ptr, string delimiter);

void NewLineToArray(InventoryItem* ptr);
void AddNewUnitValue(InventoryItem* ptr);
void ReduceUnitValue(InventoryItem* ptr);

void openOutputFile(string& outputFileName, ofstream& outFile);
void openInputFile(string& inputFileName, fstream& inFile);
void closeInputFile(fstream& inFile);
void closeOutputFile(ofstream& outFile);

int splitLineToArray(string inputText, string inputDelim,
	string outputFieldArray[], int maxFields);

void printInventory(InventoryItem* ptr);

const string DEFAULT_DELIMITER = "|";
const int SIZE = 100;
int cur_count = 0;

int main() {

	outputHelpText();	

	//Create an array with an InventoryItem pointer.
	int cur_SIZE = 0;
	InventoryItem* ptr = nullptr;
	ptr = new InventoryItem[SIZE];

	//setting the file names and the fstream file object related.
	fstream inFile;
	string inputFileName;
	ofstream outFile;
	string outputFileName;
	
	string delimiter = DEFAULT_DELIMITER;

	string command;			//	command string, input by user
	bool keepRunning = true;         // flag to control exit from program.

	while (keepRunning == true) {
		
		cout << "\nCommand: ";
		getline(cin, command);
		cin.clear();

		if (command == "") {
		
		}
		else if (command == "a") {
			AddNewUnitValue(ptr);
		}
		else if (command == "h") {
			outputHelpText();
		}
		else if (command == "i") {
			openInputNCopyT0Array(inputFileName, inFile, 
				ptr, delimiter);
		}
		else if (command == "p") {
			printInventory(ptr);
		}
		else if (command == "n") {
			NewLineToArray(ptr);
		}
		else if (command == "o") {
			openOutputNCopyFromArray(outputFileName,outFile, 
				ptr,delimiter);
		}
		else if (command == "q") {
			
			keepRunning = !confirmYN("Are you sure that you want to exit the program? ");
			cout << "Exit." << endl;
		}
		else if (command == "r") {
			ReduceUnitValue(ptr);
		}
		else {
			cout << "Invalid command:  " << command << endl;
		}

	}  // (end 'while')

	//Reset dynamic memory at the end of program.
	delete[] ptr;
	ptr = nullptr;
	return 0;
}

void printInventory(InventoryItem* ptr) {	//Displays list implemented in the dynamic array.
	cout << fixed << showpoint <<setprecision(2);

	cout << setw(4) << "Item Num\t"  << setw(45) << left << "Description" 
		<< setw(40)<< right << "Cost" << setw(15) << "Quantity" << endl;
	
	cout << setw(4) << left << "________\t" << setw(45) << "__________"
		 << setw(40) << right << "____"  << setw(15) << "_________" << endl;
	
	for (int i = 0; i < cur_count; i++)
	{
		cout << setw(4) << left << i << "\t\t" << setw(45)<< ptr[i].getDescription()
			<< setw(40) << right << ptr[i].getCost() << setw(15) << ptr[i].getUnits() <<endl;	
	}
	
	cout << "\n" << cur_count << " records.";
}

void NewLineToArray(InventoryItem* ptr) {	//add new item in list with its component.
	string desc;
	double cost;
	int	units;
	
	cout << "Enter description for new Item: ";
	getline(cin, desc);
	cin.clear();

	cout << "Enter unit cost for new Item: ";
	cin >> cost;
	cin.ignore(3, '\n');
	cin.clear();

	cout << "Enter initial quantity for the new Item: ";
	cin>> units;
	cin.clear();

	ptr[cur_count].setCost(cost);
	ptr[cur_count].setDescription(desc);
	ptr[cur_count].setUnits(units);

	ptr = new InventoryItem[cur_count];
	cout << "Announcing a new inventory Item: " << desc <<endl ;

	cur_count++;

	cout << "We now have " << cur_count  << " different inventory Items in stock!" << endl;
}

void AddNewUnitValue(InventoryItem* ptr) {	//add the unit amout of selected item in list.
	int count;
	int new_unitAm;
	int cur_unitAm;

	cout << "Choose a Item Number : ";
	cin >> count;
	cin.clear();

	cout << "How many parts to add ? ";
	cin >> new_unitAm;
	cin.clear();

	cur_unitAm = ptr[count].getUnits();
	if (new_unitAm < 0 || new_unitAm > 30)
	{
		cout << "ERROR: initial quantity must be >= zero and <= 30." << endl;
	}
	else
	{
		ptr[count].setUnits(cur_unitAm + new_unitAm);
	}
	cout << endl;
}

void ReduceUnitValue(InventoryItem* ptr) {	//substract the unit amout of selected item in list.
	int count;
	int new_unitAm;
	int cur_unitAm;
	 
	cout << "Choose a Item Number : ";
	cin >> count;
	cin.clear();

	cout << "How many parts to remove? ";
	cin >> new_unitAm;
	cin.clear();

	cur_unitAm = ptr[count].getUnits();
	if (new_unitAm > cur_unitAm)
	{
		cout << "Error: You are attempting to remove more parts than the Item currently holds." << endl;
	}

	else
	{
		ptr[count].setUnits(cur_unitAm - new_unitAm);
	}
	cout << endl;
}

void openInputNCopyT0Array(string& inputFileName, fstream& inFile, InventoryItem* ptr, string delimiter) {
	openInputFile(inputFileName, inFile);
	int count = 0;
	string inputBuffer;
	int fieldCount = 0;
	string Inv_line[SIZE];
	while (getline(inFile, inputBuffer)) {

		fieldCount = splitLineToArray(inputBuffer, delimiter, Inv_line, SIZE);
		for (int i = 0; i < fieldCount; i++)
		{
			if (i == 1)
			{
				ptr[cur_count].setDescription(Inv_line[i]);	
			}
			if (i == 2)
			{
				ptr[cur_count].setCost(stod(Inv_line[i]));	
			}
			if (i == 3)
			{
				ptr[cur_count].setUnits(stoi(Inv_line[i]));
			}
		}
		cur_count++;
		count++;
	}

	cout << count << " records loaded to array. " << endl;

	closeInputFile(inFile);
}  

int splitLineToArray(string inputText, string inputDelim,
	string outputFieldArray[], int maxFields)
{

	size_t nextFieldPosition = 0;		//	Start position of data field.
	size_t foundPosition;				//  Position where delimiter was found,
	int fieldCount = 0;		        //  Number of data fields found so far,
	bool endOfLine = false;			//	Flag -- end of input line detected,
	string dataField;				//  Copy of the data field.

	while (!endOfLine)
	{
		foundPosition = inputText.find(inputDelim, nextFieldPosition);
		if (foundPosition == string::npos)
		{
			// (Here if the string 'find' function reached the end of the input string.)
			endOfLine = true;
			foundPosition = inputText.length();

			if (foundPosition > nextFieldPosition)
			{
				dataField = inputText.substr(nextFieldPosition,
					foundPosition - nextFieldPosition);
				fieldCount++;
			}
		}
		else
		{
			// (Here if 'inputDelim' was found in the input string.)
			// Copy the data field contents from the input string to the
			// 'dataField' local variable.
			dataField = inputText.substr(nextFieldPosition, foundPosition - nextFieldPosition);
			fieldCount++;

			// Adjust 'nextFieldPosition' as preparation for finding NEXT delimiter.
			nextFieldPosition = foundPosition + 1;
		}

		if (fieldCount > 0)
		{
			if (fieldCount > maxFields)
			{
				cout << "ERROR at line __LINE__: too many input fields, fieldCount="
					<< fieldCount << endl;
			}
			else
			{
				outputFieldArray[fieldCount - 1] = dataField;
			}
		}
	} // (end while)


	return fieldCount;
} // (end function splitLineToArray )


void openOutputNCopyFromArray(string& outputFileName, ofstream& outFile, InventoryItem* ptr, string delimiter) {
	openOutputFile(outputFileName,outFile);
	//Copy the content of array into this outoutfile.

	int count = 0;
	string inputBuffer;
	int fieldCount = 0;
	string Inv_line[SIZE];

	for (int i = 0; i < cur_count; i++)
	{
		outFile << i << delimiter << ptr[i].getDescription() << delimiter
			 << ptr[i].getCost() << delimiter << ptr[i].getUnits() << endl;
	}
	cout << cur_count << " records written to file. " << endl;

	closeOutputFile(outFile);
}  

void outputHelpText() {
	cout << "Supported commands: " << endl;
		cout << "	a	Add parts : increase the units value for an existing inventory item. " << endl;
		cout <<	"	h	print Help text. " << endl;
		cout << "	i	Input inventory data from a file."<< endl;
		cout << "	p	Print inventory list." << endl;
		cout << "	n	Create a New inventory Item. " << endl;
		cout << "	o	Output inventory data to a file. "<< endl;
		cout << "	q	Quit(end the program)."<< endl;
		cout << "	r	Remove parts : reduce the units value for an existing inventory item."<< endl;
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



void openInputFile(string& inputFileName, fstream& inFile) {	//Open input File
	cout << "Enter name of input file:  ";
	getline(cin, inputFileName);
	
	inFile.open(inputFileName);
	// Check for file open error.
	if (inFile.fail())
	{
		cout << "(line " << __LINE__ << ") Error opening file:  " << inputFileName << endl;
	}
}


void openOutputFile(string& outputFileName, ofstream& outFile) {	//Open output file
	cout << "Enter name of output file:  ";
	getline(cin, outputFileName);

	outFile.open(outputFileName);
}


void closeInputFile(fstream& inFile) {	//Close Input File.

	inFile.close();
} 

void closeOutputFile(ofstream& outFile) {	//Close Output File.

	outFile.close();
}