#include "pch.h"
#include "Repair_Info.h"

Repair_Info::Repair_Info()
{
}

Repair_Info::Repair_Info(string repairNumber, string dormBuilding, string dormitoryNumber, string repair_time, string question, string situation)
{
	_repairNumber = repairNumber;
	_dormBuilding = dormBuilding;
	_dormitoryNumber = dormitoryNumber;
	_repair_time = repair_time;
	_question = question;
	_situation = situation;
}

void Repair_Info::set_repairNumber(string repairNumber)
{
	_repairNumber = repairNumber;
}

void Repair_Info::set_situation(string situation)
{
	_situation = situation;
}
