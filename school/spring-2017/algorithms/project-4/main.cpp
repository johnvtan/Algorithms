#include <iostream>
#include <cstdlib>
#include "board.h"
#include <string.h>

using namespace std;

int main()
{
   ifstream fin;

   // Read the sample grid from the file.
   string fileName = "C:\\Users\\Mary\\Documents\\GitHub\\Algorithms\\school\\spring-2017\\algorithms\\project-4\\Sudoku1.txt";

   fin.open(fileName.c_str());
   if (!fin)
   {
      cerr << "Cannot open " << fileName << endl;
      exit(1);
   }

   try
   {
      board b1(SquareSize);

      while (fin && fin.peek() != 'Z')
      {
        b1.initialize(fin);
        b1.print();
        b1.printConflicts();
      }
   }
   catch  (indexRangeError &ex)
   {
      cout << ex.what() << endl;
      exit(1);
   }
}