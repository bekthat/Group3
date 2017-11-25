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
T average(T arr[], int size) {
	T sum = 0;
	for (auto i = 0; i < size; ++i) {
		sum += arr[i];
	}
	return sum / size;
}
char average(char arr[], int size) {
	int sum = 0;
	for (auto i = 0; i < size; ++i) {
		sum += (int)arr[i];
	}
	return (char) (sum / size);
}
template <typename T1, typename T2>
auto sum(T1 a, T2 b) -> decltype(T1 + T2) {
	return a + b;
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

int main() {
	int a[5] = { 1, 2, 3, 4, 5 };
	double b[5] = { 6, 7, 8, 9, 10 };
	float c[5] = { 11, 12, 13, 14, 15 };
	char d[5] = { 'a', 'b', 'c', 'd', 'e' };
	cout << average(a, 5) << endl;
	cout << average(b, 5) << endl;
	cout << average(c, 5) << endl;
	cout << average(d, 5) << endl;
	/*int arr[10] = { 2, 6, 8, 4, 9, 5, 3, 7, 1, 5 };
	quicksort(arr, 0, 9);
	for (auto i = 0; i < 10; ++i) {
		cout << arr[i] << endl;
	}*/
	system("pause");
	return 0;
}
