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
	IDatabase<Employee>& database_;
};