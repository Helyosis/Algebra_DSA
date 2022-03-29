

#include "Scientists.h"

void write_bin(string& s, ofstream& out) {
	short length = s.length();
	out.write((char*)&length, sizeof(length));
	out.write(s.c_str(), length);
}

string read_bin(short length, ifstream& bin) {
	char* tmp = new char[length];
	bin.read(tmp, length);

	string s(tmp, length);
	return s;
}

void Main() {
	ifstream in("Scientists.csv");
	ofstream out("output.dat", ios_base::binary);

	if (!in || !out) {
		cout << 404 << endl;
		return;
	}

	string line;
	getline(in, line); // Skip header
	while (getline(in, line)) {
		stringstream ss;
		ss << line;

		string name;
		if (!getline(ss, name, ';')) {
			break;
		}

		bool no_data = true;

		string tmp;
		for (int i = 0; i < 10; ++i) {
			getline(ss, tmp, ';');
			stringstream c(tmp);
			int n;
			if ((c >> n))
				no_data = false;
		}

		if (no_data)
			write_bin(name, out);
	}

	in.close();
	out.close();

	ifstream bin("output.dat", ios_base::binary);
	if (!bin) {
		cout << "404" << endl;
		return;
	}

	while (true) {
		short length;
		if (!bin.read((char*)&length, sizeof(short))) {
			break;
		}

		string name = read_bin(length, bin);

		cout << name << endl;
	}
}