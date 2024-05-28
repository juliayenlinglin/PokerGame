/*
 * Name: Julia Lin
 * Email: jylin@scu.edu
 * Lab2: Poker
 */
#ifndef POKER_H
#define POKER_H

// Poker class
namespace lab2jylin {
	class Poker {
	public:
		// An int to define each of the poker ranking
		// in decending order here.  Therefore 0 is the lowest rank, which is High card
		using PokerRank_t = int;
		// You could also use enum
		//static const PokerRank_t POKER_ROYAL_FLUSH = 9;
		static const PokerRank_t POKER_STRAIGHT_FLUSH = 8;
		static const PokerRank_t POKER_QUAD = 7;
		static const PokerRank_t POKER_FULLHOUSE = 6;
		static const PokerRank_t POKER_FLUSH = 5;
		static const PokerRank_t POKER_STRAIGHT = 4;
		static const PokerRank_t POKER_TRIPLE = 3;
		static const PokerRank_t POKER_2_PAIR = 2;
		static const PokerRank_t POKER_PAIR = 1;
		static const PokerRank_t POKER_HIGHCARD = 0;

		Poker(){

		};
		void dealHand();
		int rankHand();
		friend std::ostream& operator<<(std::ostream& os, const Poker &c);

	private:
		Deck deck;
		lab2jylin:: Card hand[5];
		// use a member to store the the hand as opposed to dealHand returning a pointer
		// don't want to deal with new/delete yet

		// helper functions for ranking, you should implement them in poker.cxx
		//bool isRoyal(Card s[]);
		bool isFlush(Card s[]);
		bool isStraight(Card r[]);
		bool isQuad(Card r[]);
		bool isTriple(Card r[]);
		bool is2Pair(Card r[]);
		bool isPair(Card r[]);
	};
}

#endif // POKER_H
