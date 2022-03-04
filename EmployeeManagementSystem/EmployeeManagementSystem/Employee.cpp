#include "Employee.h"
#include <regex>
#include <sstream>

bool Employee::isMatch(string const& column, string const& keyword) {
	if (column == "employeeNum")
		return !keyword.compare(employeeNumber_);

	if (column == "name")
		return !keyword.compare(name_);

	if (column == "cl")
		return !keyword.compare(cl_);
	
	if (column == "phoneNum")
		return !keyword.compare(phoneNumber_);

	if (column == "birthday")
		return !keyword.compare(birth_);

	if (column == "certi")
		return !keyword.compare(certi_);

	return false;
}

bool Employee::isMatch(string const& column, string const& keyword, string const & option) {
	if (option == " " || column == "employeeNum" || column == "cl" || column == "certi") {
		return isMatch(column, keyword);
	}
	if (column == "name") {
		if (option == "-f") 
			return !keyword.compare(firstName_);
		if (option == "-l") 
			return !keyword.compare(lastName_);
		return false;
	}
	
	if (column == "phoneNum") {
		std::regex* re;
		if (option == "-m")
			re = new std::regex("010-" + keyword + "-\\d{4}");
		else if (option == "-l")
			re = new std::regex("010-\\d{4}-" + keyword);
		else
			return false;
		bool result = std::regex_match(phoneNumber_, *re);
		delete re;
		return result;
	}
	if (column == "birthday") {
		std::regex* re;
		if (option == "-y")
			re = new std::regex(keyword + "\\d{4}");
		else if (option == "-m")
			re = new std::regex("\\d{4}" + keyword + "\\d{2}");
		else if (option == "-d")
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
	if (column == "employeeNum") 
		return employeeNumber_;
	if (column == "name")
		return name_;
	if (column == "cl")
		return cl_;
	if (column == "phoneNum")
		return phoneNumber_;
	if (column == "birthday")
		return birth_;
	if (column == "certi")
		return certi_;
	return string();
}

void Employee::setValue(string const& column, string const & value)
{
	if (column == "employeeNum")
		employeeNumber_ = value;
	if (column == "name")
		name_ = value;
	if (column == "cl")
		cl_ = value;
	if (column == "phoneNum")
		phoneNumber_ = value;
	if (column == "birthday")
		birth_ = value;
	if (column == "certi")
		certi_ = value;
	
}
