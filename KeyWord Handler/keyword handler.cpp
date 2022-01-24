#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <sstream>
#include <stack>
using namespace std;

vector<string> tokenize(string exp)
{
	vector<string> tokens;
	stringstream check1(exp);
	string mid;
	while (getline(check1, mid, ' '))
	{
		tokens.push_back(mid);
	}
	return tokens;
}
bool keywords(const char* tokens)
{

	if (!strcmp(tokens, "INT") || !strcmp(tokens, "int") || !strcmp(tokens, "AND") || !strcmp(tokens, "ARRAY") || !strcmp(tokens, "BEGIN") || !strcmp(tokens, "DIV") || !strcmp(tokens, "DO")
		|| !strcmp(tokens, "ELSE") || !strcmp(tokens, "END") || !strcmp(tokens, "FUNCTION") || !strcmp(tokens, "IF") || !strcmp(tokens, "INTEGER")
		|| !strcmp(tokens, "MOD") || !strcmp(tokens, "NOT") || !strcmp(tokens, "OF") || !strcmp(tokens, "OR") || !strcmp(tokens, "PROCEDURE") || !strcmp(tokens, "PROGRAM")
		|| !strcmp(tokens, "REAL") || !strcmp(tokens, "READLN") || !strcmp(tokens, "THEN") || !strcmp(tokens, "VAR") || !strcmp(tokens, "WHILE") || !strcmp(tokens, "WRITELN")
		|| !strcmp(tokens, "and") || !strcmp(tokens, "array") || !strcmp(tokens, "begin") || !strcmp(tokens, "div") || !strcmp(tokens, "do")
		|| !strcmp(tokens, "else") || !strcmp(tokens, "end") || !strcmp(tokens, "function") || !strcmp(tokens, "if") || !strcmp(tokens, "integer")
		|| !strcmp(tokens, "mod") || !strcmp(tokens, "not") || !strcmp(tokens, "of") || !strcmp(tokens, "or") || !strcmp(tokens, "procedure") || !strcmp(tokens, "program")
		|| !strcmp(tokens, "real") || !strcmp(tokens, "readln") || !strcmp(tokens, "then") || !strcmp(tokens, "var") || !strcmp(tokens, "while") || !strcmp(tokens, "writeln"))
	{
		return true;
	}
	else
		return false;
}
int main()
{


	string exp;
	ifstream file("keyword.txt");
	while (!file.eof())
	{

		string s;
		getline(file, s);
		exp = s;
		//vector<string> tokens = tokenize(exp);
		vector<string> tokens = tokenize(exp);
		for (int i = 0; i < tokens.size(); i++)
		{


            	cout << tokens[i] << "            ";
			bool key = keywords(tokens[i].c_str());

            if(key == true)
            cout<<"This is a keyword"<<endl;
            else
            cout<<"   ERROR"<<endl;
		}
	}
}
