// Mary Forde
// John Tan
// Project 3
// This file implements the grid class
#include"grid.h"

using namespace std;

grid::grid(const char* filename)
//constructs a grid from the given file
{
	ifstream myFile;
	myFile.open(filename);
		
	if(myFile.is_open()) 
	{
		//get first two integers, which give us the array size
		int numRows, numCols;
		myFile >> numRows;		
		myFile >> numCols;
		
		wordGrid.resize(numRows, numCols);
		
		char c;
			
		// iterating through and getting all chars in grid
		for (int i = 0; i < numRows; i ++) 
		{
			for (int j = 0; j < numCols; j++) 
			{
				myFile >> wordGrid[i][j];
			}
		}
	}
	
	myFile.close();
	
	generatePossibleWords();		
} // end grid constructor

vector<string> grid::getPossibleWords()
// returns the possible words vector 
{
    return possibleWords;
} 

matrix<char> grid::getWordGrid()
// returns word grid matrix
{
    return wordGrid;
}

void grid::generatePossibleWords()
// generates all possible words in the word search grid
{
    int numRows = wordGrid.rows();
    int numCols = wordGrid.cols();
    
    for(int i = 0; i < numRows; i++)
    {
        for(int j = 0; j < numCols; j++)
        {
            possibleWordsAt(i, j);
        }
    }
} // end generatePossibleWords

void grid::possibleWordsAt(int startRow, int startCol)
// generates all the possible words to the right of the starting 
{
	// add first letter
	string startLetter = ""; 
	startLetter += wordGrid[startRow][startCol];
	possibleWords.push_back(startLetter);
	
	// Up
	generatePossibleWordsIncrementBy(startRow,startCol,1,0);
	// Down
	generatePossibleWordsIncrementBy(startRow,startCol,-1,0);
	// Right
	generatePossibleWordsIncrementBy(startRow,startCol,0,1);
	// Left
	generatePossibleWordsIncrementBy(startRow,startCol,0,-1);
	// Up Right
	generatePossibleWordsIncrementBy(startRow,startCol,-1,1);
	// Down Left
	generatePossibleWordsIncrementBy(startRow,startCol,1,1);
	// Down Right
	generatePossibleWordsIncrementBy(startRow,startCol,1,-1);
	// Up Left
	generatePossibleWordsIncrementBy(startRow,startCol,-1,-1);
} // end possibleWordsAt


void grid::generatePossibleWordsIncrementBy(int startRow, int startCol, int horInc, int vertInc) 
// Appends all possible strings to the possibleWords vector in grid class, 
// direction is based on the horizontal increment and vertical increment 
// arguments
{
	int numRows = wordGrid.rows();
	int numCols = wordGrid.cols();
	
	// the starting letter
	string currWord = ""; 
	currWord += wordGrid[startRow][startCol];
		
	int i = startRow;
	int j = startCol;
	
	while(true) 
	{
		// update i,j by increments
		i += vertInc; //rows
		j += horInc; //cols
		
		// bounds checking indexes if over/under
		if (vertInc > 0 && i >= numRows)
		{
			i = 0;
		}
		if (vertInc < 0 && i < 0)
		{
			i = numRows - 1;
		}
		if (horInc > 0 && j >= numCols)
		{
			j = 0;
		}
		if (horInc < 0 && j < 0)
		{
			j = numCols - 1;
		}
		
		if (i == startRow && j == startCol) { break; }
		
		// adding char from grid to current word
		currWord += wordGrid[i][j];

		// appending it to vector
		possibleWords.push_back(currWord);
	}
} // end generatePossibleWordsIncrementBy


ostream& operator<<(ostream& ostr, grid& g)
// Overloads the << operator
{
	int numRows = g.wordGrid.rows();
	int numCols = g.wordGrid.cols();
	
	ostr << numRows << " " << numCols << endl;
	
	for (int i = 0; i < numCols; i ++) 
	{
		for (int j = 0; j < numRows; j++) 
		{
			ostr << g.wordGrid[i][j] << " ";
		}
		ostr << endl;
	}
	
	return ostr;
}
