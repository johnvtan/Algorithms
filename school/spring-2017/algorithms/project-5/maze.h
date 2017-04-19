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
#include <queue>

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
	void findPathRecursive(graph &g);
	void findPathNonRecursive(graph &g);
	bool findShortestPath1(graph &g);
	bool findShortestPath2(graph &g);

private:
	int rows; // number of rows in the maze
	int cols; // number of columns in the maze

	matrix<bool> value;
	matrix<int> map;      // Mapping from maze (i,j) values to node index values

	bool findPathRecursiveHelper(graph &g, int currI, int currJ, bool &solved);


};

struct COORDINATE {
	int x;
	int y;
};

struct LABEL {
	struct COORDINATE coordinates;
	int distance;
	struct COORDINATE parent;
};

void maze::setMap(int i, int j, int n)
// Set mapping from maze cell (i,j) to graph node n.
{
	if (i > rows || j > cols || i < 0 || j < 0) {
		throw rangeError("maze::getMap Invalid index value(s) given for this map.");
	}

	map[i][j] = n;
}

int maze ::getMap(int i, int j) const
// Return mapping of maze cell (i,j) in the graph.
{
	if (i > rows || j > cols || i < 0 || j < 0) {
		throw rangeError("maze::getMap Invalid index value(s) given for this map.");
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
	int nodeCount = 0;
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
			else {
				setMap(i,j,-1);
			}
		}
	}

	// Add all the edges to the graph
	for (int i = 0; i <= rows - 1; i++)
	{
		for (int j = 0; j <= cols - 1; j++)
		{
			//If a valid node, check for edges
			if (map[i][j] >= 0)
			{
				// up
				if (i > 0 && map[i-1][j] >= 0)
				{
					g.addEdge(map[i][j], map[i-1][j], 1);
				}
				// down
				if (i <= rows-2 && map[i+1][j] >= 0)
				{
					g.addEdge(map[i][j], map[i+1][j], 1);
				}
				// left
				if (j > 0 && map[i][j-1] >= 0)
				{
					g.addEdge(map[i][j], map[i][j-1], 1);
				}
				// right
				if (j <= cols-2 && map[i][j+1] >= 0)
				{
					g.addEdge(map[i][j], map[i][j+1], 1);
				}
			}
		}
	}
}



void maze::findPathRecursive(graph &g)
{

	bool solved = false;
	//findPathRecursiveHelper(g, 0, 0, solved);
	print(rows-1,cols-1,0,0);

	if (!findPathRecursiveHelper(g, rows-1, cols-1, solved)) {
		cout << "No path found.";
	}
	else {
		cout << "Solved!";
	}
}


bool maze::findPathRecursiveHelper(graph &g, int currI, int currJ, bool &solved)
// Finds a path through the maze using a recursive algorithm
{
	// Are we finished?
	if(currI == 0 && currJ == 0)
	{
		solved = true;
		return true;
	}

	if (!solved) {
		int currNode = getMap(currI, currJ);

		//Mark node as visited
		g.visit(currNode);

		//Left
		if (currJ > 0 && !solved) {
			int leftNode = getMap(currI, currJ - 1);
			if (leftNode >= 0 && g.isEdge(currNode, leftNode) && !g.isVisited(leftNode)) {
				if (findPathRecursiveHelper(g, currI, currJ - 1, solved)) {
					cout << "Go Right from Node " << currNode-1 << endl;
					print(rows-1, cols-1, currI, currJ);
				}
			}
		}

		//Right
		if (currJ < cols-1 && !solved) {
			int rightNode = getMap(currI, currJ + 1);
			if (rightNode >= 0 && g.isEdge(currNode, rightNode) && !g.isVisited(rightNode)) {
				//currPath.push_back(g.getEdge(currNode, rightNode));
				if (findPathRecursiveHelper(g, currI, currJ + 1, solved)) {
					cout << "Go Left from Node " << currNode-1 << endl;
					print(rows-1, cols-1, currI, currJ);
				}
			}
		}

		//Down
		if (currI < rows-1 && !solved) {
			int upNode = getMap(currI + 1, currJ);
			if (upNode >= 0 && g.isEdge(currNode, upNode) && !g.isVisited(upNode)) {
				//currPath.push_back(g.getEdge(currNode, upNode));
				if (findPathRecursiveHelper(g, currI + 1, currJ, solved)) {
					cout << "Go Up from Node " << currNode-1 << endl;
					print(rows-1, cols-1, currI, currJ);
				}
			}
		}

		//Up
		if (currI > 0 && !solved) {
			int downNode = getMap(currI - 1, currJ);
			if (downNode >= 0 && g.isEdge(currNode, downNode) && !g.isVisited(downNode)) {
				//currPath.push_back(g.getEdge(currNode, downNode));
				if (findPathRecursiveHelper(g, currI - 1, currJ, solved)) {
					cout << "Go Down from Node " << currNode-1 << endl;
					print(rows-1, cols-1, currI, currJ);
				}
			}
		}

		if (!solved) {
			//If we get all the way through, we hit a dead end
			vector<edge> deadEnd;
			return false;
		}
		else {
			return true;
		}
	}
}


void maze::findPathNonRecursive(graph &g)
// Finds a path through the maze using a non-recursive algorithm
{
	vector<struct COORDINATE> stack;

	int startNode = getMap(0,0);
	g.visit(startNode);

	struct COORDINATE startNodeCoors;
	startNodeCoors.x = 0;
	startNodeCoors.y = 0;
	stack.push_back(startNodeCoors);

	bool foundNeighbor = false;

	while (stack.size() > 0 )
	{
		//peak at top of stack
		struct COORDINATE currNodeCoors = stack.back();

		int currJ = currNodeCoors.x;
		int currI = currNodeCoors.y;

		int currNode = getMap(currI, currJ);

		if (currJ == cols-1 && currI == rows-1)
		{
			cout << "Solved!" << endl;
			break;
		}

		foundNeighbor = false;
		// check all neighbors
		// Left
		if (currJ > 0 && !foundNeighbor) {
			int leftNode = getMap(currI, currJ - 1);
			if (leftNode >= 0 && g.isEdge(currNode, leftNode) && !g.isVisited(leftNode)) {
				struct COORDINATE temp;
				temp.x = currJ - 1;
				temp.y = currI;
				stack.push_back(temp);
				foundNeighbor = true;
				g.visit(leftNode);
				print(rows-1, cols-1, currI, currJ);
				cout << "Go Left from Node " << currNode << endl;
			}
		}

		//Right
		if (currJ < cols - 1 && !foundNeighbor) {
			int rightNode = getMap(currI, currJ + 1);
			if (rightNode >= 0 && g.isEdge(currNode, rightNode) && !g.isVisited(rightNode)) {
				struct COORDINATE temp;
				temp.x = currJ + 1;
				temp.y = currI;
				stack.push_back(temp);
				g.visit(rightNode);
				foundNeighbor = true;
				print(rows-1, cols-1, currI, currJ);
				cout << "Go Right from Node " << currNode << endl;
			}
		}

		//Down
		if (currI < rows - 1 && !foundNeighbor) {
			int upNode = getMap(currI + 1, currJ);
			if (upNode >= 0 && g.isEdge(currNode, upNode) && !g.isVisited(upNode)) {
				struct COORDINATE temp;
				temp.x = currJ;
				temp.y = currI + 1;
				stack.push_back(temp);
				g.visit(upNode);
				foundNeighbor = true;
				print(rows-1, cols-1, currI, currJ);
				cout << "Go Down from Node " << currNode << endl;
			}
		}

		//Up
		if (currI > 0 && !foundNeighbor) {
			int downNode = getMap(currI - 1, currJ);
			if (downNode >= 0 && g.isEdge(currNode, downNode) && !g.isVisited(downNode)) {
				struct COORDINATE temp;
				temp.x = currJ;
				temp.y = currI - 1;
				stack.push_back(temp);
				g.visit(downNode);
				foundNeighbor = true;
				print(rows-1, cols-1, currI, currJ);
				cout << "Go Up from Node " << currNode << endl;
			}
		}

		// If we've iterated through and found no neighbors
		if (!foundNeighbor) {
			cout << "Hit Dead End at Node " << currNode <<". Go back." << endl;
			stack.pop_back();
		}

	}

}

bool maze::findShortestPath1(graph &g)
// finds the shortest path in the maze using BFS algorithm
{
	// vector of predecessors for each node in the graph
	vector<int> pred;
	pred.resize(g.numNodes(),-1);

	vector<struct COORDINATE> predCoors;
	predCoors.resize(g.numNodes());

	// queue of the nodes being traversed
	vector<struct COORDINATE> queue;

	int startNode = getMap(0,0);
	g.visit(startNode);

	struct COORDINATE startNodeCoors;
	startNodeCoors.x = 0;
	startNodeCoors.y = 0;
	queue.push_back(startNodeCoors);

	struct COORDINATE vCoors; //front of the queue : coordinates
	int currI;
	int currJ;
	int currNode; // front of the queue: node

	while (queue.size() > 0) {
		vCoors = queue.front();
		currI = vCoors.y;
		currJ = vCoors.x;
		currNode = getMap(currI, currJ);

		// Left
		if (currJ > 0) {
			int leftNode = getMap(currI, currJ - 1);
			if (leftNode >= 0 && g.isEdge(currNode, leftNode) && !g.isVisited(leftNode)) {
				struct COORDINATE temp;
				temp.y = currI;
				temp.x = currJ - 1;
				queue.push_back(temp);
				g.visit(leftNode);

				pred.at(leftNode) = currNode;
				predCoors.at(leftNode) = temp;
			}
		}

		//Right
		if (currJ < cols - 1) {
			int rightNode = getMap(currI, currJ + 1);
			if (rightNode >= 0 && g.isEdge(currNode, rightNode) && !g.isVisited(rightNode)) {
				struct COORDINATE temp;
				temp.x = currJ + 1;
				temp.y = currI;
				queue.push_back(temp);
				g.visit(rightNode);

				pred.at(rightNode) = currNode;
				predCoors.at(rightNode) = temp;
			}
		}

		//Down
		if (currI < rows - 1) {
			int upNode = getMap(currI + 1, currJ);
			if (upNode >= 0 && g.isEdge(currNode, upNode) && !g.isVisited(upNode)) {
				struct COORDINATE temp;
				temp.x = currJ;
				temp.y = currI + 1;
				queue.push_back(temp);
				g.visit(upNode);

				pred.at(upNode) = currNode;
				predCoors.at(upNode) = temp;
			}
		}

		//Up
		if (currI > 0) {
			int downNode = getMap(currI - 1, currJ);
			if (downNode >= 0 && g.isEdge(currNode, downNode) && !g.isVisited(downNode)) {
				struct COORDINATE temp;
				temp.x = currJ;
				temp.y = currI - 1;
				queue.push_back(temp);
				g.visit(downNode);

				pred.at(downNode) = currNode;
				predCoors.at(downNode) = temp;
			}
		}

		queue.erase(queue.begin());

	}

	int target = getMap(0,0);
	int curr = getMap(rows-1, cols-1);

	if (pred.at(curr) < 0) {
		cout << "Path not found." << endl;
		return false; // no predecessors -> no path to start
	}

	else {
		cout << "Path found!" << endl;

		vector<struct COORDINATE> inOrder;
		struct COORDINATE temp;
		while (curr != target)
		{
			temp = predCoors.at(curr);
			inOrder.push_back(temp);

			curr = pred.at(curr);
		}

		temp.x = 0;
		temp.y = 0;
		inOrder.push_back(temp);

		cout << "Shortest path contains " << inOrder.size() <<  " nodes." << endl;

		print(rows-1, cols-1, 0, 0);

		for (int i = inOrder.size() - 1; i > 0; i--)
		{
			if (inOrder.at(i).x - inOrder.at(i-1).x > 0)
			{
				cout << "Go left." << endl;
			}
			else if (inOrder.at(i).x - inOrder.at(i-1).x < 0)
			{
				cout << "Go right." << endl;
			}
			else if (inOrder.at(i).y - inOrder.at(i-1).y > 0)
			{
				cout << "Go up." << endl;
			}
			else if (inOrder.at(i).y - inOrder.at(i-1).y < 0)
			{
				cout << "Go down." << endl;
			}

			print(rows-1, cols-1, inOrder.at(i-1).y, inOrder.at(i-1).x);
		}

		return true;
	}
}

bool maze::findShortestPath2(graph &g)
// finds the shortest path in the maze using Dijkstra algorithm
{
	vector<LABEL> pqueue;
	pqueue.resize(g.numNodes());

	int startNode = getMap(0,0);
	g.visit(startNode);

	struct COORDINATE startNodeCoors;
	startNodeCoors.x = 0;
	startNodeCoors.y = 0;

	struct LABEL startNodeLabel;
	startNodeLabel.coordinates = startNodeCoors;
	startNodeLabel.distance = 0;
	startNodeLabel.parent.x = -1;
	startNodeLabel.parent.y = -1;

	pqueue.push_back(startNodeLabel);

	struct LABEL currLabel; //front of the queue : coordinates
	int currI;
	int currJ;
	int currNode; // front of the queue: node

	while (queue.size() > 0) {
		currLabel = pqueue.front();
		currI = currLabel.coordinates.y;
		currJ = currLabel.coordinates.x;
		currNode = getMap(currI, currJ);

		// Check if we've solved the maze
		if (currNode == getMap(rows-1, cols-1))
		{
			break;
		}

		// Left
		if (currJ > 0) {
			int leftNode = getMap(currI, currJ - 1);
			if (leftNode >= 0 && g.isEdge(currNode, leftNode) && !g.isVisited(leftNode)) {
				struct LABEL temp;
				temp.coordinates.y = currI;
				temp.coordinates.x = currJ - 1;
				if (currLabel.distance + 1 < temp.distance)
				{
					temp.distance = currLabel.distance + 1;
					temp.parent = currLabel.coordinates;
				}

				pqueue.push_back(temp);
				cout << "Node at X: " << temp.coordinates.x << " Y: " << temp.coordiantes.y << endl;
			}
		}

		//Right
		if (currJ < cols - 1) {
			int rightNode = getMap(currI, currJ + 1);
			if (rightNode >= 0 && g.isEdge(currNode, rightNode) && !g.isVisited(rightNode)) {
				temp.coordinates.y = currI;
				temp.coordinates.x = currJ + 1;
				if (currLabel.distance + 1 < temp.distance)
				{
					temp.distance = currLabel.distance + 1;
					temp.parent = currLabel.coordinates;
				}
				queue.push_back(temp);
				cout << "Node at X: " << temp.coordinates.x << " Y: " << temp.coordiantes.y << endl;
			}
		}

		//Down
		if (currI < rows - 1) {
			int upNode = getMap(currI + 1, currJ);
			if (upNode >= 0 && g.isEdge(currNode, upNode) && !g.isVisited(upNode)) {
				temp.coordinates.y = currI + 1;
				temp.coordinates.x = currJ;
				if (currLabel.distance + 1 < temp.distance)
				{
					temp.distance = currLabel.distance + 1;
					temp.parent = currLabel.coordinates;
				}

				pqueue.push_back(temp);
				cout << "Node at X: " << temp.coordinates.x << " Y: " << temp.coordiantes.y << endl;
			}
		}

		//Up
		if (currI > 0) {
			int downNode = getMap(currI - 1, currJ);
			if (downNode >= 0 && g.isEdge(currNode, downNode) && !g.isVisited(downNode)) {
				temp.coordinates.y = currI - 1;
				temp.coordinates.x = currJ;
				if (currLabel.distance + 1 < temp.distance)
				{
					temp.distance = currLabel.distance + 1;
					temp.parent = currLabel.coordinates;
				}
				pqueue.push_back(temp);
				cout << "Node at X: " << temp.coordinates.x << " Y: " << temp.coordiantes.y << endl;
			}
		}

		pqueue.erase(pqueue.begin());

		for (int i = 0; i < pqueue.size(); i++)
		{
			for (int j = 0; j < pqueue.size(); j++)
			{
				if (pqueue.at(i).distance > pqueue.at(j).distance)
				{
					struct LABEL temp = pqueue.at(i);
					pqueue.at(i) = pqueue.at(j);
					pqueue.at(j) = temp;
				}
			}
		}

	}

}

