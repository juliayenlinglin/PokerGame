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

// Test program for Card
// test code just for Card class
int main(void) {
	lab2jylin::Card AceSpade(4, 13);
	lab2jylin::Card AceClub(1, 13);
	int intValue = int(AceSpade);
	cout <<intValue<<endl;
	cout<<AceSpade;
	cout<<AceClub;

	

	if(AceClub<AceSpade){
		cout<<"true"<<endl;
	}
	else{
		cout<<"false"<<endl;
	}

	return EXIT_SUCCESS;
}
