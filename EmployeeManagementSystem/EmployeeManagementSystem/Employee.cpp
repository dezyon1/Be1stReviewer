#include "Employee.h"

bool Employee::isMatch(string const& column, string const& keyword) {
	if (column == "employeeNum") {
		if (!keyword.compare(employeeNumber_))
			return true;
	}
	else if (column == "name") {
		if (!keyword.compare(name_))
			return true;
	}
	else if (column == "cl") {
		if (!keyword.compare(cl_))
			return true;
	}
	else if (column == "phoneNum") {
		if (!keyword.compare(phoneNumber_))
			return true;
	}
	else if (column == "birthday") {
		if (!keyword.compare(birth_))
			return true;
	}
	else if (column == "certi") {
		if (!keyword.compare(certi_))
			return true;
	}
	return false;
}

bool Employee::isMatch(string const& column, string const& keyword, string const& option) {
	return true;
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
