#include "Holder.h"
#include "Employee.h"
#include "Department.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

Holder::Holder()
{

}
//If provided with the fileName during construction, it will parse through the file immediately
Holder::Holder(string fileName)
{
	readTextFile(fileName);
}

//Uses the given string fileName to find the file and parse through it and store it into listOfEmployees
void Holder::readTextFile(string fileName)
{
	ifstream inputFile;
	string lineOfText;
	char delim = ',';
	int commaPos;
	int i = 0;

	//Open the file
	inputFile.open(fileName);

	//Check to see if the file is open
	if (inputFile)
	{
		//cout << "File Found" << endl;

		//Find the length of the file
		while (getline(inputFile, lineOfText))
		{
			numOfEmployees++;
		}
		inputFile.close();
		//Set listOfEmployees to an array the length of the file
		listOfEmployees = new Employee[numOfEmployees];
		lineOfText = "";

		inputFile.open(fileName);
		//Parse the data into listOfEmployees
		while (getline(inputFile, lineOfText))
		{
			//Set up two variables within the Employee that will be used on the regular
			listOfEmployees[i].setEmpNum(i);

			//Assign the ssn
			commaPos = lineOfText.find(delim);
			listOfEmployees[i].setSsn(lineOfText.substr(0, commaPos));
			lineOfText = lineOfText.substr(commaPos + 1);

			//Assign the fName
			commaPos = lineOfText.find(delim);
			listOfEmployees[i].setFName(lineOfText.substr(0, commaPos));
			lineOfText = lineOfText.substr(commaPos + 1);

			//Assign the lName
			commaPos = lineOfText.find(delim);
			listOfEmployees[i].setLName(lineOfText.substr(0, commaPos));
			lineOfText = lineOfText.substr(commaPos + 1);

			//Assign the mInitial (Chars don't require finding the comma)
			listOfEmployees[i].setMInitial(lineOfText.at(0));
			lineOfText = lineOfText.substr(2);

			//Assign the city
			commaPos = lineOfText.find(delim);
			listOfEmployees[i].setCity(lineOfText.substr(0, commaPos));
			lineOfText = lineOfText.substr(commaPos + 1);

			//Assign the state
			commaPos = lineOfText.find(delim);
			listOfEmployees[i].setState(lineOfText.substr(0, commaPos));
			lineOfText = lineOfText.substr(commaPos + 1);

			//Assign the age
			commaPos = lineOfText.find(delim);
			listOfEmployees[i].setAge(stoi(lineOfText.substr(0, commaPos)));
			lineOfText = lineOfText.substr(commaPos + 1);

			//Assign the gender
			listOfEmployees[i].setGender(lineOfText.at(0));
			lineOfText = lineOfText.substr(2);

			//Assign the depId
			commaPos = lineOfText.find(delim);
			listOfEmployees[i].setDepId(stoi(lineOfText.substr(0, commaPos)));
			lineOfText = lineOfText.substr(commaPos + 1);

			//Assign the depName
			commaPos = lineOfText.find(delim);
			listOfEmployees[i].setDepName(lineOfText.substr(0, commaPos));
			lineOfText = lineOfText.substr(commaPos + 1);

			//Assign the buildingLetter
			listOfEmployees[i].setBuildingLetter(lineOfText.at(0));
			lineOfText = lineOfText.substr(2);

			//Assign the buildingFloor
			commaPos = lineOfText.find(delim);
			listOfEmployees[i].setBuildingFloor(stoi(lineOfText.substr(0, commaPos)));
			lineOfText = lineOfText.substr(commaPos + 1);

			//Assign the depPhoneNumber
			listOfEmployees[i].setDepPhoneNumber(lineOfText);

			i++;
		}

		inputFile.close();
	}
	else
	{
		//cout << "File Not Found" << endl;
	}
}

//Display Functions
//==~~==~~==~~==~~==~~==~~==~~==~~==~~==

//Displays the menu of choices for the user
//=~=~= OPTION 0 =~=~=
void Holder::displayMenu()
{
	system("CLS");
	cout << "      EMPLOYEE INFORMATION MANAGER" << endl;
	cout << "=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=" << endl;
	cout << "   1. Display All Employees" << endl;
	cout << "   2. Display Name Of Oldest Employee" << endl;
	cout << "   3. Display The Building Letter And Floor For Computer Science Department" << endl;
	cout << "   4. Display Department Names Who Are In Building A" << endl;
	cout << "   5. Find An Employee And List Their Information" << endl;
	cout << "   6. Average Age Of Employees Who Live In Michigan" << endl;
	cout << "   0. Display Menu" << endl;
	cout << "-999. Exit The Program" << endl;
}

//Display all employees for the user
//=~=~= OPTION 1 =~=~=
void Holder::displayAllEmployees()
{
	system("CLS");
	for (int i = 0; i < numOfEmployees; i++)
	{
		listOfEmployees[i].displayEmployeeData(numOfEmployees);
	}
}

//Finds and displays the oldest employee
//=~=~= OPTION 2 =~=~=
void Holder::displayOldestEmployee()
{
	//Find the oldest employee
	int oldestEmployee = 0;
	int oldestEmployeeAge = listOfEmployees[0].getAge();
	for (int i = 1; i < numOfEmployees; i++)
	{
		if (listOfEmployees[i].getAge() > oldestEmployeeAge)
		{
			oldestEmployeeAge = listOfEmployees[i].getAge();
			oldestEmployee = i;
		}
	}

	//Display the oldest employee
	system("CLS");
	cout << "Oldest Employee Data" << endl;
	cout << "=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=" << endl;
	listOfEmployees[oldestEmployee].displayEmployeeData(numOfEmployees);
}

//Displays the Building Letter and Building Floor of the Computer Science building
//=~=~= OPTION 3 =~=~=
void Holder::displayComputerScienceBuilding()
{
	//Find the first employee in the Computer Science department
	int employeeNumber = -1;
	for (int i = 0; i < numOfEmployees && i != -999; i++)
	{
		if (listOfEmployees[i].getDep().getDepName() == "Computer Science")
		{
			employeeNumber = i;
			i = -1000;
		}
	}

	if (employeeNumber != -1)
	{
		//Display the information about the Computer Science building
		listOfEmployees[employeeNumber].displayBuildingData("Computer Science");
	}
	else
	{
		system("CLS");
		cout << "Computer Science Building" << endl;
		cout << "=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=" << endl;
		cout << "No Valid Computer Science Building Found" << endl;
	}
}

//Displays all departments in building A
//=~=~= OPTION 4 =~=~=
void Holder::displayBuildingADepartments()
{
	int sizeOfPointer = 0;
	//Create a pointer to store the departments in building A
	string* listOfDepartments = new string[sizeOfPointer];
	string* listOfDepartmentsTemp;
	//Add any departments to the list as long as they have not been added before
	for (int i = 0; i < numOfEmployees; i++)
	{
		if (listOfEmployees[i].getDep().getBuildingLetter() == 'A')
		{
			bool unentered = true;
			for (int j = 0; j < sizeOfPointer; j++)
			{
				if (listOfDepartments[j] == listOfEmployees[i].getDep().getDepName())
				{
					unentered = false;
				}
			}
			if (unentered)
			{
				//Temporarily transfers all items to listOfDepartmentsTemp, then resizes and puts the list back into itself along with the new string
				sizeOfPointer++;
				listOfDepartmentsTemp = listOfDepartments;
				listOfDepartments = new string[sizeOfPointer];
				for (int j = 0; j < sizeOfPointer - 1; j++)
				{
					listOfDepartments[j] = listOfDepartmentsTemp[j];
				}
				listOfDepartments[sizeOfPointer - 1] = listOfEmployees[i].getDep().getDepName();
			}
		}
	}

	//Display the departments
	system("CLS");
	cout << "Building A Departments" << endl;
	cout << "=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=" << endl;
	if (sizeOfPointer == 0)
	{
		cout << "No Valid Building A Departments Found" << endl;
	}
	else
	{
		for (int i = 0; i < sizeOfPointer; i++)
		{
			cout << listOfDepartments[i] << endl;
		}
	}
}

//Displays the details of an employee based off of the user's ssn input
//=~=~= OPTION 5 =~=~=
void Holder::displayEmployeeSSN()
{

	string ssn, tempSsn;
	int employeeLocation = -1;
	//Asks the user to enter the ssn of the employee
	system("CLS");
	cout << "Employee Finder" << endl;
	cout << "=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=" << endl;
	cout << "Enter the ssn for the employee: ";
	cin >> tempSsn;

	//Simplify the new ssn
	ssn = listOfEmployees[0].getSimplifiedSsn(tempSsn);

	//Find the matching social security number
	for (int i = 0; i < numOfEmployees && i != -999; i++)
	{
		string currentSSN = listOfEmployees[i].getSimplifiedSsn();
		if (currentSSN == ssn)
		{
			employeeLocation = i;
			i = -1000;
		}
	}

	//If the employee is found, it tell the user all of the information
	if (employeeLocation != -1)
	{
		cout << "=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=" << endl;
		listOfEmployees[employeeLocation].displayEmployeeData(numOfEmployees);
	}
	//If the employee is not found, it informs the user that the employee was not found
	else
	{
		cout << "=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=" << endl;
		cout << "The employee with an ssn of " << tempSsn << " does not exist" << endl;
	}
}

//Displays the average age of all employees in MI
//=~=~= OPTION 6 =~=~=
void Holder::displayAverageAge()
{
	//Keeps count of the total of all of the ages
	int count = 0;
	//Keeps count of all the employees that live in MI
	int miEmployees = 0;

	//Finds all employees in Michigan and adds their age to a counter
	for (int i = 0; i < numOfEmployees; i++)
	{
		if (listOfEmployees[i].getState() == "MI")
		{
			count += listOfEmployees[i].getAge();
			miEmployees++;
		}
	}

	//Display the average age of the employees in MI
	system("CLS");
	cout << "Average Age Of MI Employees" << endl;
	cout << "=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=" << endl;
	cout << "Average Age: " << double(count) / double(miEmployees) << endl;
}

//getters
Employee* Holder::getListOfEmployees()
{
	return listOfEmployees;
}
int Holder::getNumOfEmployees()
{
	return numOfEmployees;
}