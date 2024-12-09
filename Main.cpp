#include <iostream>
#include <string>
#include "Player.h"
#include "Game.h"

using namespace std;

int main() {
	string player1Name, player2Name;

	
	cout << "Enter name for Player 1: ";
	getline(cin, player1Name);
	cout << "Enter name for Player 2: ";
	getline(cin, player2Name);

	Player p1(player1Name);
	Player p2(player2Name);

	cout << "Player 1 is: " << p1.getName() << "\n";
	cout << "Player 2 is: " << p2.getName() << "\n";

	Game game;

	game.startGame(p1, p2);
	game.printHands(p1, p2);

	p1.addCard(game.hit(p1));
	p2.addCard(game.hit(p2));

	p1.displayHand();
	p2.displayHand();

	game.printHands(p1, p2);

	return 0;
}