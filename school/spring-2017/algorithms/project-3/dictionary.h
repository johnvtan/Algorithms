// Mary Forde
// John Tan
// Project 3
#include<string.h>
#include<iostream>
#include<vector>

using namespace std;

class dictionary {
	public:
		// constructor
		dictionary(const char* fileName);
		
		// public methods for sorting and searching
		void selectionSort();
		signed int binarySearch(const string& findThis);
		
		// overloaded cout operator
		friend ostream& operator<<(ostream& ostr, dictionary& dict);
	
	private:
		// private data member containing all words in dict
		vector<string> words;
		
		// private helper method to swap two indexes in vector
		void swap(int i, int j);
};
