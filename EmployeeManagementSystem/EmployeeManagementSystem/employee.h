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
	void setData(string const& column, string const& value);

	string toString() {
		return m_employeeInfo.employeeNumber + "," + m_employeeInfo.name + "," +
			m_employeeInfo.cl + "," + m_employeeInfo.phoneNumber + "," +
			m_employeeInfo.birth + "," + m_employeeInfo.certi;
	}
private:
	EmployeeInfo m_employeeInfo;
};