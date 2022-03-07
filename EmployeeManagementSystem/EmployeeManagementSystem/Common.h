#pragma once
#include <vector>
#include <string>

using namespace std;

class Employee;
vector<string> splitString(string input, char delimiter); 

namespace StringValue {
	static string employeeNumStr = "employeeNum";
	static string phoneNumStr = "phoneNum";
	static string clStr = "cl";
	static string certiStr = "certi";
	static string nameStr = "name";
	static string birthStr = "birthday";

	static string emptyOptionStr = " ";
	static string pOptionStr = "-p";
	static string fOptionStr = "-f";
	static string lOptionStr = "-l";
	static string mOptionStr = "-m";
	static string yOptionStr = "-y";
	static string dOptionStr = "-d";

	static string addCmdStr = "ADD";
	static string delCmdStr = "DEL";
	static string schCmdStr = "SCH";
	static string modCmdStr = "MOD";
}