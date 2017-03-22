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
		}
	}
<<<<<<< HEAD
} // end selectionSort
=======
}// end selectionSort
>>>>>>> 1e3d689a70f5dbb52a77b7a1b81db701192ead52

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
<<<<<<< HEAD
} // end binarySearch
=======
}//end binarySearch
>>>>>>> 1e3d689a70f5dbb52a77b7a1b81db701192ead52
