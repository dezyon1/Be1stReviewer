#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char** argv) {
	ifstream inputFile;
	inputFile.open("input.txt");

	if (inputFile.is_open()) {
		string str;
		while (getline(inputFile, str)) {
			cout << str << endl;
		}

	}

	inputFile.close();

	return 0;
}