#include "Card.h"
#include <vector>
#include <queue>
#include <random>
#include <algorithm>

class Deck {
public:
	Deck(int iterations);
	Card drawCard();
	void print();
	void shuffleDeckFunction();
	int getDeckSize();

private:
	queue<Card> fullDeck;
	vector<Card> shuffleDeck;
};