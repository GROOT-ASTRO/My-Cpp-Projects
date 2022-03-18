// Implementation file for the Employee class

#include "Production_Worker.h"
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

// Mutators
void ProductionWorker::setShift(int s)
{	
	testShift(s);
	shift = s;
}


void ProductionWorker::setPayRate(double r)
{	
	testpayrate(r);
	payRate = r;
}

// Accessors
int ProductionWorker::getShiftNumber() const
{
	return shift;
}

string ProductionWorker::getShiftName() const
{
	getShiftNumber();
	if (shift == 1) {
		return "day";
	}
	else if (shift == 2) {
		return "night";
	}
	else
	{
		return "Not an integer";
	}
}
double ProductionWorker::getPayRate() const
{
	return payRate;
}
void ProductionWorker::printWorkerDate() const
{
	cout << getHireDate();
}



void ProductionWorker::printWorkerData() const
{
	cout << "\nName: " << getEmployeeName();

	cout << "\nEmployee number: " << getEmployeeNumber();

	cout << "\nHire date: " << getHireDate();

	cout << "\nShift: " << getShiftName();

	cout << "\nShift number: " << shift;

	cout << "\nPay rate: " << payRate;
}

void ProductionWorker::testpayrate(double r) {
	if (r < 7.25 )
	{
		throw InvalidPayRate();
	}
}

void ProductionWorker::testShift(int s) {
	if (s != 1 && s != 2)
	{
		throw InvalidShift();
	}
}


 ProductionWorker* ProductionWorker::createNewProductionWorker() {

	ProductionWorker* Emp = nullptr;
	string hireDate;
	string aname;
	int ashift;
	double aPayRate;
	bool Loops = true;
	while (Loops == true)
	{
		cout << "\nEnter name of new employee: ";
		getline(cin, aname);
		cout << endl;

		cout << "\nEnter hire date of new employee: ";
		getline(cin, hireDate);
		cout << endl;

		cout << "\nEnter shift for new employee (1=day, 2=night): ";
		cin >> ashift;
		cout << endl;
		cin.ignore(10, '\n');

		cout << "\nEnter hourly pay rate for new employee: ";
		cin >> aPayRate;
		cout << endl;
		cin.ignore(10, '\n');

		try {

			Emp = new ProductionWorker(aname, hireDate, ashift, aPayRate);
			Loops = false;
		}
		catch (Employee::InvalidHireDate)
		{
			cout << "Error: The date [" << hireDate << "] does not match the MM/DD/YYYY format." << endl;
		}

		catch (ProductionWorker::InvalidShift)
		{
			cout << "Error: There are only 2 shifts in this establishment. The input "

				<< ashift << " does not follow our protocol." << endl;

		}
		catch (ProductionWorker::InvalidPayRate)
		{
			cout << "Error: Didn't you know that " << aPayRate
				<< "$/hr is lower than the federal wage?" << endl;
		}
	}
	return Emp;
}
	