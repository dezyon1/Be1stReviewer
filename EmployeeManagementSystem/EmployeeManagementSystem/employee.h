#pragma once
#include <string>

using namespace std;

class Employee {
public:
	Employee(unsigned int employeeNum, string name,
		string cl, string phoneNum, string birthday, string certi) :
		employeeNum_(employeeNum), name_(name), cl_(cl), phoneNum_(phoneNum),
		birthday_(birthday), certi_(certi) {};
private:
	unsigned int employeeNum_;
	string name_;
	string cl_;
	string phoneNum_;
	string birthday_;
	string certi_;
};