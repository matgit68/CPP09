#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(std::string csvfile) {
    std::ifstream in;
    std::string line;
	std::string date;
	float value;

	in.open(csvfile.c_str());
	if (in.fail()) throw std::ios_base::failure("Can't open data file");
    std::getline(in, line);
	while (std::getline(in, line)) {
        std::istringstream ligneStream(line);
        if (std::getline(ligneStream, date, ',') && (ligneStream >> value) && dateOk(date) && value >= 0) {
            _rate[date] = value;
        } else throw line;
    }
    in.close();
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &ref) : _rate(ref._rate) {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &ref) {
	_rate = ref._rate;
	return *this;
}

void BitcoinExchange::display() const{
 for (std::map<std::string, float>::const_iterator it = _rate.begin(); it != _rate.end(); ++it)
        std::cout << it->first << " -> " << it->second << std::endl;
}

void BitcoinExchange::process(std::string line) {
	if (line.size() < 14 || line.substr(10, 3) != " | ") {
		std::cerr << "Error: bad format /!\\ " << line << std::endl;
		return ;
	}
	std::string date = line.substr(0, 10);
	if (!dateOk(date)) {
		std::cerr << "Error: wrong date format /!\\ " << date << std::endl;
		return ;
	}
	if (date < _rate.begin()->first || date > _rate.rbegin()->first) {
		std::cerr << "Error: date out of reference data range /!\\" << date << std::endl;
		return;
	}
	std::string strVal = line.substr(13, line.size());
	if (strVal.find_first_not_of("0123456789.") != std::string::npos
		|| countOccurrences('.', strVal) > 1
		|| strVal.size() > 4) {
		std::cerr << "Error: wrong value format /!\\ " << strVal << std::endl;
		return ;
	}
	convert(date, std::atof(strVal.c_str()));
}

void BitcoinExchange::convert(std::string date, float value) {
	std::map<std::string, float>::iterator it;

	it = _rate.lower_bound(date);
	if (it->first > date) 
		it--;
	std::cout << it->first << "(" << it->second << ") => ";
	std::cout << value << " = " << value * it->second << std::endl;
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

int countOccurrences(char target, const std::string &str) {
    int count = 0;
    for (std::size_t i = 0; i < str.size(); i++)
        if (str[i] == target)
            count++;
    return count;
}