#pragma once
#include <string>
#include <sstream>
#include <vector>
#include "InputValidation.h"
#include "Database.h"

using std::vector;
using std::string;

class iCommand {
public:
	iCommand(string command) {
		if (!isValidInput(command))
			throw std::invalid_argument("입력 형식이 잘못되었습니다. : " + command);
		std::stringstream ss(command);
		string temp;

		while (getline(ss, temp, ',')) {
			commandTokens.push_back(temp);
		}
	}
protected:
	vector<string> commandTokens;
};

class AddCommand : public iCommand {
public:
	AddCommand(string command) :iCommand(command) {

	}
private:
	string employeeNum;
	string name;
	string cl;
	string phoneNum;
	string birthday;
	string certi;
};

class iSchCommand : public iCommand{
public:
	iSchCommand(string command) :iCommand(command) {
		option1 = commandTokens[1];
		option2 = commandTokens[2];
		searchColumn = commandTokens[3];
		searchValue = commandTokens[4];
	}
protected:
	string option1;
	string option2;
	string searchColumn;
	string searchValue;
};

class DelCommand : public iSchCommand {
public:
	DelCommand(string command):iSchCommand(command){
	};
};

class SchCommand : public iSchCommand {
public:
	SchCommand(string command) :iSchCommand(command) {
	};
};

class ModCommand : public iSchCommand {
public:
	ModCommand(string command) :iSchCommand(command) {
		modColumn = commandTokens[5];
		modValue = commandTokens[6];
	}

	string run(IDatabase<Employee>* database);
private:
	string modColumn;
	string modValue;
};
