// Mary Forde
// John Tan
// Project 3

// This file runs the code that has been implemented.

#include<iostream>
#include"dictionary.h"
using namespace std;

int main() {
	dictionary d("SmallDictionary.txt");
	
	cout << "Unsorted:\n";
	cout << d;
	cout << endl;
	
	d.selectionSort();
	
	cout << "Sorted:\n";
	cout << d;
	
	
	cout << "Found word: " << d.binarySearch("collegiately") << endl; 
	cout << "Nonsense word: " << d.binarySearch("helloasdfye8orafd");
	
	return 0;
}
