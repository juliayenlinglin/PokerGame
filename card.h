/*
 * Name: Julia Lin
 * Email: jylin@scu.edu
 * Lab2: Poker
 */
#ifndef CARD_H
#define CARD_H
using namespace std;


// short hand to define static const varables

// stand-alone Card class
namespace lab2jylin {
	class Card {
	public:
		using rank_t = int;
		using suit_t = int;
		Card(suit_t s=0, rank_t r=0): rank{r}, suit{s} {
			
		}

		suit_t getSuit() const { return suit; } 
		rank_t getRank() const { return rank; }
	
	friend std::ostream& operator<<(std::ostream& os, const Card &c);
	
	bool operator<(const Card&rhs);

	// encode a card into an integer
	operator int() const;

	private:
		rank_t rank;	// A, King, Queen, ..., 2
		suit_t suit;	// Spade, Heart, Diamond, Club
	};
}

#endif // CARD_H
