#include <iostream>
#include <string>
#include "EmployeeManagementSystem.h"
#include "Employee.h"
#include "InputValidation.h"
#include "Command.h"
#include "Database.h"

using namespace std;

string EmployeeManagementSystem::runCommand(string command)
{
	string result;
	if (!isValidInput(command))
		throw invalid_argument("입력 형식에 오류가 있습니다: " + command);

	if (command.find("ADD") == 0) {
		AddCommand add_command = AddCommand(command);
	}

	if (command.find("DEL") == 0) {
		DelCommand del_command = DelCommand(command);
	}

	if (command.find("MOD") == 0) {
		ModCommand mod_command = ModCommand(command);
		mod_command.run(database_);
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