#pragma once
#include <string>
#include "EmployeeManagementSystem.h"

using namespace std;

struct EmployeeInfo
{
	string employeeNumber;
	string name;
	string cl;
	string phoneNumber;
	string birth;
	string certi;
};

class Employee {
public:
	~Employee() {};
	Employee(EmployeeInfo& employeeInfo) : m_employeeInfo(employeeInfo) {};

	bool isMatch(string const& column, string const& keyword);
	string getInfoStr();
	int getEmployeeID();

private:
	EmployeeInfo m_employeeInfo;
};