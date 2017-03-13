// Mary Forde, John Tan
// Project 2

// This file declares the "deck" class, which represents a deck of cards
#include"card.h"
#include"node.h"

class deck
{
	public:
		// constructor
		deck();
		deck(const card& c);
		
		// destructor
		~deck();
		
		// public deck operations
		node<card>* getHead() { return first; }
		void shuffle();
		card deal();
		void replace(const card& c);
		card atIndex(int i);
	
		// cout overloader
        friend ostream& operator<< (ostream& ostr, deck& d);
        
	private:
		// data members
		node<card>* first;
		
		// private deck operations
		node<card>* getNodeAtIndex(int i);
		void swap(int i1, int i2);
};
