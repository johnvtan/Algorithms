// Mary Forde, John Tan
// Project 2

// This file declares the "deck" class, which represents a deck of cards
#include"card.h"
#include"cardNode.h"

class deck
{
	public:
		deck();
		cardNode* getHead() { return first; }
		void printDeck();
	
        friend ostream& operator<< (ostream& ostr, deck& d);
	
	private:
		cardNode* first;
	
};
