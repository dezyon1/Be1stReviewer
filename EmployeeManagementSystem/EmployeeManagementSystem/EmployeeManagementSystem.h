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
	EmployeeManagementSystem(IDatabase<Employee>& database) : database_(database) {};

	virtual void testMock() override {};

	string runCommand(string command);

private:
	IDatabase<Employee>& database_;

	string add(string command);
	string del(string command);
	string mod(string command);
	string sch(string command);
};