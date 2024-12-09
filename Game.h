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
	void printHands(const Player& player1, const Player& player2);
	Card hit(Player& player);
};

#endif
