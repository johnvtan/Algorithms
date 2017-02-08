// Mary Forde, John Tan
// Project 2

// This file declares the "deck" class, which represents a deck of cards
#include"card.h"
#include <iostream>

class cardNode
{
	public:
		// data members
		card c;
		cardNode *next;
		
		// constructors
		cardNode() {}
        
                // changed, but we never use this anyway
		cardNode(const cardNode& head) {
			c = head.c;
			next = head.next;
		}
	
};

class deck
{
	public:
		deck();
		//void printDeck();
	
               friend ostream& operator<< (ostream& ostr, const cardNode& head);
	private:
		cardNode* first;
	
	

};
