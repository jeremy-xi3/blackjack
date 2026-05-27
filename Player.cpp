#include "Player.h"
#include <iostream>

Player::Player(int startingMoney) {
	money = startingMoney;
	handValue = 0;
}

void Player::addCard(Card addedCard) {
	hand.push_back(addedCard);
	handValue += addedCard.getCardValue();
}

void Player::printHand() {
	cout << "\nPlayer hand is: | ";
	for (size_t i = 0; i < hand.size(); i++) {
		cout << hand[i].getCardName() << " | ";
	}
	cout << "   Current hand value: " << handValue << endl;
}

int Player::getPoints() {
	return handValue;
}

int Player::getMoney() {
	return money; 
}

void Player::clearHand() {
	for (size_t i = 0; i < hand.size(); i++) {
		hand.erase(hand.begin());
	}
	handValue = 0;
}

void Player::changeMoney(int change, int win) {
	change *= win;
	money += change;
}