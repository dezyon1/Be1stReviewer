#pragma once

#include <vector>
#include "Common.h"
#include "Database.h"
using namespace std;

class IEmployeeManagementSystem
{
public:
	virtual ~IEmployeeManagementSystem() {};
	virtual string runCommand(string command) = 0;
};

class EmployeeManagementSystem : public IEmployeeManagementSystem
{
public:
	string runCommand(string command) override;
	EmployeeManagementSystem(IDatabase<Employee>& database) : database_(database) {};

private:
	IDatabase<Employee>& database_;
};