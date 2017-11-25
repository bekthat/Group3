// Templates.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

using namespace std;



//template <typename T>
//template <class T>

template <typename T>
T max(T arr[], int size) {
	T temp = arr[0];
	for (auto i = 1; i < size; ++i) {
		if (temp < arr[i])
			temp = arr[i];
	}
	return temp;
}

template <typename T>
void quicksort(T* a, int low, int high) {
	int i = low, j = high;
	T pivot = a[(low + high) / 2];

	while (i <= j) {
		while (a[i] < pivot)
			i++;
		while (a[j] > pivot)
			j--;
		if (i <= j) {
			swap(a[i], a[j]);
			i++;
			j--;
		}
	};

	if (low < j)
		quicksort(a, low, j);
	if (i < high)
		quicksort(a, i, high);
}

int main()
{
	int a[5] = { 1, 2, 3, 4, 5 };
	double b[5] = { 6, 7, 8, 9, 10 };
	float c[5] = { 11, 12, 13, 14, 15 };
	cout << max(a, 5) << endl;
	cout << max(b, 5) << endl;
	cout << max(c, 5) << endl;
	int a[10] = { 2, 6, 8, 4, 9, 5, 3, 7, 1, 5 };
	quicksort(a, 0, 9);
	system("pause");
	return 0;
}
