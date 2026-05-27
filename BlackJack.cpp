#include "BlackJack.h"
#include <iostream>

using namespace std;

BlackJack::BlackJack() {
	int numDecks;
	dealerPoints = 0;
	cout << "Please enter the amount of decks to be used: ";
	while (!(cin >> numDecks) or numDecks < 1) {
		cout << "Invalid input, please enter a positive integer: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	Deck* newerDeck = new Deck(numDecks);
	newDeck = newerDeck;

	int startingMoney;
	cout << "\nHow much money would you like to start with? $";
	while (!(cin >> startingMoney) or startingMoney < 1) {
		cout << "Invalid input, please enter a positive integer: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	Player* newPlayer = new Player(startingMoney);
	newerPlayer = newPlayer;
	gameQuery();
}

void BlackJack::gameQuery() {
	int bet;
	cout << "Your balance is $" << newerPlayer->getMoney() <<
		".\nHow much would you like to bid? $";
	while (!(cin >> bet) or bet < 1 or bet > newerPlayer->getMoney()) {
		cout << "Invalid input, please enter a positive integer equal" 
			 << " to or less than your balance: $";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	startRound();

	//start query
	bool game = true;
	while (game) {
		printBoard();
		cout << "Player Action: ";
		string input;
		cin >> input;

		if (input == "hit") {
			hitFunction();
			if (newerPlayer->getPoints() >= 21) {
				game = false;
			}
		}

		else if (input == "stand") {
			game = false;
		}

		else {
			cout << "Input \"hit\" or \"stand\" to play." << endl;
		}
	}
	newerPlayer->changeMoney(bet, dealerFunction(bet));
}

void BlackJack::startRound() {
	//add first card for player
	newerPlayer->addCard(newDeck->drawCard());

	//add first card for dealer and hide it from client
	dealer.push_back(newDeck->drawCard());
	dealer[0].hideCard();

	//add second card for player
	newerPlayer->addCard(newDeck->drawCard());
	
	//add second card for dealer but do not hide it from client
	dealer.push_back(newDeck->drawCard());
	dealerPoints += dealer[1].getCardValue();

}

void BlackJack::printDealerHand() {
	cout << "Dealer's hand: | ";
	for (size_t i = 0; i < dealer.size(); i++) {
		cout << dealer[i].getCardName() << " | ";
	}
	cout << "Dealer's revealed hand value: " << dealerPoints << endl;
} 

void BlackJack::printBoard() {
	newerPlayer->printHand();
	printDealerHand();
	cout << "\n\\---------------------------------------------\\\n" << endl;
}

void BlackJack::hitFunction() {
	newerPlayer->addCard(newDeck->drawCard());
}

int BlackJack::dealerFunction(int bet) {
	if (newerPlayer->getPoints() > 21) {
		cout << "Bust!" << endl;
		return -1;
	}

	//reveal dealer card
	dealer[0].hideCard();
	dealerPoints += dealer[0].getCardValue();
	printBoard();

	//hit until > 16
	while (dealerPoints < 17) {
		dealer.push_back(newDeck->drawCard());
		dealerPoints += dealer.back().getCardValue();
		printBoard();
	}

	if (dealerPoints > 21) {
		cout << "You gain $" << bet << endl;
		return 1;
	}

	if (dealerPoints > newerPlayer->getPoints()) {
		cout << "You lost $" << bet << endl;
		return -1;
	}
	else if (dealerPoints < newerPlayer->getPoints()) {
		cout << "You gain $" << bet << endl;
		return 1;
	}
	else {
		cout << "Draw!" << endl;
		return 0;
	}
}