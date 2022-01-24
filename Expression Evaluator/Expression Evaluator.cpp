#include <iostream>
#include <fstream>
#include <string>
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
string check_expression(vector<string> tokens)
{
	//int len = exp.size();
	int size = tokens.size();
	string last = tokens[size - 1];
	string second_last = tokens[size - 2];
	//int k;
	string result = "";
	
	 if (isdigit(last[0]) && (second_last == "+" || second_last == "-" || second_last == "/" || second_last == "*"))
	{
		result = "infix";
	}
	else if (last == ")")
	{
		result = "infix";
	}
	
	
	return result;
}



int precedence(string op)
{
	if (op == "+" || op == "-")
	{
		return 1;
	}
	if (op == "*" || op == "/")
	{
		return 2;
	}
	return 0;
}

int solve_operation(int o1, int o2, string op)
{
	if (op == "+")
	{
		return o1 + o2;
	}
	if (op == "-")
	{
		return o1 - o2;
	}
	if (op == "*")
	{
		return o1 * o2;
	}
	if (op == "/")
	{
		return o1 / o2;
	}
}



int evaluate_infix(vector<string> exp)
{
	
	stack<int> s;
	stack<string> operators;

	for (int i = 0; i < exp.size(); i++)
	{
		if (exp[i] == "(")
		{
			operators.push(exp[i]);
		}
		else if (isdigit(exp[i][0]))
		{
			stringstream ss(exp[i]);   
			int x = 0;
			ss >> x;
			s.push(x);  
		}
		else if (exp[i] == ")")
		{
			while (!operators.empty() && operators.top() != "(")
			{
				int val = s.top();
				s.pop();

				int val1 = s.top();
				s.pop();

				string op = operators.top();
				operators.pop();

				s.push(solve_operation(val1, val, op));
			}
			if (!operators.empty())
			{
				operators.pop();
			}
		}
		else
		{
			while (!operators.empty() && precedence(operators.top())>= precedence(exp[i]))
			{
				int val = s.top();
				s.pop();

				int val1 = s.top();
				s.pop();

				string op = operators.top();
				operators.pop();

				s.push(solve_operation(val1, val, op));
			}

			// Push current token to 'ops'. 
			operators.push(exp[i]);
		}
	}

	while (!operators.empty()) {
		int val = s.top();
		s.pop();

		int val1 = s.top();
		s.pop();

		string op = operators.top();
		operators.pop();

		s.push(solve_operation(val1, val, op));
	}

	return s.top();
}



int main()
{
    //std::cout << "Hello World!\n";

	string exp;
	ifstream file("exp.txt");
	while (!file.eof())
	{
		string s;
		getline(file, s);
		exp = s;


		vector<string> tokens = tokenize(exp);
		string s1 = check_expression(tokens);
		if (s1 == "infix")
		{
			int res = evaluate_infix(tokens);
			cout << exp << " = " << res << endl;
		}
	

	}
	return 0;
	

}

