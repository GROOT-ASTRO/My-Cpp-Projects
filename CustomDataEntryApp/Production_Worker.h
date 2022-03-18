// Specification file for the ProductionWorker Class
#ifndef PRODUCTION_WORKER_H
#define PRODUCTION_WORKER_H
#include <iostream>
#include <iomanip>
#include <string>
#include "Employee.h"
using namespace std;
class ProductionWorker : public Employee
{
private:
	int shift; 
	double payRate;

public:
	
	class InvalidPayRate{};
	class InvalidShift{};

	// Default constructor
	ProductionWorker() : Employee() {
		shift = 0; payRate = 0.0;
	}

	// Constructor
	ProductionWorker(string aName, string aDate, int aShift, double aPayRate)
		: Employee(aName, aDate) {
		shift = aShift; payRate = aPayRate;
		testpayrate(aPayRate);
		testShift(aShift);
		TestHireDate(aDate);
	}
	
	// Mutators
	void setShift(int s);
	void setPayRate(double r);


	// Accessors
	int getShiftNumber() const;
	string getShiftName() const;
	double getPayRate() const;
	void printWorkerDate() const;
	void printWorkerData() const;
	void testpayrate(double aPayRate);
	void testShift(int aShift);
	

	static ProductionWorker* createNewProductionWorker();
};
#endif