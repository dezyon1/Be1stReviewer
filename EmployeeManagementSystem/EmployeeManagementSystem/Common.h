#pragma once
#include <vector>
#include <string>

using namespace std;

class Employee;
vector<string> splitString(string input, char delimiter); 

namespace StringValue {
	const string EMPLOYEE_NUM_STR = "employeeNum";
	const string PHONE_NUM_STR = "phoneNum";
	const string CL_STR = "cl";
	const string CERTI_STR = "certi";
	const string NAME_STR = "name";
	const string BIRTH_STR = "birthday";

	const string EMPTY_OPT_STR = " ";
	const string P_OPT_STR = "-p";
	const string F_OPT_STR = "-f";
	const string L_OPT_STR = "-l";
	const string M_OPT_STR = "-m";
	const string Y_OPT_STR = "-y";
	const string D_OPT_STR = "-d";

	const string ADD_CMD_STR = "ADD";
	const string DEL_CMD_STR = "DEL";
	const string SCH_CMD_STR = "SCH";
	const string MOD_CMD_STR = "MOD";
}