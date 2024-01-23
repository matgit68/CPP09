#pragma once
//#include <string>
#include <iomanip>
#include <string>
#include <map>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h> 

class BitcoinExchange {
private:
	std::map<std::string, float> _rate;
	BitcoinExchange();

public:
	BitcoinExchange(std::string csvfile);
	BitcoinExchange(BitcoinExchange const &ref);
	~BitcoinExchange();

	BitcoinExchange &operator=(BitcoinExchange const &ref);

	void setRate(std::string);
};

const int maxDaysInMonths[12] = {31, 29, 31, 30, 31, 30 , 31, 31, 30, 31, 30, 31};
bool isBissextile(int date);
bool dateOk(std::string date);