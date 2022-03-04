#include <iostream>
#include <string>
#include "Employee.h"
#include "EmployeeManagementSystem.h"
#include "InputValidation.h"
#include "Command.h"

using namespace std;

string EmployeeManagementSystem::runCommand(string command)
{
	string result;
	if (!isValidInput(command))
		throw invalid_argument("�Է� ���Ŀ� ������ �ֽ��ϴ�: " + command);

	if (command.find("ADD") == 0) {
		AddCommand add_command = AddCommand(command);
		EmployeeInfo employeeInfo = add_command.getEmployeeInfo(command);
		Employee employee(employeeInfo);
		database_.add(employee);
	}

	if (command.find("DEL") == 0) {
		DelCommand del_command = DelCommand(command);
	}

	if (command.find("MOD") == 0) {
		ModCommand mod_command = ModCommand(command);
	}

	if (command.find("SCH") == 0) {
		SchCommand sch_command = SchCommand(command);
	}

	return result;
}

string EmployeeManagementSystem::add(string command) {
	return "";
}

string EmployeeManagementSystem::del(string command) {
	return "";
}

string EmployeeManagementSystem::mod(string command) {
	return "";
}

string EmployeeManagementSystem::sch(string command) {
	return "";
}