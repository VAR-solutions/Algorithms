#include "stdafx.h"
#include "ReversedPolishNotation.h"
#include <iostream>


ReversedPolishNotation::ReversedPolishNotation()
{
	precedence.emplace('n', 2);
	precedence.emplace('a', 1);
	precedence.emplace('o', 1);
	precedence.emplace('i', 0);
	association.emplace('n', RIGHT);
	association.emplace('a', LEFT);
	association.emplace('o', LEFT);
	association.emplace('i', LEFT);

}


ReversedPolishNotation::~ReversedPolishNotation()
{
}

string ReversedPolishNotation::convertToRPN(string s)
{
	string output;
	stack<char> operators;
	stack <char> controller;
	bool seenSymbol=false, seenVariable=false;


	while (s.length() != 0) {
		char token = s.front();
		s.erase(0, 1);
		if (token >= 'A'&&token <= 'Z' || token == '0' || token == '1') {
			if (seenVariable)
				return DOUBLED_VARIABLE_ERROR;

			output += token;
			seenVariable = true;
			seenSymbol = false;
		}
		else if(contains(token))
		{
			if (seenSymbol&&token != 'n')
				return DOUBLED_SYMBOL_ERROR;
			seenVariable = false;
			seenSymbol = true;
			if (operators.size() > 0) {
				char op = operators.top();
				operators.pop();
				int error = 1;
				while (op != '(' && ((precedence.at(op) > precedence.at(token)) || ((precedence.at(op) == precedence.at(token)) && association.at(op) == LEFT))){
					error = 0;
					output += op;
					if (operators.size() > 0) {
						op = operators.top();
						operators.pop();
					}
					else
						break;
				}
				if (error == 1)
					operators.push(op);
				operators.push(token);
			}
			else
				operators.push(token);
		}
		else if (token == '(') {
			if(seenVariable)
				return NO_SYMBOL_PARENTHESIS_ERROR;
			operators.push(token);
		}
		 else if (token == ')') {
			 char op = operators.top();
			 operators.pop();
			 while (op != '(') {
				 output += op;
				 if (operators.size() > 0)
				 {
					 op = operators.top();
					 operators.pop();
				 }
				 else 
					 return PARENTHESIS_ERROR;
			 }
		 }
		 else if(token!=' ')
			 return INVALID_CHARACTER_ERROR;

	}
	if (operators.size() > 0) {
		char op = operators.top();
		operators.pop();
		while (operators.size() > 0) {
			if (op != '(')
				output += op;
			else
				return PARENTHESIS_ERROR;
			op = operators.top();
			operators.pop(); 
		}
		if (op != '(')
			output += op;
		else
			return PARENTHESIS_ERROR;
	}
	return output;
}

bool ReversedPolishNotation::contains(char c)
{
	for (auto& x : precedence)
		if (x.first == c)
			return true;
	return false;
}
