#include "global.h"

using namespace std;

void findMatches(dictionary& d, grid& g)
// Prints out all the words that can be found in the grid.
{
    // sorting dictionary
	cout << "Sorting..." << endl;

    d.heapSort();
    
    cout << "Sorted\n:" << d;
    
	// generating possible words in grid
    vector<string> possibleWords = g.getPossibleWords();
    vector<int> foundWords;
    signed int index;

    for(int i = 0; i < possibleWords.size(); i++)
    {
		index = d.binarySearch(possibleWords[i]);
		if(index >= 0)
		{
			// prints out words only if length >= 5
			if(possibleWords[i].length() >= 5)
				cout << "Found: " << possibleWords[i] << endl;
		}
    }
} // end findMatches

void search()
// asks for user input for filename, opens the file and initializes grid and
// dictionary before calling findMatches()
{
	char fileName[255];
	cout << "Please enter the name of the grid file: ";
	cin.getline(fileName, 255);
	
	cout << "Opening " << fileName << endl;
	grid g(fileName);
	//cout << g << endl;
	dictionary d("Dictionary.txt");
	findMatches(d, g);
} // end search
