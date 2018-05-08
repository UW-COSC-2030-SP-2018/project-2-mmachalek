// Max Machalek
// Project 2 
// Data Structures and Algorithms
// May 6th 2018 

// sorting functions

#include<vector>
#include<algorithm>
#include<iostream>
#include<cstdlib>
#include<string>
using std::swap;
using std::vector;
using std::cout;
using std::endl;
using std::string;



// partition for quickSort
	// sets pivot as the rightmost element in array
	// then places it in sorted position
	// with all values <pivot to the left
	// and all values >pivot to the right
int partition(int arr[], int leftmost, int rightmost)
{
	// set pivot to rightmost element
	int pivot = arr[rightmost]; 
	int i = (leftmost - 1);

	for(int j = leftmost; j <= rightmost - 1; j++)
	{
		if(arr[j] <= pivot)
		{
			i++;
			// swap arr[i] and arr[j]
			int k = arr[i];
			arr[i] = arr[j];
			arr[j] = k;
		}
	}
	// swap arr[i+1] and arr[high]
	int k = arr[i + 1];
	arr[i + 1] = arr[rightmost];
	arr[rightmost] = k;
	return i + 1;
}

// quick sort
// source referenced (also for partition):
	// location: https://www.geeksforgeeks.org/cpp-program-for-quicksort/
	// author: geeksforgeeks
	// date published: no date given
void quickSort(int arr[], int leftmost, int rightmost)
{
	if(leftmost < rightmost)
	{
		// get index location of partition
		int partitionIndex = partition(arr, leftmost, rightmost);

		// run through left side of partition first
		quickSort(arr, leftmost, partitionIndex - 1);

		// now sort elements on right side of the partition
		quickSort(arr, partitionIndex + 1, rightmost);
	}
}

// merge used for mergeSort
// source referenced: 
	// location: https://www.youtube.com/watch?v=RZK6KVpaT3I
		// and  https://pastebin.com/bpiMpDxx
	// author: Dylan Sallee
	// university: CU Boulder
	// date published: March 24, 2017
void merge(int arr[], int leftmost, int rightmost, int midpoint)
{
	int i(leftmost), j(midpoint+1), k(leftmost);
	int tempArr[100];

	// 
	while(i <= midpoint && j<= rightmost)
	{
		// if arr[i] and arr[j] in order already
		if(arr[i] < arr[j])
		{
			// put arr[i] in corresponding tempArr position
			// because it was thew lower of the two being checked
			tempArr[k] = arr[i];
			k++; i++;
		}
		// if arr[i] and arr[j] not in order yet
		else
		{
			// put the smaller val (arr[j]) in corresponding tempArr position
			tempArr[k] = arr[j];
			k++; j++;
		}
	}
	// in case leftside is > rightside?
	while(i <= midpoint)
	{
		tempArr[k] = arr[i];
		k++; i++;
	}
	// in case rightside is > leftside?
	while(j <= rightmost)
	{
		tempArr[k] = arr[j];
		k++; j++;
	}
	// now reassemble arr, filling with the ordered tempArr
	for(i = leftmost; i < k; i++)
	{
		arr[i] = tempArr[i];
	}
}

// merge sort
	// leftmost is arr index 0, rightmost is last index of array
// source referenced: 
	// location: https://www.youtube.com/watch?v=RZK6KVpaT3I
	// author: Dylan Sallee
	// university: CU Boulder
	// date: March 24, 2017
void mergeSort(int arr[], int leftmost, int rightmost)
{	
	// check to make sure array is >1 element
	if(leftmost < rightmost)
	{
		int midpoint = (leftmost + rightmost) / 2;

		// recurse through left side of array first
		mergeSort(arr, leftmost, midpoint);

		// now recurse through right side
		mergeSort(arr, midpoint + 1, rightmost);

		// bring everything back together, ordering
		merge(arr, leftmost, rightmost, midpoint);
	}
	return;
}

// potentially to check the first half a vector for
// any unsorted elements, since if the vector is unsorted it is likely 
// the entire first half will be sorted
// returns true when not sorted
bool checkUnsorted(vector<int> vec)
{
	for(int i = 0; i < (vec.size() / 2); i++)
	{
		if(vec[i] > vec[i + 1]){return true;}
	}
	// otherwise: 
	return false;
}

// binary search for value "val" in vector "vec" 
// returns the index location of the value
int binarySearch(vector<int> vec, int val, int leftmost, int rightmost)
{
	int midpoint = (leftmost + rightmost) / 2;

	// if vec empty
		// return "not found"
	if(vec.size() == 0)
	{
		cout << "Value not found - empty vector" << endl;
		return -9999;
	}
	// if vec is just 1 element long
		// see if that element is what is being searched for
	// segfault error w/ core dump if this is excluded
		// and vector size is 1 and isn't the desired number
	else if(vec.size() == 1)
	{
		if(vec[0] == val)
		{
			cout << "Value found!" << endl;
			return 0;
		}
		else
		{
			cout << "Value not found" << endl;
			return -9999;
		}
	}
	// if vec not sorted
		// return "vector not sorted"
	else if(checkUnsorted(vec))
	{
		// checkSorted returns true when vec[i] > vec[i+1]
		// checks the first half only, to save operations
		// hoping that if a vector is unsorted, it will show
		// in the first half
		cout << "Cannot search - vector not sorted" << endl;
		return -9999;
	}
	else if(val > vec[rightmost])
	{
		cout << "Value not found." << endl;
	}
	else if(val < vec[leftmost])
	{
		cout << "Value not found" << endl;
	}
	else
	{
		// if val < vector midpoint
		if(val == vec[midpoint])
		{
			// found
			cout << "Value found!" << endl;
			return midpoint;
		}
		else if(val < vec[midpoint])
		{
			// recurse on left side of vector
			return binarySearch(vec, val, leftmost, midpoint);

		}
		else if(val > vec[midpoint])
		{
			// recurse on right side of vector
			return binarySearch(vec, val, (midpoint + 1), rightmost);
		}
	}
	return -9999;
}

// a hash 
//referenced:
	// location: http://www.cse.yorku.ca/~oz/hash.html
	// // // // // // // // // // // // // // // // // 
	// location: https://stackoverflow.com/questions/2535284/how-can-i-hash-a-string-to-an-int-using-c
	// author: Alex Martelli && deepmax
	// date published: March 29, 2010 && Nov 5, 2012
unsigned long aHash(string toHash)
{
	// initialize prime hash val
	unsigned long hash = 5381;
	// set offset 
	unsigned long offset = 'a' - 1;
	
	for(string::const_iterator it = toHash.begin(); it != toHash.end(); ++it)
	{
		// bitshift to left by 5, add hash then bitwise OR the result 
		// with the current string val - offset to mitigate collisions
		hash = ((hash << 5) + hash) | (*it - offset);

		// collides if 2 strings have same letters in different order:
		// hash = ((hash << 5) + hash) + offset;
	}
	// todo: get a big old hash from the darn string

	return hash;
}

