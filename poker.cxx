/*
 * Name: Julia Lin
 * Email: jylin@scu.edu
 * Lab2: Poker
 */
#include <iomanip>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#include <cassert>
#include "card.h"
#include "deck.h"
#include "poker.h"

using namespace std;

namespace lab2jylin {
	// so that we can simply "cout << " a poker hand
	ostream& operator<<(ostream& os, const Poker &h) {
		Poker temp = h;
		static const string myRank_names[] = { "HIGH CARD", "PAIR", "2PAIR", "TRIPLE", "STRAIGHT", "FLUSH", "FULLHOUSE", "QUAD", "STRAIGHT FLUSH", "ROYAL FLUSH"};
		os << myRank_names[temp.rankHand()];
		return os;
	}
}

namespace lab2jylin{
	void Poker::dealHand(){
		//deck.shuffle();
		int i;
		for (i=0; i<5; i++){
			hand[i]=deck.deal();
		//	cout << hand[i];
		}
	}

	int Poker::rankHand(){	
		PokerRank_t myRank;
		/*if(isRoyal(hand) == true && isFlush(hand) == true){
			return myRank = POKER_ROYAL_FLUSH;
		}*/
		if(isFlush(hand) == true && isStraight(hand) == true){
			return myRank = POKER_STRAIGHT_FLUSH;
		}
		if(isQuad(hand) == true){
			return myRank = POKER_QUAD;
		}
		if(isTriple(hand) == true && is2Pair(hand)){
			return myRank = POKER_FULLHOUSE;
		}
		if(isFlush(hand) == true){
			return myRank = POKER_FLUSH;
		}
		if(isStraight(hand) == true){
			return myRank = POKER_STRAIGHT;
		}
		if(isTriple(hand) == true){
			return myRank = POKER_TRIPLE;
		}
		if(is2Pair(hand) == true){
			return myRank = POKER_2_PAIR;
		}
		if(isPair(hand) == true){
			return myRank = POKER_PAIR;
		}
		else{
			return myRank = POKER_HIGHCARD;
		}
		return myRank;
	}	

	/*bool Poker::isRoyal(Card s[]){
		int i;
		if(s[0].getRank() == 9){
			int b = 10;
			for(i=1; i<5; i++){
				if(s[i].getRank() != b){
					return false;
				}
				b++;
			}
			return true; 
		}
		if(s[0].getRank() == 14){
			int b = 14;
			for(i=1; i<5; i++){
				if(s[i].getRank() != b){
					return false;
				}
				b--;
			}
			return true; 
		}
		return false;
	}*/

	bool Poker::isFlush(Card s[]) {
		int i=0;
		int j;
		for(j=1; j<5; j++){
			if(s[i].getSuit() != s[j].getSuit()){
				return false;
			}
		}
		return true;
	}

	bool Poker::isStraight(Card r[]) {
		int i;
		int flag = 0;
		int count = 0;
		int rank3;
		int rank2[14] = {0, 0, 0, 0, 0, 0, 0,0 ,0 ,0 ,0 ,0 ,0, 0};
		for(i=0; i<5; i++){
			rank3 = r[i].getRank();
			if (rank3 == 13){
				rank2[0]++;
				rank2[13]++;
			}
			else{
				rank2[rank3]++;
			}
		}
		for(i=0; i<14; i++){
			if((rank2[i]!= 0) && (flag==0)){
				flag = 1;
				count++;
			}
			else if((rank2[i]!=0) && (flag==1)){
				count++;
			}
			if(count==5){
				return true;
			}
			if(rank2[i]==0){
				flag = 0;
				count = 0;
			}
		}
		return false;
	}
		//sort(begin(r), end(r));
	/*	int b=r[0].getRank();
		int k=r[0].getRank();
		for(i=1; i<5; i++){
			b++;
			k--;
			if((r[i].getRank() != b) && (r[i].getRank() != k)){
				return false;
			}
		}
		return true;*/

	bool Poker::isQuad(Card r[]) {
		for (int i = 0; i < 2; i++) {
			int count = 0;
			for (int j = 0; j < 5; j++) {
				if (r[j].getRank() == r[i].getRank()) {
					count++;
				}
			}
			if (count == 4) {
				return true;
			}
		}
		return false;
	}

	bool Poker::isTriple(Card r[]) {
		for (int i = 0; i < 3; i++) {
			int count = 0;
			for (int j = 0; j < 5; j++) {
				if (r[j].getRank() == r[i].getRank()) {
					count++;
				}
			}
			if (count == 3) {
				return true;
			}
		}
		return false;
	}

	bool Poker::is2Pair(Card r[]){
		int i;
		int b;
		int k;
		for(i=0; i<5; i++){
			int count = 0;
			for(int j = 0; j<5; j++){
				if(r[j].getRank() == r[i].getRank()){
					count++;
				}
			}
			if(count==2){
				break;
			}
		}
		if (i == 5){
			return false;
		}
		i++;
		for(k=i; k<5; k++){
			int count2 = 0;
			for(b=k; b<5; b++){
				if(r[k].getRank() == r[b].getRank()){
					count2++;
				}
			}
			if(count2==2){
				return true;
			}
		}
		return false;
	}

	bool Poker::isPair(Card r[]){
		for (int i = 0; i < 5; i++) {
			int count = 0;
			for (int j = i; j < 5; j++) {
				if (r[j].getRank() == r[i].getRank()) {
					count++;
				}
			}
			if (count == 2) {
				if (is2Pair(r) == true){
					return false;
				}
				return true;
			}
		}
		return false;	
	}

}

