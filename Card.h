#pragma once
#include <string>
using namespace std;

class Card {
	public:
		Card(int type, int suits);
		string getCardName();
		int getCardValue();
		void hideCard();
		bool checkCardHidden();
	
	private:
		string cardType;
		string suit;
		int value;
		bool hidden;
};