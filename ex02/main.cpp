#include "PMergeMe.hpp"

int main(int argc, char **argv) {
    std::vector<unsigned int> vec;
    std::deque<unsigned int> deq;
    unsigned long tmp;

    if (argc < 2)
		return 1;
	for (int i = 1; argv[i]; i++) {
		std::string str(argv[i]);
		if (str.find_first_not_of("0123456789") != std::string::npos)
			return 2;
		tmp = atol(argv[i]);
		if (tmp > 4294967295)
			return 3;
		vec.push_back((unsigned int) tmp);
		deq.push_back((unsigned int) tmp);
	}
	FJsortV(vec);
	// sort(deq);
    return 0;
}