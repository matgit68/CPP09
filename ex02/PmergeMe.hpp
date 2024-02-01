#pragma once

#include <string>
#include <vector>
#include <deque>
#include <list>
#include <iostream>
#include <algorithm>
#include <stdlib.h>

template <typename T>
void insertSort(T &vec) {
	for(size_t i = 1; i < vec.size(); i++){
		unsigned int x = vec[i];
		for(size_t j = i-1; j != 0 && vec[j] > x; j--){
            unsigned int temp = vec[j+1];
            vec[j+1] = vec[j];
            vec[j] = temp;
		}
	}
}

template <typename T>
void mergeSort(T &vec) {
	if (vec.size() <= 5) insertSort(vec);
	else {
		typename T::iterator iter = vec.begin() + vec.size() / 2;
		T v1(vec.begin(), iter);
		T v2(iter, vec.end());

		mergeSort(v1);
		mergeSort(v2);

		vec.clear();
		std::merge(v1.begin(), v1.end(), v2.begin(), v2.end(), std::back_inserter(vec));
	}
}
