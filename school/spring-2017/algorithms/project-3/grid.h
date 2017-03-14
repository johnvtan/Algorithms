// Mary Forde
// John Tan
// Project 3
#include"d_matrix.h"
#include<fstream>
#include<iostream>

using namespace std;

class grid
{
	public:
		// constructor
		grid(const char* filename);
		
		// getter method
		vector<string> getPossibleWords();
		matrix<char> getWordGrid();		
	
		// overloaded cout operator
		friend ostream& operator<<(ostream& ostr, grid& g);
		
	
	private:
		// private data members 
		matrix<char> wordGrid;
		vector<string> possibleWords;

		// helper methods for constructor
		void possibleWordsAt(int startRow, int startCol);
		void generatePossibleWords();
		void generatePossibleWordsIncrementBy(int startRow, int startCol, int horInc, int vertInc);
};
