#include "Deck.h"
#include "Player.h"

class BlackJack {
public:
	BlackJack();
	void gameQuery();
	void startRound();
	void printDealerHand();
	void printBoard();
	void hitFunction();
	int dealerFunction(int bet);

private:
	Player* newerPlayer;
	Deck* newDeck;
	vector<Card> dealer;
	int dealerPoints;
};