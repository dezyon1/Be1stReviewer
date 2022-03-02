#pragma once
#include <string>
#include "EmployeeManagementSystem.h"

using namespace std;

class Employee {
public:
	~Employee() {};
	Employee(IEmployeeManagementSystem& manage, unsigned int employeeNum, string name,
		string cl, string phoneNum, string birthday, string certi) :
		manage_(manage), employeeNum_(employeeNum), name_(name), cl_(cl), phoneNum_(phoneNum),
		birthday_(birthday), certi_(certi) {};

	string test()
	{
		return manage_.testMock();
	}
protected:
	IEmployeeManagementSystem& manage_;

private:
	unsigned int employeeNum_;
	string name_;
	string cl_;
	string phoneNum_;
	string birthday_;
	string certi_;
};