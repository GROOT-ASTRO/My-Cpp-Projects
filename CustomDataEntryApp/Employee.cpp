// Implementation file for the Employee class

#include "Employee.h"
#include <string>
#include <cctype>


using namespace std;

int Employee::lastEmployeeNumberIssued=0;   // Sequential employee number

	// Default constructor
	Employee::Employee()
	{
		lastEmployeeNumberIssued++;
		employeeNumber = lastEmployeeNumberIssued;
		employeeName = "";
		hireDate = "";
	}


	// Constructor
	Employee::Employee(string aName, string aDate)
	{
		lastEmployeeNumberIssued++;
		employeeNumber = lastEmployeeNumberIssued;
		employeeName = aName;
		hireDate = aDate;
	}

	// Mutators
	void Employee::setEmployeeName(string n)
	{
		employeeName = n;
	}

	void Employee::setHireDate(string date)
	{
		hireDate = date;
		TestHireDate(date);
	}

	// Accessors
	string Employee::getEmployeeName() const
	{
		return employeeName;
	}

	int Employee::getEmployeeNumber() const
	{
		return employeeNumber;
	}

	string Employee::getHireDate() const
	{
		return hireDate;
	}

	int Employee::getLastEmployeeNumberIssued()
	{
		return lastEmployeeNumberIssued;
	}

	void Employee::TestHireDate(string date)
	{	
		if (date.length() < 10 || date[2] !='/' || date[5] != '/')
		{
			throw InvalidHireDate();
		}
		
		for (int i = 0; i < 10; i++)
		{
			if (i != 2 && i != 5) {
				if (!isdigit(date[i])) {
					throw InvalidHireDate();
				}
			}
		}
		
	}

	
	