#include "global.h"

// This implements the global functions findMatches and search

using namespace std;

void findMatches(dictionary& d, grid& g, int sortType)
// Prints out all the words that can be found in the grid.
{
    // sorting dictionary
	cout << "Sorting..." << endl;
    switch(sortType) {
    	case 0: 
			d.selectionSort();
    		break;
    	case 1:
    		d.quickSort();
    		break;
    	case 2:
    		d.heapSort();
    		break;
    	default:
    		cout << "Something went wrong.";
	}
    
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

void search(int sortType)
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
	findMatches(d, g, sortType);
} // end search
