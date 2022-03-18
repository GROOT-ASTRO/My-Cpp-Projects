// This app sorts data alphabetically inside an array. 

//Name: Ludovic
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

void selectionSort(string[], int);	//sorts each line alphabetically.
void showArray(string[], int);  ////prints each line alphabetically.


int main()
{
	//Reads the file and stores each line in an array in the original order.
	string inputFileName;

	cout << "Enter name of input file: ";
	getline(cin, inputFileName);


	const int ARRAY_SIZE = 50; // Array size
	string numbers[ARRAY_SIZE];    // Array with 100 elements

	ifstream inputFile;         // Input file stream object
	const int NUMBERS_PER_LINE = 1;  // Number of output columns
	const int COLUMN_WIDTH = 8; // Column width for displaying data.

	inputFile.open(inputFileName.c_str()); // Open the file.

	if (!inputFile) { cout << "ERROR: Invalid filename \n"; exit(1); }	//failsafe

	int count = 0;          
	
	while (count < ARRAY_SIZE && getline(inputFile, numbers[count])) {
		count++;
	}
	
	// Close the file.
	inputFile.close();
	
	cout << count <<" lines of text read from input file." << endl;

	// Display the numbers read.
	cout << "Here are the unsorted names:\n" << 
		"-----------------------------" << endl;
	for (int index = 0; index < count; index++) {
		// Output the data to the screen, with
		// NUMBERS_PER_LINE values on each line.
		cout << "[ " << index << "]" << setw(COLUMN_WIDTH) << numbers[index];
		if ((index >= 0) && (index % NUMBERS_PER_LINE == (NUMBERS_PER_LINE - 1))) {
			cout << endl;
		}
		
	}
	cout << endl;
	
	selectionSort(numbers, count);
	cout << "\nHere are the names sorted:\n" <<
		"-----------------------------" << endl;
	showArray(numbers, count);
	return 0;
}
                 *
// This function performs an ascending order selection sort.
void selectionSort(string array[], int size)
{
	int startScan, minIndex;
	string minValue;
	int pass = 0;
	int swapCount = 0;
	for (startScan = 0; startScan < (size - 1); startScan++)
	{
		pass++;
		minIndex = startScan;
		minValue = array[startScan];
		for (int index = startScan + 1; index < size; index++)//outer, reaches for first letter in a string.
		{
			if (array[index] < minValue)//inner, reiterates the lower string value every line.
			{
				minValue = array[index];
				minIndex = index;
			}
		}
		swap(array[minIndex], array[startScan]);	//changes the index values for the new array based on the old.

		cout << "Swap[" << minIndex << "] " << array[minIndex]
			<< " with [" << startScan << "] " << array[startScan] << "." << endl;

	}
}

void showArray(string array[], int size)
{
	for (int count = 0; count < size; count++)
		cout << "[ " << count << "]" << array[count] << " "<< endl;
	cout << endl;
}