// Mary Forde, John Tan
// Project 2

// Initializes a deck, prints it, then shuffles the deck and prints the
// shuffled deck.

#include"deck.h"
#include<time.h>

using namespace std;

int main() {
	// random seed
	srand(time(NULL));

	deck d;
	
    card c;
	c = d.deal();
    
    d.replace(c);
    
	//cout << "c: " << c;  
    cout << "deck: " << d;
        
	return 0;
}
