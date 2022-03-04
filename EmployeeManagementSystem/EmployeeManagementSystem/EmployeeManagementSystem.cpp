#include <iostream>
#include <string>
#include <algorithm>
#include "EmployeeManagementSystem.h"
#include "Employee.h"
#include "InputValidation.h"
#include "Command.h"

using namespace std;

string EmployeeManagementSystem::runCommand(string command)
{
	string result;
	if (!isValidInput(command))
		throw invalid_argument("입력 형식에 오류가 있습니다: " + command);

	if (command.find("ADD") == 0) {
		AddCommand add_command = AddCommand(command);
		Employee employee = add_command.getEmployee();
		database_.add(employee);
		return string("");
	}

	if (command.find("DEL") == 0) {
		DelCommand del_command = DelCommand(command);
		vector<Employee> result = database_.del(del_command.getSearchColumn(), del_command.getSearchValue());

		return resultToString(result, del_command.getOption1(), "DEL");
	}

	if (command.find("MOD") == 0) {
		ModCommand mod_command = ModCommand(command);
		vector<Employee> result = database_.mod(mod_command.getSearchColumn(), mod_command.getSearchValue(), mod_command.getModColumn(), mod_command.getModValue());

		return resultToString(result, mod_command.getOption1(), "MOD");
	}

	if (command.find("SCH") == 0) {
		SchCommand sch_command = SchCommand(command);
		vector<Employee> result = database_.sch(sch_command.getSearchColumn(), sch_command.getSearchValue());

		return resultToString(result, sch_command.getOption1(), "SCH");
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

string EmployeeManagementSystem::resultToString(vector<Employee> result, string option, string command)
{
	if (command == "ADD")
		return string("");

	if (result.size() == 0)
		return string(command + ",NONE");

	if (option == "-p") {
		string str;
		sort(result.begin(), result.end());
		for (int i = 0; i < 5 && i < result.size(); i++) {
			if (i != 0)
				str += "\n";
			str += (command + "," + result[i].toString());
		}
		return str;
	}

	return command + "," + std::to_string(result.size());
}
