#pragma once

#include <iomanip>
#include <string>
#include <stack>
#include <iostream>
#include <stdlib.h> 

class RPN {
private:
	std::stack<int> _stack;
	std::string _exp;
	RPN();
	void add();
	void substract();
	void multiply();
	void divide();

public:
	RPN(std::string str);
	RPN(const RPN &ref);
	~RPN();

	RPN &operator=(const RPN &ref);

	void compute();
};