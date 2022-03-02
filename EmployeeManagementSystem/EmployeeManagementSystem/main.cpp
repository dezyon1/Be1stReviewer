#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool readInputFile() {
	ifstream inputFile;
	inputFile.open("input.txt");

	if (inputFile.is_open()) {
		string str;
		while (getline(inputFile, str)) {
			cout << str << endl;
		}
	}
	else {
		return false;
	}

	inputFile.close();
	return true;
}

int main(int argc, char** argv) {
	if (!readInputFile()) {
		return -1;
	}

	ofstream outputFile;
	outputFile.open("output.txt");

	if (outputFile.is_open()) {
		// for test
		outputFile << "Hello World!\n";
		outputFile << "This is C++ File Contents.\n";
		outputFile.close();
	}

	return 0;
}
