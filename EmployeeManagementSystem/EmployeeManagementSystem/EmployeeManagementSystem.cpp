#include <iostream>
#include <string>
#include "EmployeeManagementSystem.h"
#include "Employee.h"
#include "Command.h"
#include "CommandFactory.h"

using namespace std;

string EmployeeManagementSystem::runCommand(string command)
{
	CommandFactory commandFactory;
	ICommand* pICommand;
	try {
		pICommand = commandFactory.createCommand(command);
		if (!pICommand)
			throw exception("객체 생성 실패");
	}
	catch (exception& e) {
		cout << e.what() << endl;
		return string("");
	}
	string result = pICommand->run(database_);

	if (pICommand != nullptr) {
		delete(pICommand);
	}
	
	return result;
}