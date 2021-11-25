#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_2_Sorting_Algoritms.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(QuickSortTest)
		{
			int* test_array = new int[10];
			int first = 0; int last = 10 - 1;
			for (int i = 0; i < 10; i++)
			{
				test_array[i] = 10 - i;
			}

			QuickSort(test_array, first, last);

			for (int i = 1; i < 10; i++) {
				Assert::IsTrue(test_array[i - 1] <= test_array[i]);
			}
			delete[]test_array;
		}

		TEST_METHOD(InsertionSortTest)
		{
			int* test_array = new int[10];
			for (int i = 0; i < 10; i++)
			{
				test_array[i] = 10 - i;
			}
			InsertionSort(test_array, 10);

			for (int i = 1; i < 10; i++) {
				Assert::IsTrue(test_array[i - 1] <= test_array[i]);
			}
			delete[]test_array;
		}
		TEST_METHOD(BogoSortTest)
		{
			int* test_array = new int[10];
			for (int i = 0; i < 10; i++)
			{
				test_array[i] = 10 - i;
			}

			BogoSort(test_array, 10);

			for (int i = 1; i < 10; i++) {
				Assert::IsTrue(test_array[i - 1] <= test_array[i]);
			}
			delete[]test_array;
		}

		TEST_METHOD(CountingSortTest)
		{
			char* test_array = new char[4];
			test_array[0] = 'd';
			test_array[1] = 'c';
			test_array[2] = 'b';
			test_array[3] = 'a';

			CountingSort(test_array, 4);

			Assert::IsTrue(test_array[0] == 'a');
			Assert::IsTrue(test_array[1] == 'b');
			Assert::IsTrue(test_array[2] == 'c');
			Assert::IsTrue(test_array[3] == 'd');

			delete[]test_array;
		}

		TEST_METHOD(BinarySearchTest)
		{
			int* test_array = new int[10];
			for (int i = 0; i < 10; i++)
			{
				test_array[i] = i;
			}
			try {
				BinarySearch(test_array, 10, 5);
			}
			catch (const invalid_argument error) {
				Assert::AreEqual("There is no such element in the array\n", error.what());
			}

			try {
				BinarySearch(test_array, 10, 11);
			}
			catch (const invalid_argument error) {
				Assert::AreEqual("There is no such element in the array\n", error.what());
			}
			Assert::IsTrue(BinarySearch(test_array, 10, 9) == 9);
			delete[]test_array;

		}
	};
}
