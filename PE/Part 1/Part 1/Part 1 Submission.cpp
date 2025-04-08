#include <iostream>
using namespace std;
#include "ShakerSort.h"

void ShakerSorter::sort() {
	bool swap = true;
	print();

	for (int i = 0; i < m_size/2 && swap; i++) {
		swap = false;

		for (int j = 0; j < m_size-1; j++) {
			if (m_arr[j] > m_arr[j+1]) {
				int temp = m_arr[j];
				m_arr[j] = m_arr[j + 1];
				m_arr[j + 1] = temp;
				swap = true;
			}
		}

		if (!swap) break;

		print();

		for (int j = (m_size - 2 - i); j > 0; j--) {
			if (m_arr[j] < m_arr[j - 1]) {
				int temp = m_arr[j];
				m_arr[j] = m_arr[j - 1];
				m_arr[j - 1] = temp;
				swap = true;
			}
		}

		if (!swap) break;

		print();
	}
};