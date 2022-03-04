#include "Command.h"
#include "Employee.h"

string ModCommand::run(IDatabase<Employee>* database) {
	string result = "";

	vector<Employee> found = database->mod(searchColumn, searchValue, modColumn, modValue);
	for (auto& it : found) {
		result += "MOD," + it.toString() + "\n";
	}

	return result;
}
