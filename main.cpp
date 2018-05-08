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
	// get some space in the terminal for easier reading
	cout << endl; 

	// Exercising fxns, w/ focus on corner cases:
	cout << "===================================QuickSort===================================" << endl;

	// make sure it sorts to begin with:
	int arr[15] = {9,8,7,6,5,4,3,2,1,15,14,13,12,11,10};
	cout << "arr before quicksort: ";
	for(int i = 0; i < 15; i++)
	{
		cout << arr[i] << ", ";
	}
	quickSort(arr, 0, 14);
	cout << "\narr after quicksort: ";
	for(int i = 0; i < 15; i++)
	{
		cout << arr[i] << ", ";
	}
	cout << endl << endl;

	// what happens with an empty array?
	cout << "what happens when try to sort empty array? " << endl;
	cout << "emptyArr before quickSort call: ";
	int emptyArr[15] = {};
	for(int i = 0; i < 15; i++)
	{
		cout << emptyArr[i] << ", ";
	}
	cout << endl;
	quickSort(emptyArr,0,14);
	cout << "emptyArr after quickSort call: ";
	for(int i = 0; i < 15; i++)
	{
		cout << emptyArr[i] << ", ";
	}
	cout << endl << endl;

	// what about any array of size 1?
	int atomicArr[1] = {2};
	cout << "atomicArr before quickSort call: " << atomicArr[0] << endl;
	quickSort(atomicArr,0,0);
	cout << "atomicArr after quickSort call: " << atomicArr[0] << endl;
	cout << endl;

	// will it sort an unordered pair?
	int smallArr[2] = {10, 6};
	cout << "smallArr before quickSort call: " << smallArr[0] << ", " 
	<< smallArr[1] << endl;
	quickSort(smallArr,0,1);
	cout << "smallArr after quickSort call: " << smallArr[0] << ", " 
	<< smallArr[1] << endl << endl;

	// how does it handle negatives?
	int nArr[15] = {-1, 2, 5, 3, -3, 3, -20, 100, -1000, -12, 12, 16, 0, 18, 17};
	cout << "nArr before quickSort call: ";
	for(int i = 0; i < 15; i++)
	{
		cout << nArr[i] << ", ";
	}
	cout << endl;
	quickSort(nArr,0,14);
	cout << "nArr after quickSort call: ";
	for(int i = 0; i < 15; i++)
	{
		cout << nArr[i] << ", ";
	}
	cout << endl << endl;

	// ** //
	cout << "===================================MergeSort===================================" << endl;

	// now what about mergeSort?
	// make sure it sorts to begin with:
	int arrM[15] = {90,80,70,60,50,40,30,20,10,150,140,130,120,110,100};
	cout << "arrM before mergeSort: ";
	for(int i = 0; i < 15; i++)
	{
		cout << arrM[i] << ", ";
	}
	mergeSort(arrM, 0, 14);
	cout << "\narrM after mergeSort: ";
	for(int i = 0; i < 15; i++)
	{
		cout << arrM[i] << ", ";
	}
	cout << endl << endl;

	// what happens with an empty array?
	cout << "what happens when try to mergeSort empty array? " << endl;
	cout << "emptyArrM before mergeSort call: ";
	int emptyArrM[15] = {};
	for(int i = 0; i < 15; i++)
	{
		cout << emptyArrM[i] << ", ";
	}
	cout << endl;
	quickSort(emptyArrM,0,14);
	cout << "emptyArrM after mergeSort call: ";
	for(int i = 0; i < 15; i++)
	{
		cout << emptyArrM[i] << ", ";
	}
	cout << endl << endl;

	// what about any array of size 1?
	int atomicArrM[1] = {7};
	cout << "atomicArrM before mergeSort call: " << atomicArrM[0] << endl;
	quickSort(atomicArrM,0,0);
	cout << "atomicArrM after mergeSort call: " << atomicArrM[0] << endl;
	cout << endl;

	// will it sort an unordered pair?
	int smallArrM[2] = {11, 5};
	cout << "smallArrM before mergeSort call: " << smallArrM[0] << ", " 
	<< smallArrM[1] << endl;
	quickSort(smallArrM,0,1);
	cout << "smallArrM after mergeSort call: " << smallArrM[0] << ", " 
	<< smallArrM[1] << endl << endl;

	// how does it handle negatives?
	int nArrM[15] = {-10, 26, 5, 3, -34, 3, -20, 100, -1000, -12, 190, 16, 0, 18, 17};
	cout << "nArrM before mergeSort call: ";
	for(int i = 0; i < 15; i++)
	{
		cout << nArrM[i] << ", ";
	}
	cout << endl;
	quickSort(nArrM,0,14);
	cout << "nArrM after mergeSort call: ";
	for(int i = 0; i < 15; i++)
	{
		cout << nArrM[i] << ", ";
	}
	cout << endl << endl;

	
	return 0;
}