#include <iostream>
#include <string>
#include "EmployeeManagementSystem.h"
#include "Employee.h"
#include "InputValidation.h"
#include "Command.h"

using namespace std;

string EmployeeManagementSystem::runCommand(string command)
{
	if (!isValidInput(command))
		throw invalid_argument("�Է� ���Ŀ� ������ �ֽ��ϴ�: " + command);

	FactoryCommand factoryCommand;
	iCommand* pICommand = factoryCommand.createCommand(command);
	string result = pICommand->run(database_);

	if (pICommand != nullptr) {
		delete(pICommand);
	}	
	
	return result;
}
