#include "PrintFile.h"
#include <fstream>

string readFile(string filename) {
	ifstream file(filename);
	if (!file.good()) {
		throw invalid_argument(string("File ") + filename + string(" doesnt exists or is not readable."));
	}

	string res;
	file >> res;
	file.close();

	return res;
}


bool fileExists(string filename) {
	struct stat buffer;
	return (stat(filename.c_str(), &buffer) == 0);
}