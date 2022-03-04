#include "Command.h"
#include <iostream>

EmployeeInfo AddCommand::getEmployeeInfo(string command)
{
	string info = command.substr(command.find(',', InfoStartIndex) + 1, command.length() - 1);
	int sequence = 0;
	int previous = 0;
	int current = info.find(',');

	while (current != string::npos)
	{
		string substring = info.substr(previous, current - previous);
		employeeInfoSeq[sequence++] = substring;
		previous = current + 1;
		current = info.find(',', previous);
	}
	employeeInfoSeq[sequence] = info.substr(previous, current - previous);

	EmployeeInfo employeeInfo;
	employeeInfo.employeeNumber = employeeInfoSeq[EmployeeNum];
	employeeInfo.name = employeeInfoSeq[Name];
	employeeInfo.cl = employeeInfoSeq[CL];
	employeeInfo.phoneNumber = employeeInfoSeq[PhoneNum];
	employeeInfo.birth = employeeInfoSeq[Birthday];
	employeeInfo.certi = employeeInfoSeq[CERTI];

	return employeeInfo;
}