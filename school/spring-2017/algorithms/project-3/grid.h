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
		grid(char* filename);
		
		vector<string> getPossibleWords();
		
		friend ostream& operator<<(ostream& ostr, grid& g);
		
		
		vector<string> possibleWords;
		void possibleWordsAt(int startRow, int startCol);
	
	private:
		matrix<char> wordGrid;
		
		
		void generatePossibleWords();
		void generatePossibleWordsIncrementBy(int startRow, int startCol, int horInc, int vertInc);
		//void possibleWordsAt(int row, int col);
};
