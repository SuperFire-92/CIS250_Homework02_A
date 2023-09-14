#pragma once
#include "Employee.h"
#include "Department.h"

using namespace std;

class Holder
{
private:
	//A pointer that will store a dynamic array of all the employees in the list
	Employee* listOfEmployees;
	//An integer to store the number of employees in the company
	int numOfEmployees;
public:
	Holder();
	Holder(string);

	void readTextFile(string);
	void displayMenu();
	void displayAllEmployees();
	void displayOldestEmployee();
	void displayComputerScienceBuilding();
	void displayBuildingADepartments();
	void displayEmployeeSSN();
	void displayAverageAge();

	//getters
	Employee* getListOfEmployees();
	int getNumOfEmployees();

	//no setters for listOfEmployees or numOfEmployees, due to it being unnecessary
};

