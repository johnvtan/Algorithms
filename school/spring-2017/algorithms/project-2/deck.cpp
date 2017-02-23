// Mary Forde, John Tan
// Project 2

// This file implements the methods of the "deck" class

#include"deck.h"

using namespace std;

deck::deck() 
// default constructor, creates a standard deck of 52 cards
{	
	first=NULL;

	// iterates through the card values
	for (int suitInt = spade; suitInt != END_SUIT; suitInt++)
	{
		
		// iterates through the card suits
		for (int valueInt = king; valueInt != END_VAL ; valueInt++) 
		{     
			card ca(static_cast<suit>(suitInt), 
			        static_cast<value>(valueInt));
			        
			node<card>* newCard = new node<card>;
            
			newCard->nodeValue = ca;
            newCard->next = NULL;
            
            // pointing current node to first
            newCard->next = first;
            first = newCard;        
		}
	}
	
	
} // end default constructor

deck::deck(const card& c)
// creates a deck which only contains the given card
{
	node<card>* newCard = new node<card>();
	newCard->nodeValue = c;
	newCard->next = NULL;
	
	first = newCard;
}


deck::~deck()
//destructor
{
	while(first->next != NULL)
	{
		node<card>* next = first->next;
		delete first;
		first = next;	
	}
	
	delete first;
	first = NULL;
} // end destructor

ostream& operator<< (ostream& ostr, deck& d)
// overloads the cout operator to print the full deck
{
    node<card>* curr = d.getHead();
    
    while (curr->next != NULL)
    {
        ostr << curr->nodeValue;
        curr = curr->next;
    }
    ostr << curr->nodeValue;
    ostr << endl;
    return ostr;
} // end operator<<


node<card>* deck::getNodeAtIndex(int i)
// gets the "i"th card of the deck 
{
	node<card>* curr = first;
	int n = 0;
	while (n < i && curr->next != NULL) 
	{
		curr = curr->next;	
		n++;
	}	
	
	return curr;
} // end getNodeAtIndex

void deck::swap(int i1, int i2) 
// swaps the card data members of the nodes at the given indexes
{
	node<card>* cNode1 = getNodeAtIndex(i1);
	node<card>* cNode2 = getNodeAtIndex(i2);
	
	card tempCard = cNode1->nodeValue;
	
	cNode1->nodeValue = cNode2->nodeValue;
	
	cNode2->nodeValue = tempCard;
} // end swap

void deck::shuffle() 
// shuffles the cards randomly
{
	int rand1, rand2;
	
	for (int i = 0; i < 100; i++) {
		rand1 = rand() % 52; // 0 - 51, our indexes
		rand2 = rand() % 52;
		swap(rand1, rand2);
	}
} // end shuffle

card deck::deal() 
// returns the top cards of the deck, and removes it from the deck
{
	card c(first->nodeValue);
	
	first = first->next;
	
	return c;
} // end deal

void deck::replace(const card& c) 
// adds the given card to the bottom of the deck
{
	node<card>* curr = first;
	
	while (curr->next != NULL) 
	{
		curr = curr->next;
	}
	
	node<card> *newCard = new node<card>;
	newCard->nodeValue = c;
	newCard->next = NULL;
		
	curr->next = newCard;
}

card deck::atIndex(int i)
// returns the card at the given index of the deck
{
	node<card>* curr = first;
	
	for (int j = 0; j < i; j++)
	{
		curr = curr->next;
	}
	
	return curr->nodeValue;
}

