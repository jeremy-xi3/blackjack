#include "Deck.h"
#include <iostream>
using namespace std;

Deck::Deck(int iterations) {
// number of decks
	for (int i = 0; i < iterations; i++) {
		// each suit
		for (int j = 1; j < 5; j++) {
			// each card
			for (int k = 1; k < 14; k++) {
				Card insert = Card(k, j);
				shuffleDeck.push_back(insert);
			}
		}
	}
	random_device rd;
	mt19937 g(rd());
	shuffle(shuffleDeck.begin(), shuffleDeck.end(), g);
	while (!shuffleDeck.empty()) {
		fullDeck.push(shuffleDeck.front());
		shuffleDeck.erase(shuffleDeck.begin());
	}
}

void Deck::print() {
	while (!fullDeck.empty()) {
		Card printCard = fullDeck.front();
		cout << printCard.getCardName() << endl;
		fullDeck.pop();
	}
}

Card Deck::drawCard() {
	if (fullDeck.empty()) {
		cout << "Empty deck" << endl;
		shuffleDeckFunction();
		return drawCard();
	}
	Card topCard = fullDeck.front();
	shuffleDeck.push_back(topCard);
	fullDeck.pop();
	return topCard;
}

void Deck::shuffleDeckFunction() {
	while (!fullDeck.empty()) {
		Card copy = fullDeck.front();
		shuffleDeck.push_back(copy);
		fullDeck.pop();
	}

	//randomizing function
	random_device rd;
	mt19937 g(rd());
	shuffle(shuffleDeck.begin(), shuffleDeck.end(), g);
	while (!shuffleDeck.empty()) {
		fullDeck.push(shuffleDeck.front());
		shuffleDeck.erase(shuffleDeck.begin());
	}
}

int Deck::getDeckSize() {
	return fullDeck.size();
}