// Mary Forde
// John Tan
// Project 3

// This file runs the code that has been implemented.

#include<iostream>
#include"dictionary.h"
#include"grid.h"
#include"global.h"

using namespace std;

int main() {
	/**dictionary d("SmallDictionary.txt");
	
	cout << "Unsorted:\n";
	cout << d;
	cout << endl;
	
	d.selectionSort();
	
	cout << "Sorted:\n";
	cout << d;
		
	cout << "Found word: " << d.binarySearch("collegiately") << endl; 
	cout << "Nonsense word: " << d.binarySearch("nonsensfasreasdf");**/
	
	grid g("15x15 matrix.txt");
        
        /*	
	//g.possibleWordsAt(0,0);
	
	for (int i = 0; i < g.possibleWords.size(); i++) {
		cout << g.possibleWords.at(i) << endl;
	}
	
	cout << "Size: " << g.possibleWords.size();
        */
	dictionary d("Dictionary.txt");
	findMatches(d, g);	
	
	return 0;
}
