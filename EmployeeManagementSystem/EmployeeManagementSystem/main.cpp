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

	if (argc != 3) {
		cout << "EmployeeManagementSystem.exe input_filename.txt output_filename.txt" << endl;
		exit(1);
	}

	remove(argv[2]);

	ifstream inputFile;
	ofstream outputFile;

	inputFile.open(argv[1]);
	outputFile.open(argv[2]);

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