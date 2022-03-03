#pragma once

#include <vector>
#include "Common.h"
using namespace std;

#define ADD "ADD"
#define DELETE "DEL"
#define SEARCH "SCH"
#define MODIFY "MOD"

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

	void add(Employee* employee);
	void del(Employee* employee);
	void sch(Employee* employee);
	void mod(Employee* employee);

	void inputCommand(string command);
	void printResult();
	string getResultStr();

private:
	vector<Employee> employees_;
};