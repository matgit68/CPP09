#include "RPN.hpp"

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "Usage : RPN \"inverted Polish mathematical expression\"" << std::endl;
        return EXIT_FAILURE;
    }
	try {
		RPN rpn(argv[1]);
		rpn.compute();
	} catch (const char *e) {
		std::cerr << "Exception: " << e << std::endl;
	}
}