/*
 * Name: Julia Lin
 * Email: jylin@scu.edu
 * Lab2: Poker
 */
#include <cstdlib>
#include <iomanip>
#include <iostream>

using namespace std;
#include "card.h"
#include "deck.h"

namespace lab2jylin {
	// Fisher-Yates shuffle
	void Deck::shuffle(void) { 
		int i;
		int j;
		// Use a different seed value so that 
		// we don't get same result each time
		// we run this program 
		srand (time(NULL)); 
		//cout << "Shuffling:" << endl;
		// Start from the last element and swap 
		// one by one. We don't need to run for 
		// the first element that's why i > 0 
		for (int i = nCards - 1; i > 0; i--) { 
			// Pick a random index from 0 to i 
			int j = rand() % (i + 1); 
	
			// Swap arr[i] with the element 
			// at random index 
			Card temp = cards[i];
			cards[i] = cards[j];
			cards[j] = temp;
			next = 0;
		} 
	}	 
}




