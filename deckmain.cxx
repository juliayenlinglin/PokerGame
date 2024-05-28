/*
 * Name: Julia Lin
 * Email: jylin@scu.edu
 * Lab2: Poker
 */
#include <iomanip>
#include <iostream>
#include "card.h"
#include "deck.h"

using namespace std;
using namespace lab2jylin;

// Test program for Deck class
int main(void) {
	lab2jylin::Deck d(52, 0, 1);
	cout << d;
	int i;
	for(i=1; i<100; i++){
		cout << d.deal(); 
	}
	return EXIT_SUCCESS;
}

