#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;
vector<string> splitwords(string line, string delimeter) {
	vector<string> words{};
	size_t pos = 0;
	while (pos = line.find(delimeter) != string::npos) {
		words.push_back(line.substr(0, line.find(delimeter)));
		line.erase(0, pos + delimeter.length());
	}
	return words;
}

void takeInput() {
	ifstream _stream("test.txt");
	if (!_stream) {
		cout << "No file!!!" << endl;
		exit(23);
	}
	string data;
	string delimeter = " ";
	while (getline(_stream, data)) {
		cout << data << endl;
	}
	_stream.close();
}

void outputToFile() {
	
}
int main() {
	
	takeInput();
}
