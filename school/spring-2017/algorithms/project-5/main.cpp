// Project 5
// Mary Forde, John Tan

#include "maze.h"

using namespace std;

int main()
{
	char x;
	ifstream fin;

	// Read the maze from the file.
	string fileName = "maze1.txt";

	fin.open(fileName.c_str());
	if (!fin)
	{
		cerr << "Cannot open " << fileName << endl;
		exit(1);
	}

	try
	{

		graph g;
		maze m;
		while (fin && fin.peek() != 'Z')
		{
			m.initialize(fin);
		}

		m.mapMazeToGraph(g);

		cout << "Graph: " << endl << g;


	}
	catch (indexRangeError &ex)
	{
		cout << ex.what() << endl; exit(1);
	}
	catch (rangeError &ex)
	{
		cout << ex.what() << endl; exit(1);
	}



}
