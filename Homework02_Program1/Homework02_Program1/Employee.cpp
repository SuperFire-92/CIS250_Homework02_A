#include "Employee.h"
#include "Department.h"
#include <iostream>
#include <iomanip>

using namespace std;

Employee::Employee()
{
	empNum = 0;
	ssn = "";
	fName = "";
	lName = "";
	mInitial = ' ';
	city = "";
	state = "";
	age = 0;
	gender = ' ';
}

void Employee::displayEmployeeData(int numOfEmployees)
{
	cout << "Employee #" << setfill('0') << setw(log10(numOfEmployees) + 1) << empNum << endl;
	cout << "=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=" << endl;
	cout << "SSN             : " << getSsn() << endl;
	cout << "First Name      : " << getFName() << endl;
	cout << "Last Name       : " << getLName() << endl;
	cout << "Middle Initial  : " << getMInitial() << endl;
	cout << "City            : " << getCity() << endl;
	cout << "State           : " << getState() << endl;
	cout << "Age             : " << getAge() << endl;
	cout << "Gender          : " << getGender() << endl;
	cout << "Department ID   : " << getDep().getDepId() << endl;
	cout << "Department Name : " << getDep().getDepName() << endl;
	cout << "Building Letter : " << getDep().getBuildingLetter() << endl;
	cout << "Building Floor  : " << getDep().getBuildingFloor() << endl;
	cout << "Phone Number    : " << getDep().getDepPhoneNumber() << endl;
	cout << endl << endl;
}

void Employee::displayBuildingData(string building)
{
	system("CLS");
	cout << building << " Building" << endl;
	cout << "=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=" << endl;
	cout << "Building Letter : " << dep.getBuildingLetter() << endl;
	cout << "Building Floor  : " << dep.getBuildingFloor() << endl;
}

string Employee::getSimplifiedSsn()
{
	string newSsn;
	for (int i = 0; i < ssn.length(); i++)
	{
		if (isdigit(ssn.at(i)))
		{
			newSsn = newSsn + ssn.at(i);
		}
	}
	return newSsn;
}

string Employee::getSimplifiedSsn(string inputSsn)
{
	string newSsn;
	for (int i = 0; i < inputSsn.length(); i++)
	{
		if (isdigit(inputSsn.at(i)))
		{
			newSsn = newSsn + inputSsn.at(i);
		}
	}
	return newSsn;
}

//Getters
//=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=
int Employee::getEmpNum() const
{
	return empNum;
}

string Employee::getSsn() const
{
	return ssn;
}

string Employee::getFName() const
{
	return fName;
}

string Employee::getLName() const
{
	return lName;
}

char Employee::getMInitial() const
{
	return mInitial;
}

string Employee::getCity() const
{
	return city;
}

string Employee::getState() const
{
	return state;
}

int Employee::getAge() const
{
	return age;
}

char Employee::getGender() const
{
	return gender;
}

Department Employee::getDep() const
{
	return dep;
}

//Setters
//=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=
void Employee::setEmpNum(int e)
{
	empNum = e;
}

void Employee::setSsn(string s)
{
	ssn = s;
}

void Employee::setFName(string f)
{
	fName = f;
}

void Employee::setLName(string l)
{
	lName = l;
}

void Employee::setMInitial(char m)
{
	mInitial = m;
}

void Employee::setCity(string c)
{
	city = c;
}

void Employee::setState(string s)
{
	state = s;
}

void Employee::setAge(int a)
{
	age = a;
}

void Employee::setGender(char g)
{
	gender = g;
}

void Employee::setDep(Department d)
{
	dep = d;
}

//Setters (for setting department information)
//=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=
void Employee::setDepId(int newDepId)
{
	dep.setDepId(newDepId);
}

void Employee::setDepName(string newDepName)
{
	dep.setDepName(newDepName);
}

void Employee::setBuildingLetter(char newBuildingLetter)
{
	dep.setBuildingLetter(newBuildingLetter);
}

void Employee::setBuildingFloor(int newBuildingFloor)
{
	dep.setBuildingFloor(newBuildingFloor);
}

void Employee::setDepPhoneNumber(string newDepPhoneNumber)
{
	dep.setDepPhoneNumber(newDepPhoneNumber);
}