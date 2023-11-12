#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <regex>

using namespace std;

void detectNumbers(const string &line, vector<string> &integers, vector<string> &floats);

int main() {
    ifstream file("readFile.txt");
    string line;
    vector<string> integers;
    vector<string> floats;

    if (!file.is_open()) {
        cerr << "Error opening file." << endl;
        return 1;
    }

    while (getline(file, line)) {
        detectNumbers(line, integers, floats);
    }

    file.close();

    cout << "Detected Integers:" << endl;
    for (const string &integer : integers) {
        cout << integer << endl;
    }

    cout << "\nDetected Float Numbers:" << endl;
    for (const string &flt : floats) {
        cout << flt << endl;
    }

    return 0;
}

void detectNumbers(const string &line, vector<string> &integers, vector<string> &floats) {
    istringstream iss(line);
    string token;

    while (iss >> token) {
        regex integerRegex("-?\\b\\d+\\b");
        regex floatRegex("-?\\b\\d+\\.\\d+\\b");

        if (regex_match(token, integerRegex)) {
            integers.push_back(token);
        } else if (regex_match(token, floatRegex)) {
            floats.push_back(token);
        }
    }
}


