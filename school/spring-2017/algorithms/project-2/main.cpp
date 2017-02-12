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
	
	cout << "Not shuffled:\n";
    cout <<  d;	
    
    d.shuffle();
    
    cout << "\nShuffled:\n";
    cout << d;

	return 0;
}
