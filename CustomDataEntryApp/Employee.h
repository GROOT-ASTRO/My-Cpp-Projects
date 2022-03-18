// Specification file for the Employee class
#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <string>
using namespace std;

class Employee
{
private:
	static int lastEmployeeNumberIssued;   
	int employeeNumber;                    
	string employeeName;		           
	string hireDate;	                  

public:
	class InvalidHireDate {};

	// Constructors
	Employee();//Default constructor
	Employee(string aName, string aDate);
	
	// Mutators
	void setEmployeeName(string n);
	void setHireDate(string date);

	// Accessors
	string getEmployeeName() const;
	int getEmployeeNumber() const;
	string getHireDate() const;
	void TestHireDate(string date);
	static int getLastEmployeeNumberIssued();
};

#endif
