#include "BitcoinExchange.hpp"

int main(int argc, char **argv) {
    std::ifstream in;
    std::string line;

    if (argc != 2) {
        std::cout << "Usage : btc <input file>" << std::endl;
        return EXIT_FAILURE;
    }
    try {
        BitcoinExchange btc("data.csv");
        try {
            in.open(argv[1]);
            if (in.fail()) throw std::ios_base::failure("Can't open file");
            std::getline(in, line);
            if (line != "date | value") {
                std::cout << "Wrong header in input file" << std::endl;
                return EXIT_FAILURE;
	        }
            while (std::getline(in, line))
                btc.process(line);
        } catch (const std::ios_base::failure& e) {
            std::cerr << "Exception : " << e.what() << std::endl;
            return EXIT_FAILURE;
        }
    } catch(const std::string &line) {
        std::cout << "Exception : wrong data type at line : " << line << std::endl;
        return EXIT_FAILURE;
    }
    // btc.display();
    return EXIT_SUCCESS;
}