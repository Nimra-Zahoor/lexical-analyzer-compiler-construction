#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <sstream>

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

bool validIdentifier(string token)					
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
bool keywords(const char *tokens)
{
	
	if(!strcmp(tokens, "AND")  || !strcmp(tokens,"ARRAY") || !strcmp(tokens,"BEGIN") || !strcmp(tokens,"DIV") || !strcmp(tokens,"DO")
	|| !strcmp(tokens,"ELSE") || !strcmp(tokens,"END") || !strcmp(tokens,"INT") || !strcmp(tokens,"int") || !strcmp(tokens,"FUNCTION") || !strcmp(tokens,"IF") || !strcmp(tokens,"INTEGER")
	|| !strcmp(tokens,"MOD") || !strcmp(tokens,"NOT") || !strcmp(tokens,"OF") || !strcmp(tokens,"OR") || !strcmp(tokens,"PROCEDURE") || !strcmp(tokens,"PROGRAM")
	|| !strcmp(tokens,"REAL") || !strcmp(tokens,"READLN") || !strcmp(tokens,"THEN") || !strcmp(tokens,"VAR") || !strcmp(tokens,"WHILE") || !strcmp(tokens,"WRITELN")
	|| !strcmp(tokens, "and")  || !strcmp(tokens,"array") || !strcmp(tokens,"begin") || !strcmp(tokens,"div") || !strcmp(tokens,"do")
	|| !strcmp(tokens,"else") || !strcmp(tokens,"end") || !strcmp(tokens,"function") || !strcmp(tokens,"if") || !strcmp(tokens,"integer")
	|| !strcmp(tokens,"mod") || !strcmp(tokens,"not") || !strcmp(tokens,"of") || !strcmp(tokens,"or") || !strcmp(tokens,"procedure") || !strcmp(tokens,"program")
	|| !strcmp(tokens,"real") || !strcmp(tokens,"readln") || !strcmp(tokens,"then") || !strcmp(tokens,"var") || !strcmp(tokens,"while") || !strcmp(tokens,"writeln")) 
	 {
	 return true;
     }
	 else
	 return false;
}
bool isOperator(string ch)							//check if the given character is an operator or not
{
    if (ch == "+" || ch == "-" || ch == "*" || ch == "/" || ch == "|" || ch == "&" || ch == ">" || ch == "<" || ch == "=" || ch == "<=" || ch == ">=" || ch == "==" )
    {
       return true;
    }
    return false;
}
bool isPunctuator(const char *ch)					//check if the given character is a punctuator or not
{
    if ( ch == "," || ch == ";" || ch == "(" || ch == ")" || ch == "[" || ch == "]" || ch == "{" || ch == "}"  )
        {
            return true;
        }
    return false;
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
bool isNumber(const char* str)							//check if the given substring is a number or not
{
    int i, len = strlen(str),numOfDecimal = 0;
    if (len == 0)
    {
        return false;
    }
    for (i = 0 ; i < len ; i++)
    {
        if (numOfDecimal > 1 && str[i] == '.')
        {
            return false;
        } else if (numOfDecimal <= 1)
        {
            numOfDecimal++;
        }
        if (str[i] != '0' && str[i] != '1' && str[i] != '2'
            && str[i] != '3' && str[i] != '4' && str[i] != '5'
            && str[i] != '6' && str[i] != '7' && str[i] != '8'
            && str[i] != '9' || (str[i] == '-' && i > 0))
            {
                return false;
            }
    }
    return true;
}
int main()
{


	string exp;
	ifstream file("lex.txt");
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
			bool key = keywords(tokens[i].c_str()); 
			bool op =  isOperator(tokens[i]);
			bool pc = isPunctuator(tokens[i].c_str());
			bool num = isNumber(tokens[i].c_str());
			cout << tokens[i] << "            ";
			if(!(keywords(tokens[i].c_str())))
			{
			if (result == 1 && length == 1 )
				cout << "Valid identifier" << endl;
			
			}
		    if(key == true )
			   cout<<"its a Keyword"<<endl;
		    if (op == true )
               cout<<"its an Operator"<<endl;
            if(tokens[i]==";") 
			   cout<<"its a terminator"<<endl; 
			if(pc== true)
			   cout<<"its a punctuator"<<endl;
			if(num== true)
			   cout<<"its a Number"<<endl;      
			if(key ==false && op == false && length == false && result == false)
			cout<<"ERROR!!!"<<endl;    
	
		}
		
	}
}
