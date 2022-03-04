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
	EmployeeManagementSystem(IDatabase<Employee>& database) : database_(database) {};
	string runCommand(string command);

private:
	string add(string command);
	string del(string command);
	string mod(string command);
	string sch(string command);
	IDatabase<Employee>& database_;
};