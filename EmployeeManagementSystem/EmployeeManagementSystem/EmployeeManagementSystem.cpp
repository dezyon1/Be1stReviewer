#include <iostream>
#include <algorithm>
#include <string>
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
	}

	if (command.find("DEL") == 0) {
		DelCommand del_command = DelCommand(command);

		string column = del_command.getSearchColumn();
		string value = del_command.getSearchValue();
		if (column.empty() || value.empty()) {
			return "";
		}

		auto result = database_.del(column, value);

		string opt1 = del_command.getOption1();
		//string opt2 = del_command.getOption2();
		if (opt1.empty()) {
			return to_string(result.size());
		}

		if (opt1 == "-p") {
			cout << "delete print" << endl;

			/* sorting */
			//std::sort(result.begin(), result.end(),
			//	[](Employee a, Employee b) {
			//		return a.getEmployeeID() < b.getEmployeeID();
			//	});

			int printCnt = 0;
			for (auto emp : result) {
				if (printCnt == 5) {
					break; 
				}
				cout << emp.getInfoStr() << endl;
				printCnt++;
			}
		}
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