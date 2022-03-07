#include "Employee.h"
#include <regex>
#include <sstream>

using namespace StringValue;

bool Employee::isMatch(string const& column, string const& keyword) {
	if (column == employeeNumStr)
		return !keyword.compare(employeeNumber_);

	if (column == nameStr)
		return !keyword.compare(name_);

	if (column == clStr)
		return !keyword.compare(cl_);
	
	if (column == phoneNumStr)
		return !keyword.compare(phoneNumber_);

	if (column == birthStr)
		return !keyword.compare(birth_);

	if (column == certiStr)
		return !keyword.compare(certi_);

	return false;
}

bool Employee::isMatch(string const& column, string const& keyword, string const & option) {
	if (option == emptyOptionStr || column == employeeNumStr || column == clStr || column == certiStr) {
		return isMatch(column, keyword);
	}
	if (column == nameStr) {
		if (option == fOptionStr)
			return !keyword.compare(firstName_);
		if (option == lOptionStr)
			return !keyword.compare(lastName_);
		return false;
	}
	
	if (column == phoneNumStr) {
		std::regex* re;
		if (option == mOptionStr)
			re = new std::regex("010-" + keyword + "-\\d{4}");
		else if (option == lOptionStr)
			re = new std::regex("010-\\d{4}-" + keyword);
		else
			return false;
		bool result = std::regex_match(phoneNumber_, *re);
		delete re;
		return result;
	}
	if (column == birthStr) {
		std::regex* re;
		if (option == yOptionStr)
			re = new std::regex(keyword + "\\d{4}");
		else if (option == mOptionStr)
			re = new std::regex("\\d{4}" + keyword + "\\d{2}");
		else if (option == dOptionStr)
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
	if (column == employeeNumStr)
		return employeeNumber_;
	if (column == nameStr)
		return name_;
	if (column == clStr)
		return cl_;
	if (column == phoneNumStr)
		return phoneNumber_;
	if (column == birthStr)
		return birth_;
	if (column == certiStr)
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
	if (column == employeeNumStr)
		employeeNumber_ = value;
	if (column == nameStr)
		setName(value);
	if (column == clStr)
		cl_ = value;
	if (column == phoneNumStr)
		phoneNumber_ = value;
	if (column == birthStr)
		birth_ = value;
	if (column == certiStr)
		certi_ = value;
	
}
