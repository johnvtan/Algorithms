// Mary Forde, John Tan
// Project 2

// This file implements the methods of the "deck" class

#include"deck.h"
#include <iostream>
using namespace std;

deck::deck() 
// default constructor, creates a standard deck of 52 cards
{	
	cardNode curr; // tracks where we are as we add cards to the deck
	first = curr; // the deck starts here
	
	
	// iterates through the card values
	for(int valueInt = ace; valueInt != END_VAL ; valueInt++)
	{
		
		// iterates through the card suits
		for (int suitInt = club; suitInt != END_SUIT; suitInt++)
		{
			card c(static_cast<suit>(suitInt), static_cast<value>(valueInt));
			cardNode newCard(c);
			cout << c;
			curr.next = &newCard;
			curr = newCard;
		}
	}
}
