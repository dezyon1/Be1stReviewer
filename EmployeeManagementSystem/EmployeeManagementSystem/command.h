#pragma once
#include <string>
#include <sstream>
#include <algorithm>
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
	virtual string run(IDatabase<Employee>& database) = 0;
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
	
	virtual string run(IDatabase<Employee>& database) override
	{
		Employee employee = Employee(employeeNum, name, cl, phoneNum, birthday, certi);
		database.add(employee);
		return string("");
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
	
	virtual string run(IDatabase<Employee>& database) = 0;

protected:
	string resultToString(vector<Employee> result, string option, string command)
	{
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

	string option1;
	string option2;
	string searchColumn;
	string searchValue;
};

class DelCommand : public iSchCommand {
public:
	DelCommand(string command):iSchCommand(command){
	};
	string run(IDatabase<Employee>& database) override
	{
		vector<Employee> result = database.del(searchColumn, searchValue, option2);
		return resultToString(result, option1, "DEL");
	};
};

class SchCommand : public iSchCommand {
public:
	SchCommand(string command) :iSchCommand(command) {
	};
	string run(IDatabase<Employee>& database) override
	{
		vector<Employee> result = database.sch(searchColumn, searchValue, option2);

		return resultToString(result, option1, "SCH");
	};
};

class ModCommand : public iSchCommand {
public:
	ModCommand(string command) :iSchCommand(command) {
		modColumn = commandTokens[6];
		modValue = commandTokens[7];
	}
	
	string run(IDatabase<Employee>& database) override
	{
		vector<Employee> result = database.mod(searchColumn, searchValue, option2, modColumn, modValue);
		return resultToString(result, option1, "MOD");
	};
private:
	string modColumn;
	string modValue;
};

class ICommandFactory {
public:
	virtual iCommand* createCommand(string command) = 0;
};

class CommandFactory : public ICommandFactory {
public:
	iCommand* createCommand(string command) override {

		if (command.find("ADD") == 0) {
			return new AddCommand(command);
		}

		if (command.find("DEL") == 0) {
			return new DelCommand(command);
		}

		if (command.find("SCH") == 0) {
			return new SchCommand(command);
		}

		if (command.find("MOD") == 0) {
			return new ModCommand(command);
		}

		throw invalid_argument("객체를 생성할 수 없습니다");
	}
};
