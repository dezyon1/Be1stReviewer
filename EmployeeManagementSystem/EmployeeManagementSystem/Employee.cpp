#include "Employee.h"

bool Employee::isMatch(string const& column, string const& keyword) {
	if (column == "employeeNum") {
		if (!keyword.compare(m_employeeInfo.employeeNumber))
			return true;
	}
	else if (column == "name") {
		if (!keyword.compare(m_employeeInfo.name))
			return true;
	}
	else if (column == "cl") {
		if (!keyword.compare(m_employeeInfo.cl))
			return true;
	}
	else if (column == "phoneNum") {
		if (!keyword.compare(m_employeeInfo.phoneNumber))
			return true;
	}
	else if (column == "birthday") {
		if (!keyword.compare(m_employeeInfo.birth))
			return true;
	}
	else if (column == "certi") {
		if (!keyword.compare(m_employeeInfo.certi))
			return true;
	}
	return false;
}

void Employee::setData(string const& column, string const& value) {
	if (column == "employeeNum") {
		m_employeeInfo.employeeNumber = value;
	}
	else if (column == "name") {
		m_employeeInfo.name = value;
	}
	else if (column == "cl") {
		m_employeeInfo.cl = value;
	}
	else if (column == "phoneNum") {
		m_employeeInfo.phoneNumber = value;
	}
	else if (column == "birthday") {
		m_employeeInfo.birth = value;
	}
	else if (column == "certi") {
		m_employeeInfo.certi = value;
	}
}

