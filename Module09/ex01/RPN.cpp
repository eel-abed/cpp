#include "RPN.hpp"
#include <sstream>
#include <stdexcept>
#include <cctype>
#include <cstdlib>

RPN::RPN() {}

RPN::RPN(const RPN &other) : _stack(other._stack) {}

RPN &RPN::operator=(const RPN &other)
{
	if (this != &other)
	{
		_stack = other._stack;
	}
	return *this;
}

RPN::~RPN() {}

bool RPN::isOperator(const std::string &token) const
{
	return (token.length() == 1 &&
			(token[0] == '+' || token[0] == '-' ||
			 token[0] == '*' || token[0] == '/'));
}

bool RPN::isNumber(const std::string &token) const
{
	if (token.empty())
		return false;

	if (token.length() == 1 && std::isdigit(token[0]))
		return true;

	if (token.length() == 2 && token[0] == '-' && std::isdigit(token[1]))
		return true;

	return false;
}

int RPN::performOperation(int a, int b, char op) const
{
	switch (op)
	{
	case '+':
		return a + b;
	case '-':
		return a - b;
	case '*':
		return a * b;
	case '/':
		if (b == 0)
			throw std::runtime_error("division by zero impossible");
		return a / b;
	default:
		throw std::runtime_error("Error: invalid operator");
	}
}

int RPN::evaluate(const std::string &expression)
{
	std::istringstream iss(expression);
	std::string token;

	while (!_stack.empty())
		_stack.pop();

	while (iss >> token)
	{
		if (isNumber(token))
		{
			int num = atoi(token.c_str());
			_stack.push(num);
		}
		else if (isOperator(token))
		{
			if (_stack.size() < 2)
				throw std::runtime_error("Error: insufficient operands");

			int b = _stack.top();
			_stack.pop();
			int a = _stack.top();
			_stack.pop();

			int result = performOperation(a, b, token[0]);
			_stack.push(result);
		}
		else
		{
			throw std::runtime_error("Error");
		}
	}

	if (_stack.size() != 1)
		throw std::runtime_error("Error: invalid expression");

	return _stack.top();
}
