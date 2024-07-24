#include "RPN.hpp"

RPN::RPN() : _input("") {}

RPN::RPN(std::string input) : _input(input) {}

RPN::~RPN() {}

RPN::RPN(const RPN &other) : _input(other._input), _stack(other._stack) {}

RPN &RPN::operator=(const RPN &other)
{
	if (this != &other)
	{
		_input = other._input;
		_stack = other._stack;
	}
	return *this;
}

bool RPN::isOperator(const std::string &token) const
{
	return token.length() == 1 && (token == "+" || token == "-" || token == "*" || token == "/");
}

int RPN::applyOperation(int left, int right, const std::string &op)
{
	switch (op[0])
	{
		case '+':
			return left + right;
		case '-':
			return left - right;
		case '*':
			return left * right;
		case '/':
			if (right == 0)
				throw std::runtime_error("division by zero");
			return left / right;
		default:
			throw std::invalid_argument("Invalid operator");
	}
}

void RPN::calculateRPN()
{
	std::istringstream iss(_input);
	std::string token;

	while (iss >> token)
	{
		if (isOperator(token))
		{
			if (_stack.size() < 2)
				throw std::invalid_argument("not enough operands");
			int right = _stack.top();
			_stack.pop();
			int left = _stack.top();
			_stack.pop();

			int result = applyOperation(left, right, token);
			_stack.push(result);
		}
		else {
			char* endptr;
			long value = std::strtol(token.c_str(), &endptr, 10);
			if (*endptr != '\0' || value > INT_MAX || value < INT_MIN)
				throw std::runtime_error(std::string("Invalid token: ") + token);
			_stack.push(static_cast<int>(value));
		}
	}
	if (_stack.size() != 1)
		throw std::invalid_argument("stack size != 1");
	PRINTGREEN(_stack.top());
}