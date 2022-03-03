#include <string>
#include <vector>
#include "input_validation.h"

using std::vector;
using std::string;


bool is4digits(const string& digits) {
	if (digits.length() != 4)
		return false;
	for (auto c : digits)
		if (c < '0' || c > '9')
			return false;
	return true;
}

bool isValidPhoneNum(const string& phoneNum) {
	if (phoneNum.length() != 13)
		return false;
	if (phoneNum.substr(0, 4).compare("010-"))
		return false;
	if (!is4digits(phoneNum.substr(4, 4)))
		return false;
	if (phoneNum[8] != '-')
		return false;
	if (!is4digits(phoneNum.substr(9, 4)))
		return false;
	return true;
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
	if (employeeNum.length() != 8)
		return false;

	for (auto c : employeeNum)
		if (c < '0' || c > '9')
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
	if (birthday.length() != 8)
		return false;

	for (auto c : birthday) {
		if (c < '0' || c > '9')
			return false;
	}

	return checkDate(atoi(birthday.substr(4, 2).c_str()), atoi(birthday.substr(6, 2).c_str()), atoi(birthday.substr(0, 4).c_str()));
}

bool isValidAddInput(vector<string> input_tokens) {
	if (input_tokens.size() != 10)
		return false;
	if (input_tokens[0].compare("ADD"))
		return false;
	if (input_tokens[1].compare(" ") || input_tokens[2].compare(" ") || input_tokens[3].compare(" "))
		return false;

	return true;
}

bool is_valid_input(std::string input) {
	return true;
}