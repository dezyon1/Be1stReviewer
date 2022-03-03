#pragma once

#include <vector>
#include "Common.h"
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

private:
	string add(string command);
	string del(string command);
	string mod(string command);
	string sch(string command);
};