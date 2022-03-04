#pragma once
#include <string>
#include <sstream>
#include <vector>
#include "InputValidation.h"
#include "employee.h"

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
		employeeNum = commandTokens[4];
		name = commandTokens[5];
		cl = commandTokens[6];
		phoneNum = commandTokens[7];
		birthday = commandTokens[8];
		certi = commandTokens[9];
	};
	Employee getEmployee() {
		return Employee(employeeNum, name, cl, phoneNum, birthday, certi);
	};
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
		searchColumn = commandTokens[4];
		searchValue = commandTokens[5];
	}
	const string& getOption1() {
		return option1;
	}
	const string& getOption2() {
		return option2;
	}
	const string& getSearchColumn() {
		return searchColumn;
	}
	const string& getSearchValue() {
		return searchValue;
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
		modColumn = commandTokens[6];
		modValue = commandTokens[7];
	}
	const string& getModColumn() {
		return modColumn;
	}
	const string& getModValue() {
		return modValue;
	}
private:
	string modColumn;
	string modValue;
};
