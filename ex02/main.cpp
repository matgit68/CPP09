#include "PMergeMe.hpp"
#include <ctime>

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

	for(size_t i = 0; i < 10; i++)
		std::cout << vec[i] << ' ';
	std::cout << "..." << std::endl;
	for(size_t i = 0; i < 10; i++)
		std::cout << deq[i] << ' ';
	std::cout << "..." << std::endl;

    clock_t start_time = clock();
	mergeSortV(vec);
    clock_t end_time = clock();
    double elapsed_time = static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC;
    std::cout << "Temps écoulé pour vector : " << elapsed_time << " secondes." << std::endl;

    start_time = clock();
	mergeSortD(deq);
    end_time = clock();
    elapsed_time = static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC;
    std::cout << "Temps écoulé pour deque  : " << elapsed_time << " secondes." << std::endl;

	for(size_t i = 0; i < 10; i++)
		std::cout << vec[i] << ' ';
	std::cout << "..." << std::endl;
	for(size_t i = 0; i < 10; i++)
		std::cout << deq[i] << ' ';
	std::cout << "..." << std::endl;

    return 0;
}