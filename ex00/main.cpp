#include "BitcoinExchange.hpp"

int main(int argc, char **argv) {
    BitcoinExchange btc;
    std::ifstream in;
    std::string line;
	std::string date;
	// float value;

    if (argc != 2) {
        std::cout << "Usage : btc <input file>" << std::endl;
        return EXIT_FAILURE;
    }
    try {
        BitcoinExchange tmp("data.csv");
        btc = tmp;
    } catch(const std::string &line) {
        std::cout << "Exception : wrong data type at line : " << line << std::endl;
        return EXIT_FAILURE;
    }
    try {
	    in.open(argv[1]);
        if (in.fail()) throw std::ios_base::failure("Can't open file");
    } catch (const std::ios_base::failure& e) {
        std::cerr << "Exception : " << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    // btc.display();
    // btc.exchange(std::pair)
    return EXIT_SUCCESS;
}