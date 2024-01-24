#pragma once

#include <iomanip>
#include <string>
#include <map>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h> 
#include <time.h>

class BitcoinExchange {
private:
	std::map<std::string, float> _rate;
public:
	BitcoinExchange();
	BitcoinExchange(std::string csvfile);
	BitcoinExchange(BitcoinExchange const &ref);
	~BitcoinExchange();

	BitcoinExchange &operator=(BitcoinExchange const &ref);

	void setRate(std::string);
	void display();
};

const int maxDaysInMonths[12] = {31, 29, 31, 30, 31, 30 , 31, 31, 30, 31, 30, 31};
bool dateOk(std::string date);
