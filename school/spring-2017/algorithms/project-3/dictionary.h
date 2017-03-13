// Mary Forde
// John Tan
// Project 3
#include<string.h>
#include<iostream>
#include<vector>

using namespace std;

class dictionary {
	public:
		dictionary(char* fileName);
		
		void selectionSort();
		signed int binarySearch(const string& findThis);
		
		friend ostream& operator<<(ostream& ostr, dictionary& dict);
	
	private:
		vector<string> words;
		
		void swap(int i, int j);
};
