// btc 		vector / queue
// RPN 		stack
// PMergeMe	ForwardList
// 			deque

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(std::string csvfile) {
    std::ifstream in;
    std::string line;
	std::string date;
	float valeur;

    try {
	    in.open(csvfile.c_str());
        if (in.fail()) throw std::ios_base::failure("Erreur d'ouverture du fichier");
    } catch (const std::ios_base::failure& e) { std::cerr << "Exception : " << e.what() << std::endl; }
    std::getline(in, line);
	while (std::getline(in, line)) {
        std::istringstream ligneStream(line);
        if (std::getline(ligneStream, date, ',') && (ligneStream >> valeur) && dateOk(date)) {
            _rate[date] = valeur;
        } else throw "Erreur de format dans le fichier data.csv";
    }
    in.close();}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &ref) : _rate(ref._rate) {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &ref) {
	_rate = ref._rate;
	return *this;
}

bool dateOk(std::string date) {
	std::istringstream	stream(date);
    std::string 		value;
	unsigned int		v;

	std::getline(stream, value, '-');
	v = std::atoi(value.c_str());
//	std::stoi(date, v, 10);
	return true;
}