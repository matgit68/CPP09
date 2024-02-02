#pragma once

#include <string>
#include <vector>
#include <deque>
#include <list>
#include <iostream>
#include <algorithm>
#include <stdlib.h>

template <typename T>
void insertSort(T &c) {
	unsigned int x;
	size_t j;

	for(size_t i = 1; i < c.size(); i++){
		x = c[i];
		j = i;
		while(j-- > 0 && c[j] > x)
            c[j + 1] = c[j];
		c[j + 1] = x;
	}
}

template <typename T>
void mergeSort(T &c) {
	if (c.size() <= 40) insertSort(c);
	else {
		typename T::iterator iter = c.begin() + c.size() / 2;
		T c1(c.begin(), iter);
		T c2(iter, c.end());

		mergeSort(c1);
		mergeSort(c2);

		c.clear();
		std::merge(c1.begin(), c1.end(), c2.begin(), c2.end(), std::back_inserter(c));
	}
}
