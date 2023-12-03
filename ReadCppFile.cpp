#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>

using namespace std;


bool isOperator(const string &word)
 {
      static const vector<string> op = {"+", "-", "*", "/", "="};
      return find(op.begin(), op.end(), word) != op.end();
 }

int main()
{
    ifstream cppFile("Program.cpp");
    if (!cppFile.is_open())
    {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    string line;
    set<string> functions;
    set<string> operators;

    while (getline(cppFile, line))
    {
        string word;
        istringstream stream(line);

        while (stream >> word)
        {

            size_t pos = word.find('(');
            if (pos != string::npos && pos != 0 && isalpha(word[0]) && functions.count(word.substr(0, pos)) == 0)
            {
                functions.insert(word.substr(0, pos));
                cout << "Function-" << functions.size() << ": " << word.substr(0, pos) << endl;
            }
            else if (isOperator(word) && operators.count(word) == 0)
            {
                operators.insert(word);
                cout << "Operator-" << operators.size() << ": " << word << endl;
            }
        }
    }

    cout << "Total number of user-defined functions: " << functions.size() << endl;
    cout << "Total number of operators: " << operators.size() << endl;

    cppFile.close();
    return 0;
}

