#pragma once
#include <string>
#include <stack> 
#include <map>  
using namespace std;
class ReversedPolishNotation
{
public:
	ReversedPolishNotation();
	~ReversedPolishNotation();
	string convertToRPN(string s);
private:
	const int RIGHT = 0;
	const int LEFT = 1;
	const string PARENTHESIS_ERROR = "ERROR PARENTHESIS: There are mismatched parentheses";
	const string NO_SYMBOL_PARENTHESIS_ERROR = "ERROR NO SYMBOL BEFORE PARENTHESIS: You have to put a symbol ('a','o','i','n','(') before the parenthesis";
	const string DOUBLED_SYMBOL_ERROR = "ERROR DOUBLED SYMBOL: You have to put a variable after any symbol, except for 'n' and '('";
	const string DOUBLED_VARIABLE_ERROR = "ERROR DOUBLED VARIABLE: You have to put a symbol after any variable";
	const string INVALID_CHARACTER_ERROR = "ERROR INVALID CHARACTER: You have to put variables like [A...Z] || (0,1) and symbols like a || n || o || i || ( || )";
	map<char, int> precedence;
	map<char, int> association;
	bool contains(char c);

};

