#pragma once
#include <iostream>
#include "Department.h"

using namespace std;

class Employee
{
private:
    //used to keep track of what number the employee is in the array
    int empNum;

    //social security number
    string ssn;
    //first name
    string fName;
    //last name
    string lName;
    //middle initial
    char mInitial;
    //city
    string city;
    //state
    string state;
    //age
    int age;
    //gender
    char gender;
    //department info
    Department dep;

public:
    Employee();

    void displayEmployeeData(int);
    void displayBuildingData(string);
    string getSimplifiedSsn();
    string getSimplifiedSsn(string);

    //getters
    int getEmpNum() const;
    string getSsn() const;
    string getFName() const;
    string getLName() const;
    char getMInitial() const;
    string getCity() const;
    string getState() const;
    int getAge() const;
    char getGender() const;
    Department getDep() const;
    
    //setters
    void setEmpNum(int);
    void setSsn(string);
    void setFName(string);
    void setLName(string);
    void setMInitial(char);
    void setCity(string);
    void setState(string);
    void setAge(int);
    void setGender(char);
    void setDep(Department);

    void setDepId(int);
    void setDepName(string);
    void setBuildingLetter(char);
    void setBuildingFloor(int);
    void setDepPhoneNumber(string);
};

