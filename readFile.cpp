#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

void token(const string &str, vector<string> &vec);
bool isPunctuation(char s);
bool isKeyword(const string &s);
bool isConstant(const string &s);
bool isOperator(const string &s);
bool isIdentifier(const string &s);

int main()
{
    ifstream file("readFile.txt");
    string line;
    string code;
    vector<string> tokens;

    while (getline(file, line))
    {
        code += line + '\n';
    }

    token(code, tokens);

    for (const string &token : tokens)
    {
        if (isKeyword(token))
        {
            cout << '\'' << token << "' - KEYWORD\n";
        }
        else if (isConstant(token))
        {
            cout << '\'' << token << "' - CONSTANT\n";
        }
        else if (isOperator(token))
        {
            cout << '\'' << token << "' - OPERATOR\n";
        }
        else if (isIdentifier(token))
        {
            cout << '\'' << token << "' - VALID IDENTIFIER\n";
        }
        else
        {
            cout << '\'' << token << "' - INVALID IDENTIFIER\n";
        }
    }

    return 0;
}

void token(const string &str, vector<string> &vec)
{
    string temp;
    for (char c : str)
    {
        if (!isPunctuation(c) && !isspace(c))
        {
            temp.push_back(c);
        }
        else
        {
            if (!temp.empty())
            {
                vec.push_back(temp);
                temp.clear();
            }
        }
    }

    vec.erase(remove(vec.begin(), vec.end(), ""), vec.end());
}

bool isPunctuation(char s)
{
    const string punctuations = "(){},;:";
    return punctuations.find(s) != string::npos;
}

bool isKeyword(const string &s)
{
    const vector<string> keywords = {"int", "float", "double", "cout", "cin", "endl", "using", "namespace", "vector", "array", "iostream", "#include", "string", "char", "ifstream", "fstream", "while", "for", "do", "if", "else", "else if", "std", "true", "false"};
    return find(keywords.begin(), keywords.end(), s) != keywords.end();
}

bool isConstant(const string &s)
{
    if (s.front() == '"' && s.back() == '"' && s.length() > 1)
    {
        return true;
    }
    if (s.front() == '\'' && s.back() == '\'' && s.length() > 1)
    {
        return true;
    }
    for (char c : s)
    {
        if (!isdigit(c))
        {
            return false;
        }
    }
    return true;
}

bool isOperator(const string &s)
{
    const vector<string> operators = {"+", "-", "/", "*", "%", "--", "++", "=", "+=", "-=", "*=", "/=", "%=", "==", "!=", ">", "<", "<=", ">=", "&&", "||", "!", "&", "|", "^", "~", "sizeof", "?:", ".", "->"};
    return find(operators.begin(), operators.end(), s) != operators.end();
}

bool isIdentifier(const string &s)
{
    const string symbols = "!#%";
    if ((isalpha(s.front()) || s.front() == '_') && s.find_first_of(symbols) == string::npos)
    {
        return true;
    }
    return false;
}




