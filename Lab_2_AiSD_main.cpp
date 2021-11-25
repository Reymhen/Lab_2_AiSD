#include "Lab_2_Sorting_Algoritms.h"


// function of filling an array with random values
void filling_the_array(int*array, int size_array) {
	srand(time(NULL)); // clear the random element 
	for (int i = 0; i < size_array; i++) // filling with values
	{
		array[i] = rand() % 100;
	}
	for (int i = 0; i < size_array; i++) { //array output
		cout << array[i] << ' ';
	}
};


// array zeroing function
void zeroing_an_array(int*array, int size_array) {
	for (int i = 0; i < size_array; i++) array[i] = 0;
};

void main() {
	
	 int size_array;
	 cout << "Enter the size of the array\n";
	 cin >> size_array;
	 int* array = new int[size_array]; // an array of numbers with which we will work
	// Quick Sort
	cout << "Generate an array with " << size_array << " elements:\n";
	filling_the_array(array,size_array);
	int first = 0; int last = size_array - 1; // last and first array indices
	cout << "\nSorted array with Quick Sort:\n";
	QuickSort(array, first, last);
	for (int i = 0; i < size_array; i++) { // sorted array output
		cout << array[i] << ' ';
	}
	cout << endl << endl;


	// Binary Search
	cout << "Using a sorted array:\n";
	for (int i = 0; i < size_array; i++) {
		cout << array[i] << ' ';
	}
	cout << "\nFound:\n";
	int found;
	cin >> found;
	cout << "The entered number has an index:\n";
	try {
		cout << BinarySearch(array, size_array, found);
	}
	catch (const invalid_argument error) {
		cout << error.what();
	}
	cout << "\nGet the index of '20':\n";
	try {
		cout << BinarySearch(array, size_array, 20);
	}
	catch (const invalid_argument error) {
		cout << error.what();
	}
	zeroing_an_array(array, size_array);
	cout << endl;

	// Bogo Sort
	cout << "Generate an array with " << size_array << " elements:\n";
	filling_the_array(array, size_array);
	cout << "\nSorted array with Bogo Sort:\n";
	BogoSort(array, size_array);
	for (int i = 0; i < size_array; i++) { // sorted array output
		cout << array[i] << ' ';
	}
	zeroing_an_array(array, size_array);
	cout << endl << endl;

	// Insertion Sort
	cout << "Generate an array with " << size_array << " elements:\n";
	filling_the_array(array, size_array);
	cout << "\nSorted array with Insertion Sort:\n";
	InsertionSort(array, size_array);
	for (int i = 0; i < size_array; i++) { // sorted array output
		cout << array[i] << ' ';
	}
	zeroing_an_array(array, size_array);
	cout << endl << endl;
	
	// Counting Sort for char
	cout << "Generate an char array with " << size_array << " elements:\n";
	char* char_array_test = new char[size_array];
	for (int i = 0; i < size_array; i++) // filling with values
	{
		char_array_test[i] = rand() % 127;
	}
	for (int i = 0; i < size_array; i++) { // array output
		cout << char_array_test[i] << ' ';
	}
	cout << "\nSorted char array with Counting Sort:\n";
	CountingSort(char_array_test, size_array);
	for (int i = 0; i < size_array; i++) { // sorted array output
		cout << char_array_test[i] << ' ';
	}
	delete[]char_array_test; // deleting an array

	cout << endl << endl;

	// Examples of Quick Sort work for comparison with Insertion Sort
	int degree = 1;
	cout << "Quick Sort an array of\n";
	while (degree < 6) {
		int size = pow(10, degree);
		int* new_array = new int[size];
		int first = 0; int last = size - 1;
		long double elapsed_secs = 0;
		for (int i = 0; i < 10; i++) {
			srand(time(NULL)); // clear the random element 
			for (int i = 0; i < size; i++) new_array[i] = rand() % 100;
			clock_t begin = clock();
			QuickSort(new_array, first, last);
			clock_t end = clock();
			elapsed_secs = elapsed_secs + long double(end - begin) / CLOCKS_PER_SEC;
		}
		elapsed_secs /= 10;
		cout << size << " elements takes " << elapsed_secs << " seconds\n";
		delete[]new_array;
		degree = degree + 1;
	}
	cout << endl;

	// Examples of Insertion Sort work for comparison with Quick Sort
	degree = 1;
	cout << "Insertion Sort an array of\n";
	while (degree < 6) {
		int size = pow(10, degree);
		int* new_array = new int[size];
		long double elapsed_secs = 0;
		for (int i = 0; i < 10; i++) {
			srand(time(NULL)); // clear the random element 
			for (int i = 0; i < size; i++) new_array[i] = rand() % 100;
			clock_t begin = clock();
			InsertionSort(new_array, size);
			clock_t end = clock();
			elapsed_secs = elapsed_secs + long double(end - begin) / CLOCKS_PER_SEC;
		}
		elapsed_secs /= 10;
		cout << size << " elements takes " << elapsed_secs << " seconds\n";
		delete[]new_array;
		degree = degree + 1;
	}
}