#pragma once
#include <string>
#include <vector>
#include "Common.h"
#include "EmployeeManagementSystem.h"

using namespace std;

class Employee {
public:
	~Employee() {};
	Employee(string employeeNumber, string name, string cl, string phoneNumber, string birth, string certi) : cl_(cl), phoneNumber_(phoneNumber), birth_(birth), certi_(certi) {
		setName(name);
		setEmployeeNumber(employeeNumber);
	};

	bool isMatch(string const& column, string const& keyword);
	bool isMatch(string const& column, string const& keyword, string const & option);
	string getValue(string const& column);
	void setValue(string const& column, string const & value);
	bool operator<(const Employee& e) {
		return employeeID_ < e.employeeID_;
	};
	bool operator==(Employee& e) const {
		if (employeeNumber_ == e.employeeNumber_) {
			return true;
		}
		else {
			return false;
		}
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
	void setEmployeeNumber(string const& employeeNumber);
	string employeeNumber_;
	int employeeID_;
	string name_;
	string cl_;
	string phoneNumber_;
	string birth_;
	string certi_;

	string firstName_;
	string lastName_;
};