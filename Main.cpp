#include <iostream>
#include <string>
#include "Player.h"

using namespace std;

int main() {
	string player1, player2;
<<<<<<< Updated upstream
	
	cout << "Enter name for Player 1: ";
	getline(cin, player1);
	cout << "Enter naem for player 2: ";
=======

	cout << "Enter name for Player 1: ";
	getline(cin, player1);
	cout << "Enter name for Player 2: ";
>>>>>>> Stashed changes
	getline(cin, player2);

	Player p1(player1);
	Player p2(player2);

	cout << p1.getName() << "\n";
	cout << p2.getName() << "\n";
<<<<<<< Updated upstream
=======


>>>>>>> Stashed changes
	

	return 0;
}