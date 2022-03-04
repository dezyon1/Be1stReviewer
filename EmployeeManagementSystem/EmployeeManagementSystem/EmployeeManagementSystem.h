#pragma once

#include <vector>
#include "Common.h"
#include "Database.h"
using namespace std;

class IEmployeeManagementSystem
{
public:
	virtual ~IEmployeeManagementSystem() {};
	virtual void testMock() = 0;
};

class EmployeeManagementSystem : public IEmployeeManagementSystem
{
public:
	virtual void testMock() override {};

	string runCommand(string command);
	EmployeeManagementSystem(IDatabase<Employee>& database) : database_(database) {};

private:
	string add(string command);
	string del(string command);
	string mod(string command);
	string sch(string command);
	string resultToString(vector<Employee> result, string option, string command);
	IDatabase<Employee>& database_;
};