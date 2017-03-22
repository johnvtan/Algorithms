// Mary Forde
// John Tan
// Project 3

// This file implements the dictionary class.

#include"dictionary.h"
#include<fstream>

using namespace std;

dictionary::dictionary(const char* fileName) 
// constructs a dictionary instance, from the given file
{
	// opening file
	ifstream myFile;
	myFile.open(fileName);
	
	if(myFile.is_open()) 
	{
		// getting input one line at a time and appending
		string line;
		while(getline(myFile, line)) 
		{
			words.push_back(line);	
		}
	}
	
	myFile.close();
} // end constructor

ostream& operator<<(ostream& ostr, dictionary& dict) 
// overloads the output operator
{
	for(int i = 0; i < dict.words.size(); i++) 
	{
		cout << dict.words.at(i) << endl;
	}
} // end operator<<

void dictionary::swap(int i, int j)
// swaps the values at index i and index j
{
	string temp;
	temp = words.at(i);
	words.at(i) = words.at(j);
	words.at(j) = temp;
} // end swap

void dictionary::selectionSort()
// sorts the dictionary using selection sort
{
	int minIndex;
	
	for (int i = 0; i < words.size() - 1; i++)
	{
		minIndex = i;
		for (int j = i + 1; j < words.size(); j++) 
		{
			if (words.at(j) < words.at(minIndex))
			{
				minIndex = j;
			}
		}
		
		if (minIndex != i) 
		{
			swap(i, minIndex);
			cout << ".";
		}
	}
} // end selectionSort


signed int dictionary::binarySearch(const string& findThis)
// tries to find the given string in this dictionary, returns the index if found, otherwise -1
{
	int first = 0;
	int last = words.size() - 1;
	int mid;
	string midValue;
	
	while (first <= last) 
	{
		mid = (last + first) / 2;
		midValue = words.at(mid);
		
		if (findThis == midValue)
			return mid;
		else if (findThis < midValue) 
			last = mid - 1;
		else
			first = mid + 1;
	}
	
	return -1; // if we iterate through the whole dictionary

} // end binarySearch


void dictionary::quickSort()
// sorts this dictionary using the quick sort algorithm
{
	quickSortHelper(0, words.size() - 1);	
}

void dictionary::quickSortHelper(int left, int right) 
// sorts this dictionary using the quick sort algorithm
{
	if (left < right) 
	{
		int s = partition(left, right);
		quickSortHelper(left, s - 1);
		quickSortHelper(s + 1, right); 
	}
}

int dictionary::partition (int left, int right)
// helper method for quicksort, partitians the words vector using the given left and
// right indexes
{
	string x = words.at(right);
	int i = left - 1;
	for (int j = left; j < right; j++) 
	{
		if (words.at(j) <= x) 
		{
			i += 1;
			swap(i, j);
		}
	}
	
	swap(i + 1, right);
	
	return i + 1;
}

void dictionary::heapSort()
// sorts the dictionary using the heapSort algorithm
{
	heap<string> h(words);
	
	h.heapSort();
	
}

