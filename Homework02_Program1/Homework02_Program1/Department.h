#pragma once
#include <iostream>

using namespace std;

class Department
{
private:
    //department id
    int depId;
    //department name
    string depName;
    //building letter
    char buildingLetter;
    //building floor
    int buildingFloor;
    //department phone number
    string depPhoneNumber;
public:
    Department();

    int getDepId() const;
    string getDepName() const;
    char getBuildingLetter() const;
    int getBuildingFloor() const;
    string getDepPhoneNumber() const;

    void setDepId(int);
    void setDepName(string);
    void setBuildingLetter(char);
    void setBuildingFloor(int);
    void setDepPhoneNumber(string);
};