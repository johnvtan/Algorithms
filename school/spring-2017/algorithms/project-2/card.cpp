// Mary Forde, John Tan
// Project 2

// This file implements the methods of the "card" class

#include"card.h"
//#include<string.h>

using namespace std;

card::card(suit s, value v) 
// constructor for a card
{
	setValue(v);
	setSuit(s);
}

ostream& operator<< (ostream& ostr, const card& c)
// overloads the << operator
{
	ostr << c.valueToString() << " of " << c.suitToString() << endl;	
}

string card::suitToString() const
// returns this card's suit, as a string (ex: "Spades")
{
	switch(cardSuit) {
		case spade:
			return "Spades";
		case heart:
			return "Hearts";
		case club:
			return "Clubs";
		case diamond: 
			return "Diamonds";
	}
}

string card::valueToString() const
// returns this card's value, as a string (ex: "Ace", "2")
{
	switch(cardVal) {
		case ace:
			return "Ace";
		case two:
			return "2";
		case three:
			return "3";
		case four: 
			return "4";
		case five: 
			return "5";
		case six: 
			return "6";
		case seven: 
			return "7";
		case eight: 
			return "8";
		case nine: 
			return "9";
		case ten: 
			return "10";
		case jack: 
			return "Jack";
		case queen: 
			return "Queen";
		case king: 
			return "King";				
	}
}

