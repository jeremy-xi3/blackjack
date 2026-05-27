#include "Card.h"
#include <vector>
class Player {
public:
	Player(int startingMoney);
	void addCard(Card addedCard);
	void printHand();
	int getPoints();
	int getMoney();
	void clearHand();
	void changeMoney(int change, int win);

private:
	vector<Card> hand;
	int money;
	int handValue;
};