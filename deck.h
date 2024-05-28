/*
 * Name: Julia Lin
 * Email: jylin@scu.edu
 * Lab2: Poker
 */
namespace lab2jylin {
	// Deck class with an embedded Card class
	// See stand-alone Card class in "card.h"
	class Deck {
	public:
		static const size_t CARDS_PER_DECK = 52;
		// contructor here to initialize members
		//Deck(int x=CARDS_PER_DECK, int y= 0, int z=1){};
		Deck(int nCards=CARDS_PER_DECK, int next = 0, int guard=1);

		const lab2jylin::Card &deal(void);
		void shuffle(void);
	
	friend std::ostream& operator<<(std::ostream& os, const Deck &);

	private:
		int nCards;
		lab2jylin::Card cards[CARDS_PER_DECK];
		int next;
		int guard;
	};
}
//Deck(int nCards=CARDS_PER_DECK, int next = 0, int guard=1){}