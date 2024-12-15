#ifndef GAME_H
#define GAME_H

#include <vector>
#include <string>
#include "Card.h"
#include "Deck.h"
#include "Player.h"

class Game {
private:
	Deck deck;
	vector<Card> playerHand;
	vector<Card> dealerHand;

public:
	void startGame(Player& player1, Player& player2);
	int calculateHand(const vector<Card>& hand);
	bool isBlackJack(const vector<Card>& hand);
	bool isBust(const vector<Card>& hand);
	string determineWinner(const Player& player1);
	void printHands(const Player& player1, const Player& player2);
	void dealerTurn(const Player& player1, const Player& player2);
	Card hit(Player& player);

	
};

#endif
