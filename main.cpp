// Max Machalek
// Project 2 
// Data Structures and Algorithms
// May 6th 2018

// TODO:
	//** unit tests for these below
	//**
	// quick sort (DONE?)
	// binary search (DONE?)
	// merge sort  (DONE?)
	// text/int to int hash (convert strings <80 char) or ints to ints
	//**
	//** unit tests for these above

	// bloom filter using STL hash
#include"sorting.h"

int main()
{
	int arr[15] = {9,8,7,6,5,4,3,2,1,15,14,-13,12,10};
	quickSort(arr, 0, 14);

	for(int i = 0; i < 15; i++)
	{
		cout << arr[i] << " ";
	}
	//mergeSort(arr, 0, 14);

	vector<int> vec = {3};
	binarySearch(vec, 2, 0, vec.size());

	cout << "Hashing the string \"cheese\" : " << endl;
	unsigned long hash = aHash("cheese");
	cout << "After hashing: " << hash << endl;

	cout << "Hashing the string \"eesche\": " << endl;
	unsigned long hash2 = aHash("eesche");
	cout << "After hashing: " << hash2 << endl;
	
	return 0;
}