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
		throw invalid_argument("입력 형식에 오류가 있습니다: " + command);

	CommandFactory commandFactory;
	iCommand* pICommand;
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