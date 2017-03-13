#include "dictionary.h"
#include "grid.h"
#include <iostream>

using namespace std;

void findMatches(dictionary& d, grid& g)
// Prints out all the words that can be found in the grid.
{
    // sorting dictionary
    d.selectionSort();
    vector<string> possibleWords = g.getPossibleWords();
    vector<int> foundWords;
    signed int index;

    for(int i = 0; i < possibleWords.size(); i++)
    {
	index = d.binarySearch(possibleWords[i]);
	if(index >= 0)
	{
	    cout << "Found: " << possibleWords[i] << endl;
	}
    }
}
