#include "PmergeMe.hpp"
#include <ctime>

int main(int argc, char **argv) {
    std::vector<unsigned int> vec, init;
    std::deque<unsigned int> deq;
    unsigned long tmp;
    clock_t first_start_time, start_time, end_time;
	double elapsed_time;

    // on met le contenu de argv dans un vector 'init'
	// init servira a remplir le vector vec et la deque deq.
	if (argc < 2)
		return 1;
	for (int i = 1; argv[i]; i++) {
		std::string str(argv[i]);
		if (str.find_first_not_of("0123456789") != std::string::npos)
			return 2;
		tmp = atol(argv[i]);
		if (tmp > 4294967295)
			return 3;
		init.push_back((unsigned int) tmp);
	}

	////////////////////////////////////// VECTOR //////////////////////////////////////
    first_start_time = clock();
	for(int j = 0; j < 1; j++)
		for(std::vector<unsigned int>::iterator it = init.begin(); it != init.end(); it++)
			vec.push_back(*it);
    end_time = clock();
    elapsed_time = static_cast<double>(end_time - first_start_time) / CLOCKS_PER_SEC;
    std::cout << "Affectation de " << vec.size() << " éléments dans vector : " << elapsed_time << " secondes." << std::endl;

	for(size_t i = 0; i < vec.size() && i < 15; i++)
		std::cout << vec[i] << ' ';
	std::cout << "..." << std::endl;
	
	start_time = clock();
	mergeSort(vec);
    end_time = clock();
    elapsed_time = static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC;
    std::cout << "Tri de vector : " << elapsed_time << " secondes." << std::endl;

	for(size_t i = 0; i < vec.size() && i < 15; i++)
		std::cout << vec[i] << ' ';
	std::cout << "..." << std::endl;
    end_time = clock();
    elapsed_time = static_cast<double>(end_time - first_start_time) / CLOCKS_PER_SEC;
    std::cout << "Temps total pour vector : " << elapsed_time << " secondes (" << vec.size() << " elements)." << std::endl << std::endl;


	////////////////////////////////////// DEQUE //////////////////////////////////////
    first_start_time = clock();
	for(int j = 0; j < 1; j++)
		for(size_t i = 0; i < init.size(); i++)
			deq.push_back(init[i]);
    end_time = clock();
    elapsed_time = static_cast<double>(end_time - first_start_time) / CLOCKS_PER_SEC;
    std::cout << "Affectation de " << deq.size() << " éléments dans deque : " << elapsed_time << " secondes." << std::endl;

	for(size_t i = 0; i < deq.size() && i < 15; i++)
		std::cout << deq[i] << ' ';
	std::cout << "..." << std::endl;
	
	start_time = clock();
	mergeSort(deq);
    end_time = clock();
    elapsed_time = static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC;
    std::cout << "Tri de deque : " << elapsed_time << " secondes." << std::endl;

	for(size_t i = 0; i < deq.size() && i < 15; i++)
		std::cout << deq[i] << ' ';
	std::cout << "..." << std::endl;
    end_time = clock();
    elapsed_time = static_cast<double>(end_time - first_start_time) / CLOCKS_PER_SEC;
    std::cout << "Temps total pour deque : " << elapsed_time << " secondes (" << deq.size() << " elements)." << std::endl;
    return 0;
}