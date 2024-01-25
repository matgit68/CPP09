#include "PMergeMe.hpp"

void FJsortV(std::vector<unsigned int> &t) {
	std::sort(t.begin(), t.end());
	for (size_t i = 0; i < t.size(); i++) {
		std::cout << t[i] << ' ';
	}
	std::cout << std::endl;
}