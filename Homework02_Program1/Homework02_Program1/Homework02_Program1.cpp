//=============================================
//Name: Nicolaas Dyk
//Date: 03-05-2023
//Desc: Parsing through a .txt file and displaying
//		the information using classes and pointers
//=============================================

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include "Employee.h"
#include "Department.h"
#include "Holder.h"

using namespace std;

string userChoice();

int main()
{
	//=~=~=~=~=~=~=~=~=~=~=~=~=~=~=
	//=~= Variable Declaration  =~=
	//=~=~=~=~=~=~=~=~=~=~=~=~=~=~=

	//Holder which will immediately parse through the file
	Holder listOfEmployees("EmployeeList.txt");

	//Boolean to see if the program should continue running
	bool keepRunning = true;

	//String to see what option the user chose
	string choice;

	//=~=~=~=~=~=~=~=~=~=~=~=~=~=~=
	//=~=   Display The Menus   =~=
	//=~=~=~=~=~=~=~=~=~=~=~=~=~=~=
	listOfEmployees.displayMenu();
	while (keepRunning)
	{
		//Get the user's choice
		choice = userChoice();

		//Run different functions based on what the user chose
		if (choice == "-999")
		{
			keepRunning = !keepRunning;
		}
		if (choice == "0")
		{
			listOfEmployees.displayMenu();
		}
		if (choice == "1")
		{
			listOfEmployees.displayAllEmployees();
		}
		if (choice == "2")
		{
			listOfEmployees.displayOldestEmployee();
		}
		if (choice == "3")
		{
			listOfEmployees.displayComputerScienceBuilding();
		}
		if (choice == "4")
		{
			listOfEmployees.displayBuildingADepartments();
		}
		if (choice == "5")
		{
			listOfEmployees.displayEmployeeSSN();
		}
		if (choice == "6")
		{
			listOfEmployees.displayAverageAge();
		}
	}
}

//Gets the user's option choice
string userChoice()
{
	string choice;
	
	cout << "Enter Your Selection (0 for menu, -999 to exit): ";
	cin >> choice;
	return choice;
}
