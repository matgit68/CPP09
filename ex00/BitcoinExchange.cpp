// btc 		vector / queue
// RPN 		stack
// PMergeMe	ForwardList
// 			deque

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(std::string csvfile) {
    std::ifstream in;
    std::string line;
	std::string date;
	float value;

    try {
	    in.open(csvfile.c_str());
        if (in.fail()) throw std::ios_base::failure("Can't open data file");
    } catch (const std::ios_base::failure& e) { std::cerr << "Exception : " << e.what() << std::endl; }
    std::getline(in, line);
	while (std::getline(in, line)) {
        std::istringstream ligneStream(line);
        if (std::getline(ligneStream, date, ',') && (ligneStream >> value) && dateOk(date) && value >= 0) {
            _rate[date] = value;
        } else throw line;
    }
    in.close();}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &ref) : _rate(ref._rate) {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &ref) {
	_rate = ref._rate;
	return *this;
}

void BitcoinExchange::display() {
 for (std::map<std::string, float>::const_iterator it = _rate.begin(); it != _rate.end(); ++it)
        std::cout << it->first << " -> " << it->second << std::endl;
}

bool checkDigitDate(std::string date) {
	int year = atoi(date.substr(0,4).c_str());
	int month = atoi(date.substr(5,2).c_str());
	int day = atoi(date.substr(8,2).c_str());
	if (year < 1970 || month > 12 || day > maxDaysInMonths[month - 1])
		return false;
	return true;
}

bool dateOk(std::string date) {
	if (date.size() != 10 || date[4] != '-' || date[7] != '-')	
		return false;
	if (!isdigit(date[0]) || !isdigit(date[1]) || !isdigit(date[2]) || !isdigit(date[3]) ||
		!isdigit(date[5]) || !isdigit(date[6]) || !isdigit(date[8]) || !isdigit(date[9]))
		return false;
	return (checkDigitDate(date));
}