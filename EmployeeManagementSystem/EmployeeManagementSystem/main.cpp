#include <iostream>
#include <fstream>
#include <string>
#include "EmployeeManagementSystem.h"
#include "Employee.h"

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
	VectorDatabase<Employee> vDB;
	EmployeeManagementSystem* employeeManagementSystem = new EmployeeManagementSystem(vDB);

	remove("output.txt");

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
		
		if (!result.empty()) {
			outputFile << result << endl;
		}
	}

	inputFile.close();
	outputFile.close();

	return 0;
}