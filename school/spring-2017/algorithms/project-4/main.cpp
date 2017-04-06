#include <iostream>
#include <cstdlib>
#include "board.h"
#include <string.h>

using namespace std;

int main()
{
   ifstream fin;

   // Read the sample grid from the file.
   string fileName = "sudoku1-3.txt";

   fin.open(fileName.c_str());
   if (!fin)
   {
      cerr << "Cannot open " << fileName << endl;
      exit(1);
   }

   try
   {
      board b1(SquareSize);

	  int puzzleNum = 0;

	  while (fin && fin.peek() != 'Z')
      {
		puzzleNum += 1;
	    cout << endl << "Puzzle Number: " << puzzleNum << endl;
        b1.initialize(fin);
        b1.print();
        //b1.printConflicts();
	    cout << "Solving ..." << endl;
		b1.solve();
		b1.print();
		//b1.isSolved();
      }
   }
   catch  (indexRangeError &ex)
   {
      cout << ex.what() << endl;
      exit(1);
   }
}