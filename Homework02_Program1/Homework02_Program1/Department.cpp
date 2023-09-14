#include "Department.h"
#include <iostream>

using namespace std;

Department::Department()
{
	depId = 0;
	depName = "";
	buildingLetter = ' ';
	buildingFloor = 0;
	depPhoneNumber = "";
}

//Getters
//=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=
int Department::getDepId() const
{
	return depId;
}

string Department::getDepName() const
{
	return depName;
}

char Department::getBuildingLetter() const
{
	return buildingLetter;
}

int Department::getBuildingFloor() const
{
	return buildingFloor;
}

string Department::getDepPhoneNumber() const
{
	return depPhoneNumber;
}

//Setters
//=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=
void Department::setDepId(int newDepId)
{
	depId = newDepId;
}

void Department::setDepName(string newDepName)
{
	depName = newDepName;
}

void Department::setBuildingLetter(char newBuildingLetter)
{
	buildingLetter = newBuildingLetter;
}

void Department::setBuildingFloor(int newBuildingFloor)
{
	buildingFloor = newBuildingFloor;
}

void Department::setDepPhoneNumber(string newDepPhoneNumber)
{
	depPhoneNumber = newDepPhoneNumber;
}