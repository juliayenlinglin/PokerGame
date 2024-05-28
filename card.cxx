/*
 * Name: Julia Lin
 * Email: jylin@scu.edu
 * Lab2: Poker
 */
#include <iomanip>
#include <iostream>
#include "card.h"
using namespace std;
using namespace lab2jylin;

const string SPADE = "\u2660";
const string HEART = "\u2665";
const string DIAMOND = "\u2666";
const string CLUB = "\u2663";

// Stand-alone Card definitions
namespace lab2jylin {
	ostream& operator<<(ostream& os, const lab2jylin::Card &c) {
		// implement cout
		static const string rank_names[] = { "0", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King", "Ace"};
        //static const string suit_names[] = { "0", "Clubs", "Diamonds", "Hearts", "Spades" };
		static const string suit_names[] = { "0", CLUB, DIAMOND, HEART, SPADE };

		os << suit_names[c.suit]<< " ";
		os << rank_names[c.rank] << endl;
		return os;
	}
}


Card::operator int() const{
	int cardValue;
	cardValue = suit + rank*5;
	return cardValue;
}

bool Card::operator<(const Card&rhs){
	if (rank<rhs.rank){
		return true;
	}
	else if (rank == rhs.rank){
		if(int(rank)<int(rhs)){
			return true;
		}
		else{
			return false;
		}
	}
	else{
		return false;
	}
}