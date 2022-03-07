#pragma once
#include <string>
#include <vector>
#include "Common.h"
#include "EmployeeManagementSystem.h"

using namespace std;

class Employee {
public:
	~Employee() {};
	Employee(string employeeNumber, string name, string cl, string phoneNumber, string birth, string certi) : employeeNumber_(employeeNumber), cl_(cl), phoneNumber_(phoneNumber), birth_(birth), certi_(certi) {
		setName(name);
	};

	bool isMatch(string const& column, string const& keyword);
	bool isMatch(string const& column, string const& keyword, string const & option);
	string getValue(string const& column);
	void setValue(string const& column, string const & value);
	bool operator<(const Employee& e) {
		string str1;
		string str2;
		if (employeeNumber_[0] <= '2') {
			str1 = "1" + employeeNumber_;
		}
		else {
			str1 = "0" + employeeNumber_;
		}
		if (e.employeeNumber_[0] <= '2') {
			str2 = "1" + e.employeeNumber_;
		}
		else {
			str2 = "0" + e.employeeNumber_;
		}
		return str1 < str2;
	};
	string toString() {
		return employeeNumber_ + "," +
			name_ + "," +
			cl_ + "," +
			phoneNumber_ + "," +
			birth_ + "," +
			certi_;
	};
private:
	void setName(string const &name);
	string employeeNumber_;
	string name_;
	string cl_;
	string phoneNumber_;
	string birth_;
	string certi_;

	string firstName_;
	string lastName_;
};