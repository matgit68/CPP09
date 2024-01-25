#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(std::string str) : _exp(str){
	bool space = true;

	if (_exp.find_first_not_of(" 0123456789-+/*") != std::string::npos ||
		_exp.empty())
		throw "forbidden character or empty expression";
	for (size_t i = 0; i < _exp.size(); i++)
		if (_exp[i] == ' ')
			space = true;
		else if (space)
 			space = false;
		else
			throw "space between two chars plz";
}

RPN::RPN(const RPN &ref) : _stack(ref._stack) {}

RPN::~RPN() {}


RPN &RPN::operator=(const RPN &ref) {
	_stack = ref._stack;
	return *this;
}

void RPN::compute() {
	int res = 0;

	for (size_t i = 0; i < _exp.size(); i++) {
		if (_exp[i] == ' ')
			continue;
		if (isdigit(_exp[i]))
			_stack.push(_exp[i] - 48);
		try {
			if (_exp[i] == '+')
				add();
			else if (_exp[i] == '-')
				substract();
			else if (_exp[i] == '*')
				multiply();
			else if (_exp[i] == '/')
				divide();
		} catch (const char *error) { throw error ;}
	}
	res = _stack.top();
	_stack.pop();
	if (!_stack.empty())
		throw "not empty stack";
	std::cout << res << std::endl;
}

void RPN::add() {
	if (_stack.empty())
		throw "empty stack";
	int res = _stack.top();
	_stack.pop();
		if (_stack.empty())
		throw "empty stack";
	res = _stack.top() + res;
	_stack.pop();
	_stack.push(res);
}

void RPN::substract() {
	if (_stack.empty())
		throw "empty stack";
	int res = _stack.top();
	_stack.pop();
		if (_stack.empty())
		throw "empty stack";
	res = _stack.top() - res;
	_stack.pop();
	_stack.push(res);
}

void RPN::multiply() {
	if (_stack.empty())
		throw "empty stack";
	int res = _stack.top();
	_stack.pop();
		if (_stack.empty())
		throw "empty stack";
	res = _stack.top() * res;
	_stack.pop();
	_stack.push(res);
}

void RPN::divide() {
	if (_stack.empty())
		throw "empty stack";
	int res = _stack.top();
	_stack.pop();
		if (_stack.empty())
		throw "empty stack";
	res = _stack.top() / res;
	_stack.pop();
	_stack.push(res);
}