#pragma once

#include "Command.h"
#include "InputValidation.h"

class ICommandFactory {
public:
	virtual iCommand* createCommand(string command) = 0;
};

class CommandFactory : public ICommandFactory {
public:
	iCommand* createCommand(string command) override {
		if (!isValidInput(command))
			throw invalid_argument("입력 형식에 오류가 있습니다: " + command);

		if (command.find(ADD_CMD_STR) == 0) {
			return new AddCommand(command);
		}

		if (command.find(DEL_CMD_STR) == 0) {
			return new DelCommand(command);
		}

		if (command.find(SCH_CMD_STR) == 0) {
			return new SchCommand(command);
		}

		if (command.find(MOD_CMD_STR) == 0) {
			return new ModCommand(command);
		}

		throw invalid_argument("객체를 생성할 수 없습니다");
	}
};