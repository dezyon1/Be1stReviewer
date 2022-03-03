#include "outputValidation.h"
using namespace std;

bool IsValidOutput() {
	ifstream resultFile, answerFile;
	resultFile.open("../EmployeeManagementSystem/output.txt");
	answerFile.open("../EmployeeManagementSystem/output_solution.txt");
	
	if (!resultFile.is_open() || !answerFile.is_open()) {
		return false;
	}

	string resultStr, answerStr;
	while (1) {
		if (getline(resultFile, resultStr)) {
			return false;
		}

		if (!getline(answerFile, answerStr)) {
			return false;
		}

		if (resultStr != answerStr) {
			cout << endl;
			cout << "[Invalid Output]" << endl;
			cout << "Result:: " << resultStr << endl;
			cout << "Expected Result:: " << answerStr << endl;
			cout << endl;
			return false;
		}
	}

	return true;
}