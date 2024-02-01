#include "PmergeMe.hpp"

void insertSortV(std::vector<unsigned int> &vec) {
	for(size_t i = 1; i < vec.size(); i++){
		unsigned int x = vec[i];
		for(size_t j = i-1; j != 0 && vec[j] > x; j--){
		//swapping if current element is lesser
		unsigned int temp = vec[j+1];
		vec[j+1] = vec[j];
		vec[j] = temp;
		}
	}
}

void mergeSortV(std::vector<unsigned int> &vec) {
	if (vec.size() <= 5) insertSortV(vec);
	else {
		std::vector<unsigned int>::iterator iter = vec.begin() + vec.size() / 2;
		std::vector<unsigned int> v1(vec.begin(), iter);
		std::vector<unsigned int> v2(iter, vec.end());

		mergeSortV(v1);
		mergeSortV(v2);

		vec.clear();
		std::merge(v1.begin(), v1.end(), v2.begin(), v2.end(), std::back_inserter(vec));
	}
}

void insertSortD(std::deque<unsigned int> &vec) {
	for(size_t i = 1; i < vec.size(); i++){
		unsigned int x = vec[i];
		for(size_t j = i-1; j != 0 && vec[j] > x; j--){
		//swapping if current element is lesser
		unsigned int temp = vec[j+1];
		vec[j+1] = vec[j];
		vec[j] = temp;
		}
	}
}

void mergeSortD(std::deque<unsigned int> &vec) {
	if (vec.size() <= 5) insertSortD(vec);
	else {
		std::deque<unsigned int>::iterator iter = vec.begin() + vec.size() / 2;
		std::deque<unsigned int> v1(vec.begin(), iter);
		std::deque<unsigned int> v2(iter, vec.end());

		mergeSortD(v1);
		mergeSortD(v2);

		vec.clear();
		std::merge(v1.begin(), v1.end(), v2.begin(), v2.end(), std::back_inserter(vec));
	}
}
