#pragma once
class Repair_Info
{
public:
	string _repairNumber;
	string _dormBuilding;
	string _dormitoryNumber;
	string _repair_time;
	string _question;
	string _situation;

	Repair_Info();
	Repair_Info(string repairNumber,
		string dormBuilding,
		string dormitoryNumber,
		string repair_time,
		string question,
		string situation);
	void set_repairNumber(string repairNumber);
	void set_situation(string situation);
};

