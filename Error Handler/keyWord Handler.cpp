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

bool validIdentifier(string token)						//check if the given identifier is valid or not
{

		string str = token;
		if (!((str[0] >= 'a' && str[0] <= 'z') || (str[0] >= 'A' && str[0] <= 'Z') || str[0] == '_'))
		{
			return false;
		}


		// Traverse the string for the rest of the characters
		for (int i = 1; i < str.length(); i++) {
			if (!((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z') || (isdigit(str[i])) || str[i] == '_'))
				return false;
		}


}
bool lengthOfIdentifier(string token)
{

	string str;

		str = token;
		size_t len = token.size();
		if (len > 25)
			return false;
		else
			return true;

}
int main()
{


	string exp;
	ifstream file("error.txt");
	while (!file.eof())
	{
	
		string s;
		getline(file, s);
		exp = s;
		vector<string> tokens = tokenize(exp);
		for (int i = 0; i < exp.size(); i++)
		{

			bool result = validIdentifier(tokens[i]);
			bool length = lengthOfIdentifier(tokens[i]);
			cout << tokens[i] << "            ";
			if (result == 1 && length == 1)
				cout << "Valid identifier" << endl;
			else
				cout << "ERROR!" << endl;

		}
	}
}
