#include "Game.h"
#include <iostream>


void Game::startGame(Player& player1, Player& player2) {
	deck.shuffle();

	player1.addCard(deck.dealCard());
	player2.addCard(deck.dealCard()); 
	dealerHand.push_back(deck.dealCard());
	player1.addCard(deck.dealCard());
	player2.addCard(deck.dealCard());
	dealerHand.push_back(deck.dealCard());

	
	/*playerHand.push_back(deck.dealCard());
	dealerHand.push_back(deck.dealCard());
	playerHand.push_back(deck.dealCard());
	dealerHand.push_back(deck.dealCard());*/

}

void Game::printHands(const Player& player1, const Player& player2) {


	cout << player1.getName() << "'s hand: ";
	for (const auto& card : player1.getHand()) {
		cout << card.toString() << ", ";
	}
	cout << "\n";

	cout << player2.getName() << "'s hand: ";
	for (const auto& card : player2.getHand()) {
		cout << card.toString() << ", ";
	}
	cout << "\n";

	cout << "Dealer's hand: ";
	for (const auto& card : dealerHand) {
		cout << card.toString() << ", ";
	}
	cout << "\n";

}

Card Game::hit(Player& player) {
	Card card = deck.dealCard();
	playerHand.push_back(card);
	return card;
}