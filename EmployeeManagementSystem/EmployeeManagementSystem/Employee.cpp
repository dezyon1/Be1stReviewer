#include "Employee.h"

bool Employee::isMatch(string const& column, string const& keyword) {
	if (column == "employeeNumber") {
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
	else if (column == "phoneNumber") {
		if (!keyword.compare(m_employeeInfo.phoneNumber))
			return true;
	}
	else if (column == "birth") {
		if (!keyword.compare(m_employeeInfo.birth))
			return true;
	}
	else if (column == "certi") {
		if (!keyword.compare(m_employeeInfo.certi))
			return true;
	}
	return false;
}