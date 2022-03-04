#include <string>
#include <vector>
#include <sstream>
#include "Common.h"

using std::vector;
using std::string;

vector<string> splitString(string input, char delimiter) {
	vector<string> answer;
	std::stringstream ss(input);
	string temp;

	while (getline(ss, temp, delimiter)) {
		answer.push_back(temp);
	}

	return answer;
}