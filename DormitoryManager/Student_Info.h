#pragma once
class Student_Info
{
public:
	string _studentID;
	string _name;
	string _sex;
	string _major;
	string _stuclass;
	string _dormitoryNumber;
	string _dormBuilding;
	string _phone;

	Student_Info();
	Student_Info(string studentID,
		string name,
		string sex,
		string major,
		string stuclass,
		string dormitoryNumber,
		string dormBuilding,
		string phone);

};

