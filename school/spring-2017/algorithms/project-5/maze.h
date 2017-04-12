// Project 5
// Mary Forde, John Tan

#include <iostream>
#include <limits.h>
#include "d_except.h"
#include <list>
#include <fstream>
#include <cstdlib>
#include "d_matrix.h"
#include "graph.h"

class maze
{
public:
	maze(ifstream &fin);
	maze() { };
	void initialize(ifstream &fin);
	void print(int goalI,int goalJ,int currI,int currJ);
	bool isLegal(int i, int j);

	void setMap(int i, int j, int n);
	int getMap(int i, int j) const;
	void mapMazeToGraph(graph &g);

private:
	int rows; // number of rows in the maze
	int cols; // number of columns in the maze

	matrix<bool> value;
	matrix<int> map;      // Mapping from maze (i,j) values to node index values


};

void maze::setMap(int i, int j, int n)
// Set mapping from maze cell (i,j) to graph node n.
{
	if (i > rows || j > cols || i < 0 || j < 0) {
		throw rangeError("Invalid index value(s) given for this map.");
	}

	map[i][j] = n;
}

int maze ::getMap(int i, int j) const
// Return mapping of maze cell (i,j) in the graph.
{
	if (i > rows || j > cols || i < 0 || j < 0) {
		throw rangeError("Invalid index value(s) given for this map.");
	}

	return map[i][j];
}

maze::maze(ifstream &fin)
// Initializes a maze by reading values from fin.  Assumes that the
// number of rows and columns indicated in the file are correct.
{
	fin >> rows;
	fin >> cols;

	char x;

	value.resize(rows,cols);
	for (int i = 0; i <= rows-1; i++)
		for (int j = 0; j <= cols-1; j++)
		{
			fin >> x;
			if (x == 'O')
				value[i][j] = true;
			else
				value[i][j] = false;
		}

	map.resize(rows,cols);
}


void maze::initialize(ifstream &fin)
// Initializes a maze which has already been constructed by reading values from fin.  Assumes that the
// number of rows and columns indicated in the file are correct.
{
	fin >> rows;
	fin >> cols;

	char x;

	value.resize(rows,cols);
	for (int i = 0; i <= rows-1; i++)
		for (int j = 0; j <= cols-1; j++)
		{
			fin >> x;
			if (x == 'O')
				value[i][j] = true;
			else
				value[i][j] = false;
		}

	map.resize(rows,cols);

}


void maze::print(int goalI, int goalJ, int currI, int currJ)
// Print out a maze, with the goal and current cells marked on the
// board.
{
	cout << endl;

	if (goalI < 0 || goalI > rows || goalJ < 0 || goalJ > cols)
		throw rangeError("Bad value in maze::print");

	if (currI < 0 || currI > rows || currJ < 0 || currJ > cols)
		throw rangeError("Bad value in maze::print");

	for (int i = 0; i <= rows-1; i++)
	{
		for (int j = 0; j <= cols-1; j++)
		{
			if (i == goalI && j == goalJ)
				cout << "*";
			else
			if (i == currI && j == currJ)
				cout << "+";
			else
			if (value[i][j])
				cout << " ";
			else
				cout << "X";
		}
		cout << endl;
	}
	cout << endl;
}

bool maze::isLegal(int i, int j)
// Return the value stored at the (i,j) entry in the maze.
{
	if (i < 0 || i > rows || j < 0 || j > cols)
		throw rangeError("Bad value in maze::isLegal");

	return value[i][j];
}

void maze::mapMazeToGraph(graph &g)
// Create a graph g that represents the legal moves in the maze m.
{

	// Add all the nodes to the graph
	int nodeCount = 1;
	for (int i = 0; i <= rows - 1; i++)
	{
		for (int j = 0; j <= cols - 1; j++)
		{
			if (value[i][j])
			{
				node n;
				n.setId(nodeCount);
				setMap(i,j,nodeCount);
				g.addNode(n);
				nodeCount++;
			}
		}
	}

	// Add all the edges to the graph
	for (int i = 0; i <= rows - 1; i++)
	{
		for (int j = 0; j <= cols - 1; j++)
		{
			//If a valid node, check for edges
			if (map[i][j] > 0)
			{
				// up
				if (i > 0 && map[i-1][j] > 0)
				{
					g.addEdge(map[i][j]-1, map[i-1][j]-1, 1);
				}
				// down
				if (i <= rows-2 && map[i+1][j] > 0)
				{
					g.addEdge(map[i][j]-1, map[i+1][j]-1, 1);
				}
				// left
				if (j > 0 && map[i][j-1] > 0)
				{
					g.addEdge(map[i][j]-1, map[i][j-1]-1, 1);
				}
				// right
				if (j <= cols-2 && map[i][j+1] > 0)
				{
					g.addEdge(map[i][j]-1, map[i][j+1]-1, 1);
				}
			}
		}
	}
}

void maze::findPathRecursive(graph &g)
//
{

}

