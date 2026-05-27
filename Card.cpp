#include "Card.h"

using namespace std;

Card::Card(int type, int suits) {
	hidden = false;
	value = type;
	if (value > 10) value = 10;
	if (type > 1 and type < 11) {
		cardType = to_string(type);
	}
	else if (type == 1) {
		cardType = "Ace";
		value = 11;
	}
	else if (type == 11) cardType = "Jack";
	else if (type == 12) cardType = "Queen";
	else {
		cardType = "King";
	}
	if (suits == 1) {
		suit = "diamonds";
	}
	else if (suits == 2) suit = "clubs";
	else if (suits == 3) suit = "hearts";
	else suit = "spades";
}

string Card::getCardName() {
	if (hidden) return "Mystery Card!";
	return cardType + " of " + suit;
}

int Card::getCardValue() {
	return value;
}

void Card::hideCard() {
	hidden = !hidden;
}

bool Card::checkCardHidden() {
	return hidden;
}