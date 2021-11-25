#pragma once
#include <iostream>
#include <ctime>

using namespace std;


int BinarySearch(int* array, int size, int key) {
		int left = 0;
		int right = size - 1;
		bool flag_found = false;
		int mid;

		while ((left <= right) && (flag_found != true)) {
			mid = (left + right) / 2; // calculating the average index of an array

			if (array[mid] == key) flag_found = true; // the required element is equal to the element under the index of the middle
			if (array[mid] > key) right = mid - 1; // discard the useless part of array
			else left = mid + 1;
		}

		if (flag_found) return mid; // if looking for element is exist
		else
		{
			throw invalid_argument("There is no such element in the array\n");
		}
};


void QuickSort(int* array, int first, int last) {
	int mid;
	int left = first, right = last;
	mid = array[(left + right) / 2]; //  find out the value of the middle element
	do
	{
		while (array[left] < mid) left++;
		while (array[right] > mid) right--;
		if (left <= right) // swap the elements
		{
			swap(array[left], array[right]);
			left++;
			right--;
		}
	} while (left < right);
	if (first < right) QuickSort(array, first, right); // sort the sub-array
	if (left < last) QuickSort(array, left, last); // sort the sub-array
}


void InsertionSort(int* array, int size) {
	for (int i = 1; i < size; i++)
		for (int j = i; j > 0 && array[j - 1] > array[j]; j--) {// while the previous element is greater than the next
			int temp = array[j - 1]; // swap the elements
			array[j - 1] = array[j];
			array[j] = temp;
		}
};


void BogoSort(int* array, int size) {
	bool flag_sort = true;
	for (int i = 0; i < size - 1; i++) {
		if (array[i] > array[i + 1])
			flag_sort = false;
	}
	while (!flag_sort) {
		for (int i = 0; i < size; ++i)
			swap(array[i], array[(rand() % size)]);
		flag_sort = true;
		for (int i = 0; i < size - 1; i++) {
			if (array[i] > array[i + 1])
				flag_sort = false;
		}
	}
};


void CountingSort(char* array, int size) {

	char char_array[256] = { 0 };
	for (int i = 0; i < size; ++i) {
		++char_array[array[i]]; // count the number of each character
	}

	int temp = 0; // go through all symbols
	for (int i = 0; i < 256; ++i) {
		for (int j = 0; j < char_array[i]; ++j) {
			array[temp++] = i;
		}
	}

}