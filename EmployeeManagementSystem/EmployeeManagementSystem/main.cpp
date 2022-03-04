#include <iostream>
#include <fstream>
#include <string>
#include "EmployeeManagementSystem.h"
#include "Employee.h"
#include "Database.h"

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

int main(int argc, char** argv)
{
	VectorDatabase<Employee> DB;
	EmployeeManagementSystem* employeeManagementSystem = new EmployeeManagementSystem(DB);
	
	ifstream inputFile;
	ofstream outputFile;

	inputFile.open("input.txt");
	outputFile.open("output.txt");
	if (inputFile.is_open() == false)
	{
		return false;
	}
	if (outputFile.is_open() == false)
	{
		return false;
	}

	string inputLine;
	while (getline(inputFile, inputLine))
	{
		string result = employeeManagementSystem->runCommand(inputLine);
		outputFile << result << endl;
	}

	inputFile.close();
	outputFile.close();

	return 0;
}