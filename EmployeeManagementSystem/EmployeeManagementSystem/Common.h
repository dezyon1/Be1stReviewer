#pragma once
#include <vector>
#include <string>

using namespace std;

class Employee;
vector<string> splitString(string input, char delimiter); 

namespace StringValue {
	static const string EMPLOYEE_NUM_STR = "employeeNum";
	static const string PHONE_NUM_STR = "phoneNum";
	static const string CL_STR = "cl";
	static const string CERTI_STR = "certi";
	static const string NAME_STR = "name";
	static const string BIRTH_STR = "birthday";

	static const string EMPTY_OPT_STR = " ";
	static const string P_OPT_STR = "-p";
	static const string F_OPT_STR = "-f";
	static const string L_OPT_STR = "-l";
	static const string M_OPT_STR = "-m";
	static const string Y_OPT_STR = "-y";
	static const string D_OPT_STR = "-d";

	static const string ADD_CMD_STR = "ADD";
	static const string DEL_CMD_STR = "DEL";
	static const string SCH_CMD_STR = "SCH";
	static const string MOD_CMD_STR = "MOD";
}