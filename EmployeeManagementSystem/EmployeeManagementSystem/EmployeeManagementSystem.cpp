#include <iostream>
#include <string>
#include "EmployeeManagementSystem.h"
#include "employee.h"
#include "input_validation.h"

using namespace std;

string EmployeeManagementSystem::runCommand(string command)
{
	string result;
	if (!isValidInput(command))
		throw invalid_argument("�Է� ���Ŀ� ������ �ֽ��ϴ�: " + command);

	if (command.find_first_of("ADD") == 0) {

	}

	if (command.find_first_of("DEL") == 0) {

	}

	if (command.find_first_of("MOD") == 0) {

	}

	if (command.find_first_of("SCH") == 0) {

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