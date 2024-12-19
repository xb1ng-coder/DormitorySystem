#include "pch.h"
#include "Student_Info.h"

Student_Info::Student_Info()
{
}

Student_Info::Student_Info(string studentID, string name, string sex, string major, string stuclass, string dormitoryNumber, string dormBuilding, string phone)
{
	_studentID= studentID;
	_name= name;
	_sex= sex;
	_major= major;
	_stuclass= stuclass;
	_dormitoryNumber= dormitoryNumber;
	_dormBuilding= dormBuilding;
	_phone= phone;
}
