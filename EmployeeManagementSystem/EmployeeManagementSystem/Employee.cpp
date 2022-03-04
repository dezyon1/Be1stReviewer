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

string Employee::getInfoStr() {
	string ret = m_employeeInfo.employeeNumber + ","
		+ m_employeeInfo.name + ","
		+ m_employeeInfo.cl + ","
		+ m_employeeInfo.phoneNumber + ","
		+ m_employeeInfo.birth + ","
		+ m_employeeInfo.certi;

	return ret;
}

int Employee::getEmployeeID() {
	return stoi(m_employeeInfo.employeeNumber);
}