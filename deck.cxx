/*
 * Name: Julia Lin
 * Email: jylin@scu.edu
 * Lab2: Poker
 */
#include <iomanip>
#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;
#include "card.h"
#include "deck.h"

// Deck class implementation
namespace lab2jylin {
	// deal out one card
	const Card &Deck::deal() {
		// this is stud function.  Replace it with your code
		if((nCards-guard)<=next){
			shuffle();
		}
		return cards[next++];
	}

	// print 13 cards each row
	ostream& operator<<(ostream& os, const Deck &d) {
		int i;
		for(i=0; i<d.nCards; i++){
			cout << d.cards[i];
		}
		return os;
	}

Deck::Deck(int nCards, int next, int guard){
		int i, j, count=0;
		for(i=1; i<5; i++){
			for(j=1; j<14; j++){
				cards[count] = Card(i,j);
				count++;
			}
		}
		this->nCards=nCards;
		this->next=next;
		this->guard=guard;
	}
}


