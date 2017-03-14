#include"global.h"

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
		if(index >= 0 && possibleWords[i].length() >= 5)
		{
	   		cout << "Found: " << possibleWords[i] << endl;
		}
    }
}

void search(string gridFileName)
// Prints out all the words that can be found in the grid
{
	dictionary d("Dictionary.txt");
	d.selectionSort();
	char* gridFileNameChar;
	strcpy(gridFileNameChar, gridFileName);
	grid g(gridFileNameChar);
	
	findMatches(d, g);	
}
