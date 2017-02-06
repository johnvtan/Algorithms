// Mary Forde, John Tan
// Project 2

// This file declares the "deck" class, which represents a deck of cards
#include"card.h"

class cardNode
{
	public:
		// data members
		card c;
		cardNode *next;
		
		// constructors
		cardNode() {}
		cardNode(const card& card, cardNode *nextNode = NULL) {
			c = card;
			next = nextNode;
		}
	
};

class deck
{
	public:
		deck();
		//void printDeck();
	
	private:
		cardNode first;
	
	

};
