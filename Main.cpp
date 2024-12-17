#include <iostream>
#include <string>
#include "Player.h"
#include "Game.h"

using namespace std;

void playerTurn(Game& game, Player& player) {
	char choice;
	do {
		cout << player.getName() << ", do you want to hit (h) or stay (s)?";
		try {
			cin >> choice;
			if (choice != 'h' && choice != 's') { 
				cin.clear();

				throw invalid_argument("Invalid input.Please enter 'h' or 's'."); 
			}
			else if (choice == 'h') {
				Card newCard = game.hit(player);
				player.displayHand();
				if (game.isBust(player.getHand())) {
					cout << player.getName() << " Bust! Game over.\n";
					return;
				}
			}
			else if (choice == 's') {
				cout << player.getName() + " stays";
			}
		}
		catch (const invalid_argument& exception) { cout << exception.what() << endl; }
	} while (choice != 's');
}

int main() {
	string player1Name, player2Name;
	char playAgain;
	
	cout << "Enter name for Player 1: ";
	getline(cin, player1Name);
	cout << "Enter name for Player 2: ";
	getline(cin, player2Name);

	Player p1(player1Name);
	Player p2(player2Name);

	cout << "Player 1 is: " << p1.getName() << "\n";
	cout << "Player 2 is: " << p2.getName() << "\n";

	Game game;

	do {
		game.startGame(p1, p2);
		cout << "\n";

		game.printHands(p1, p2);
		cout << "\n";

		playerTurn(game, p1);
		cout << "\n";
		playerTurn(game, p2);
		cout << "\n";
		game.dealerTurn(p1, p2);
		cout << "\n";

		game.printHands(p1, p2);
		cout << "\n";

		p1.displayHand();
		cout << "\n";
		p2.displayHand();
		cout << "\n";

		cout << game.determineWinner(p1) << "\n";
		cout << game.determineWinner(p2) << "\n";

		while (true) {
			cout << "Do you want to play again? (y/n): ";
			try {
				cin >> playAgain;
				if (playAgain != 'y' && playAgain != 'n') throw invalid_argument("Invalid input.Please enter 'y' or 'n'.");
				else { break; }
			}
			catch (const invalid_argument& exception) { cout << exception.what() << endl; }
		}

	} while (playAgain == 'y');

	cout << "Thank you for playing!" << endl;

	return 0;
}