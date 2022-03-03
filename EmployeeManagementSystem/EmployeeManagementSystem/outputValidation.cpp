#include "outputValidation.h"
using namespace std;

bool IsValidOutput() {
	ifstream resultFile, answerFile;
	resultFile.open("../EmployeeManagementSystem/output.txt");
	answerFile.open("../EmployeeManagementSystem/output_solution.txt");
	
	if (!resultFile.is_open() || !answerFile.is_open()) {
		return false;
	}

	bool ret = true;

	string resultStr, answerStr;
	while (getline(resultFile, resultStr) && getline(answerFile, answerStr)) {

		if (resultStr != answerStr) {
			cout << endl;
			cout << "[Invalid Output]" << endl;
			cout << "Result:: " << resultStr << endl;
			cout << "Expected Result:: " << answerStr << endl;
			cout << endl;

			ret = false;
			break;
		}
	}

	resultFile.close();
	answerFile.close();

	return ret;
}