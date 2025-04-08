#pragma once
#include <iostream>
using namespace std;

class ShakerSorter {

private:
	int* m_arr;
	int m_size;

public:
	ShakerSorter(int n, int* arr) { m_size = n; m_arr = new int[n]; for (int i = 0; i < n; i++) m_arr[i] = arr[i]; }
	void sort();
	void print() { for (int i = 0; i < m_size; i++) cout << m_arr[i] << (i == m_size - 1 ? '\n' : ','); };
	~ShakerSorter() { delete[] m_arr; };

};
