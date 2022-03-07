#include "Employee.h"
#include <regex>
#include <sstream>
#include "Common.h"

using namespace StringValue;

bool Employee::isMatch(string const& column, string const& keyword) {
	if (column == EMPLOYEE_NUM_STR)
		return !keyword.compare(employeeNumber_);

	if (column == NAME_STR)
		return !keyword.compare(name_);

	if (column == CL_STR)
		return !keyword.compare(cl_);
	
	if (column == PHONE_NUM_STR)
		return !keyword.compare(phoneNumber_);

	if (column == BIRTH_STR)
		return !keyword.compare(birth_);

	if (column == CERTI_STR)
		return !keyword.compare(certi_);

	return false;
}

bool Employee::isMatch(string const& column, string const& keyword, string const & option) {
	if (option == EMPTY_OPT_STR || column == EMPLOYEE_NUM_STR || column == CL_STR || column == CERTI_STR) {
		return isMatch(column, keyword);
	}
	if (column == NAME_STR) {
		if (option == F_OPT_STR)
			return !keyword.compare(firstName_);
		if (option == L_OPT_STR)
			return !keyword.compare(lastName_);
		return false;
	}
	
	if (column == PHONE_NUM_STR) {
		std::regex* re;
		if (option == M_OPT_STR)
			re = new std::regex("010-" + keyword + "-\\d{4}");
		else if (option == L_OPT_STR)
			re = new std::regex("010-\\d{4}-" + keyword);
		else
			return false;
		bool result = std::regex_match(phoneNumber_, *re);
		delete re;
		return result;
	}
	if (column == BIRTH_STR) {
		std::regex* re;
		if (option == Y_OPT_STR)
			re = new std::regex(keyword + "\\d{4}");
		else if (option == M_OPT_STR)
			re = new std::regex("\\d{4}" + keyword + "\\d{2}");
		else if (option == D_OPT_STR)
			re = new std::regex("\\d{6}" + keyword);
		else
			return false;
		bool result = std::regex_match(birth_, *re);
		delete re;
		return result;
	}
	return false;
}

string Employee::getValue(string const& column)
{
	if (column == EMPLOYEE_NUM_STR)
		return employeeNumber_;
	if (column == NAME_STR)
		return name_;
	if (column == CL_STR)
		return cl_;
	if (column == PHONE_NUM_STR)
		return phoneNumber_;
	if (column == BIRTH_STR)
		return birth_;
	if (column == CERTI_STR)
		return certi_;
	return string();
}

void Employee::setName(string const& name) {
	vector<string> fullName = splitString(name, ' ');
	name_ = name;
	firstName_ = fullName[0];
	lastName_ = fullName[1];
}

void Employee::setValue(string const& column, string const & value)
{
	if (column == EMPLOYEE_NUM_STR)
		employeeNumber_ = value;
	if (column == NAME_STR)
		setName(value);
	if (column == CL_STR)
		cl_ = value;
	if (column == PHONE_NUM_STR)
		phoneNumber_ = value;
	if (column == BIRTH_STR)
		birth_ = value;
	if (column == CERTI_STR)
		certi_ = value;
	
}
