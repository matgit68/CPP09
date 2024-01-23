#include "BitcoinExchange.hpp"

int main(void) {

    try {
        BitcoinExchange btc("data.csv");
    } catch(const char *e) { std::cout << e << std::endl; }
    return 0;
}