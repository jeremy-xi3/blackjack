#include "BlackJack.h"
#include <iostream>

using namespace std;

int main() {
	bool game = true;
	while (game) {
		BlackJack startGame = BlackJack();
		cout << "You have reached the end of the game. Input y to play again. ";
		string input;
		cin >> input;
		if (input != "y") game = false;
	}

}
