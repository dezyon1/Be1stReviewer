#include <string>
#include <vector>
#include <regex>
#include "Common.h"
#include "InputValidation.h"

using std::vector;
using std::string;
using std::regex;
using std::regex_match;

bool isValidPhoneNum(const string& phoneNum) {
	regex re("010-\\d{4}-\\d{4}");
	return regex_match(phoneNum, re);
}

bool isValidCL(const string& CL) {
	if (CL.length() != 3)
		return false;
	if (CL.substr(0, 2).compare("CL"))
		return false;
	if (CL[2] < '1' || CL[2] > '4')
		return false;
	return true;
}

bool isValidCerti(const string& certi) {
	return !certi.compare("ADV") || !certi.compare("PRO") || !certi.compare("EX");
}

bool isValidEmployeeNum(const string& employeeNum) {
	regex re("\\d{8}");
	if (!regex_match(employeeNum, re))
		return false;

	int num = atoi(employeeNum.substr(0, 2).c_str());
	if (num >= 22 && num <= 68)
		return false;

	return true;
}

bool isValidName(const string& name) {
	int count = 0;
	if (!(name.length() >= 3 && name.length() <= 15))
		return false;

	for (auto c : name) {
		if (!(c == ' ' || (c >= 'A' && c <= 'Z')))
			return false;
		if (c == ' ')
			count++;
	}
	if (count != 1)
		return false;

	return true;
}


bool checkDate(int m, int d, int y)
{
	//gregorian dates started in 1582
	if (!(1582 <= y))//comment these 2 lines out if it bothers you
		return false;
	if (!(1 <= m && m <= 12))
		return false;
	if (!(1 <= d && d <= 31))
		return false;
	if ((d == 31) && (m == 2 || m == 4 || m == 6 || m == 9 || m == 11))
		return false;
	if ((d == 30) && (m == 2))
		return false;
	if ((m == 2) && (d == 29) && (y % 4 != 0))
		return false;
	if ((m == 2) && (d == 29) && (y % 400 == 0))
		return true;
	if ((m == 2) && (d == 29) && (y % 100 == 0))
		return false;
	if ((m == 2) && (d == 29) && (y % 4 == 0))
		return true;

	return true;
}

bool isValidBirthday(const string& birthday) {
	regex re("\\d{8}");
	if (!regex_match(birthday, re))
		return false;

	return checkDate(atoi(birthday.substr(4, 2).c_str()), atoi(birthday.substr(6, 2).c_str()), atoi(birthday.substr(0, 4).c_str()));
}

bool isValidAddInput(const vector<string> & input_tokens) {
	if (input_tokens.size() != 10)
		return false;
	if (input_tokens[0].compare("ADD"))
		return false;
	if (input_tokens[1].compare(" ") || input_tokens[2].compare(" ") || input_tokens[3].compare(" "))
		return false;
	if (!isValidEmployeeNum(input_tokens[4]) || !isValidName(input_tokens[5]) || !isValidCL(input_tokens[6]) || !isValidPhoneNum(input_tokens[7])
		|| !isValidBirthday(input_tokens[8]) || !isValidCerti(input_tokens[9]))
		return false;
	return true;
}


bool optionValidation(const vector<string>& input_tokens) {
	const string & option1 = input_tokens[1];
	const string& option2 = input_tokens[2];
	const string& column_name = input_tokens[4];
	if (option1 != " " && option1 != "-p")
		return false;
	
	if (column_name == "cl" || column_name == "employeeNum" || column_name == "certi")
		if (option2 != " ")
			return false;

	if (column_name == "birthday")
		if (option2 != " " && option2 != "-y" && option2 != "-m" && option2 != "-d")
			return false;

	if (column_name == "name")
		if (option2 != " " && option2 != "-f" && option2 != "-l")
			return false;

	if (column_name == "phoneNum")
		if (option2 != " " && option2 != "-m" && option2 != "-l")
			return false;

	return true;
}

bool columnValidation(const string& columnName, const string& columnValue, const string & option2) {
	const char* columns[] = { "employeeNum", "name", "cl", "phoneNum", "birthday", "certi" };
	bool (*validationFP[6])(const string&) = { isValidEmployeeNum, isValidName, isValidCL, isValidPhoneNum, isValidBirthday, isValidCerti};

	if (option2 == " ")
	{
		for (int i = 0; i < 6; i++)
			if (columnName == columns[i])
				return validationFP[i](columnValue);
		return false;
	}

	if (columnName == "name") {
		regex re("[A-Z]{1,13}");
		return regex_match(columnValue, re);
	}

	if (columnName == "phoneNum") {
		regex re("\\d{4}");
		return regex_match(columnValue, re);
	}

	if (columnName == "birthday") {
		
		if (option2 == "-y") {
			regex re("\\d{4}");
			return regex_match(columnValue, re);
		}
		regex re("\\d{2}");
		return regex_match(columnValue, re);
	}
	return false;
}


bool isValidSchInput(const vector<string>& input_tokens) {
	if (input_tokens.size() != 6)
		return false;
	
	if (input_tokens[0].compare("SCH"))
		return false;
	
	if (input_tokens[3].compare(" "))
		return false;

	if (!optionValidation(input_tokens))
		return false;

	if (!columnValidation(input_tokens[4], input_tokens[5], input_tokens[2]))
		return false;

	return true;
}

bool isValidDelInput(const vector<string>& input_tokens) {
	if (input_tokens.size() != 6)
		return false;

	if (input_tokens[0].compare("DEL"))
		return false;

	if (input_tokens[3].compare(" "))
		return false;

	if (!optionValidation(input_tokens))
		return false;

	if (!columnValidation(input_tokens[4], input_tokens[5], input_tokens[2]))
		return false;

	return true;
}

bool isValidModInput(const vector<string>& input_tokens) {
	if (input_tokens.size() != 8)
		return false;

	if (input_tokens[0].compare("MOD"))
		return false;

	if (input_tokens[3].compare(" "))
		return false;

	if (!optionValidation(input_tokens))
		return false;

	if (!columnValidation(input_tokens[4], input_tokens[5], input_tokens[2]) || !columnValidation(input_tokens[6], input_tokens[7], " "))
		return false;

	return true;
}

bool isValidInput(std::string input) {
	vector<string> input_tokens = splitString(input, ',');

	if (input_tokens[0] == "ADD")
		return isValidAddInput(input_tokens);
	if (input_tokens[0] == "DEL")
		return isValidDelInput(input_tokens);
	if (input_tokens[0] == "SCH")
		return isValidSchInput(input_tokens);
	if (input_tokens[0] == "MOD")
		return isValidModInput(input_tokens);
	return false;
}