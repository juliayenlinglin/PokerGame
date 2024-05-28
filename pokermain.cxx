/*
 * Name: Julia Lin
 * Email: jylin@scu.edu
 * Lab2: Poker
 */
#include <ctime>
#include <iomanip>
#include <iostream>
#include <cstring>
#include <cmath>
#include <ctime>
#include "card.h"
#include "deck.h"
#include "poker.h"

using namespace std;
using namespace lab2jylin;


double percentage(int x){
		double y;
		y = x/8795000.0*100.0;
		double roundedy = round(y*1000.0)/1000.0;
		return roundedy;
	}

// Poker test code
int main(void) {
	cout << "One hand for each ranking" << endl;

	int i;
	int rankHandcount[10] = {0};
	Poker p;

	clock_t start = clock();

	for(i=0; i<8795000; i++){
		p.dealHand();
		rankHandcount[p.rankHand()]++;
		//cout << p << endl;
		//cout << p.rankHand()<<endl;
	} 

	clock_t end = clock();
	double elapsed_time = double(end - start)/CLOCKS_PER_SEC;
	cout << "Time elapsed:" << 	elapsed_time << " seconds" << endl;
		
	cout << "Statistics:" << endl;
	//cout << setw(15)<< "Royal Flush:" << setw(10) << rankHandcount[9] << setw(10) << percentage(rankHandcount[9]) << "%" << endl;
	cout << setw(15)<< "Straight Flush:" << setw(10) << rankHandcount[8] << setw(10) << percentage(rankHandcount[8]) << "%" << endl;
	cout << setw(15)<< "Four of a Kind:" << setw(10) << rankHandcount[7] << setw(10) << percentage(rankHandcount[7]) << "%" << endl;
	cout << setw(15)<< "Full House:" << setw(10) << rankHandcount[6] << setw(10) << percentage(rankHandcount[6]) << "%" << endl;
	cout << setw(15)<< "Flush:" << setw(10) << rankHandcount[5] << setw(10) << percentage(rankHandcount[5]) << "%" << endl;
	cout << setw(15)<< "Straight:" << setw(10) << rankHandcount[4] << setw(10) << percentage(rankHandcount[4]) << "%" << endl;	
	cout << setw(15)<< "Triple:" << setw(10) << rankHandcount[3] << setw(10) << percentage(rankHandcount[3]) << "%" << endl;
	cout << setw(15)<< "Two Pairs:" << setw(10) << rankHandcount[2] << setw(10) << percentage(rankHandcount[2]) << "%" << endl;
	cout << setw(15)<< "Pair:" << setw(10) << rankHandcount[1] << setw(10) << percentage(rankHandcount[1]) << "%" << endl;
	cout << setw(15)<< "High Card:" << setw(10) << rankHandcount[0] << setw(10) << percentage(rankHandcount[0]) << "%" << endl;


	/*Poker p;
	p.dealHand();
	cout << p << endl;
	cout << p.rankHand()<<endl;

	p.dealHand();
	cout << p << endl;
	cout << p.rankHand()<<endl;*/

	return EXIT_SUCCESS;
}

