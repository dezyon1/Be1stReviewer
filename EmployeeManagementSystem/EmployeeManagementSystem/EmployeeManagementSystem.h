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
	string add(string command);
	string del(string command);
	string mod(string command);
	string sch(string command);
	string resultToString(vector<Employee> result, string option, string command);
	IDatabase<Employee>& database_;
};