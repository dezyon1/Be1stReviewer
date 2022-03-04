#include "Command.h"
#include <iostream>

EmployeeInfo AddCommand::getEmployeeInfo(string command)
{
	EmployeeInfo employeeInfo;

	employeeInfo.employeeNumber = commandTokens[4];
	employeeInfo.name = commandTokens[5];
	employeeInfo.cl = commandTokens[6];
	employeeInfo.phoneNumber = commandTokens[7];
	employeeInfo.birth = commandTokens[8];
	employeeInfo.certi = commandTokens[9];

	return employeeInfo;
}