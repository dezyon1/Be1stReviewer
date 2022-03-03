#include <iostream>
#include <fstream>
#include <string>
#include "EmployeeManagementSystem.h"
#include "employee.h"

using namespace std;

enum EmployeeInfoSequence
{
	Command,
	Option1,
	Option2,
	Option3,
	EmployeeNumber,
	Name,
	CL,
	PhoneNumber,
	Birth,
	CERTI,
	EmployeeInfoCount
};

void splitLine(string employeeInfoSeq[EmployeeInfoCount], string inputLine);
EmployeeInfo fillInfo(string employeeInfoSeq[EmployeeInfoCount]);
void manage(EmployeeManagementSystem* employeeManagementSystem, string cmd, Employee* employee);

int main(int argc, char** argv) 
{	
	EmployeeManagementSystem* employeeManagementSystem = new EmployeeManagementSystem();

	ifstream inputFile;
	inputFile.open("input.txt");

	if (inputFile.is_open() == false) 
	{
		return false;
	}

	string inputLine;
	while (getline(inputFile, inputLine))
	{
		string employeeInfoSeq[EmployeeInfoCount];
		splitLine(employeeInfoSeq, inputLine);
		
		EmployeeInfo employeeInfo = fillInfo(employeeInfoSeq);
		Employee* employee = new Employee(employeeInfo);

		manage(employeeManagementSystem, employeeInfoSeq[Command], employee);
	}

	inputFile.close();
	
	return 0;
}

void splitLine(string employeeInfoSeq[EmployeeInfoCount], string inputLine)
{
	int sequence = 0;
	int previous = 0;
	int current = inputLine.find(',');

	while (current != string::npos)
	{
		string substring = inputLine.substr(previous, current - previous);
		employeeInfoSeq[sequence++] = substring;
		previous = current + 1;
		current = inputLine.find(',', previous);
	}
	employeeInfoSeq[sequence] = inputLine.substr(previous, current - previous);
}

EmployeeInfo fillInfo(string employeeInfoSeq[EmployeeInfoCount])
{
	EmployeeInfo employeeInfo;
	employeeInfo.employeeNumber = employeeInfoSeq[EmployeeNumber];
	employeeInfo.name = employeeInfoSeq[Name];
	employeeInfo.cl = employeeInfoSeq[CL];
	employeeInfo.phoneNumber = employeeInfoSeq[PhoneNumber];
	employeeInfo.birth = employeeInfoSeq[Birth];
	employeeInfo.certi = employeeInfoSeq[CERTI];
	return employeeInfo;
}

void manage(EmployeeManagementSystem* employeeManagementSystem, string cmd, Employee* employee)
{
	if (cmd == ADD)
	{
		employeeManagementSystem->add(employee);
	}

	if (cmd == DELETE)
	{
		employeeManagementSystem->del(employee);
	}

	if (cmd == SEARCH)
	{
		employeeManagementSystem->sch(employee);
	}

	if (cmd == MODIFY)
	{
		employeeManagementSystem->mod(employee);
	}
}
