#pragma once

#include <vector>
#include "Common.h"
using namespace std;

class IEmployeeManagementSystem
{
public:
	virtual ~IEmployeeManagementSystem() {};
	virtual string testMock() = 0;
};

class EmployeeManagementSystem : public IEmployeeManagementSystem
{
public:
	virtual string testMock() override {};

	void inputCommand(string command);
	void add(Employee employee);
	void del(string condition, string keyword);
	void sch(string condition, string keyword);
	void mod(string condition, string keyword, string targetCondition, string targetKeyword);
	void printResult();
	string getResultStr();

private:
	vector<Employee> employees_;
};