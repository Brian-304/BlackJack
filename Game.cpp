#include "Game.h"
#include <iostream>


void Game::startGame(Player& player1, Player& player2) {
	deck.shuffle();

	player1.clearHand();
	player2.clearHand();
	dealerHand.clear();

	player1.addCard(deck.dealCard());
	player2.addCard(deck.dealCard()); 
	dealerHand.push_back(deck.dealCard());
	player1.addCard(deck.dealCard());
	player2.addCard(deck.dealCard());
	dealerHand.push_back(deck.dealCard());

}

int Game::calculateHand(const vector<Card>& hand) {
	int value = 0;
	int numAces = 0;

	for (const auto& card : hand) {
		string rank = card.getRank();

		if (rank == "Ace") {
			value += 11;
			numAces++;
		} else if (rank == "King" || rank == "Queen" || rank == "Jack") {
			value += 10;
		} else {
			value += stoi(rank);
		}

	}

	while (value > 21 && numAces > 0) {
		value -= 10;
		numAces--;
	}

	return value;
}

bool Game::isBlackJack(const vector<Card>& hand) {
	return calculateHand(hand) == 21;

}

bool Game::isBust(const vector<Card>& hand) {
	return calculateHand(hand) > 21;
}

string Game::determineWinner(const Player& player) {
	int playerValue = calculateHand(player.getHand());
	int dealerValue = calculateHand(dealerHand);

	if (isBlackJack(player.getHand())) {
		return player.getName() + " Wins! with a BlackJack! ";
	}
	else if (isBust(player.getHand())) {
		return player.getName() + " Loses with a Bust!";
	}

	if (isBlackJack(dealerHand)) {
		return "Dealer wins with a BlackJack! ";
	}
	else if (isBust(dealerHand)) {
		return player.getName() + " Wins! Dealer Busts!";
	}

	if (playerValue > dealerValue) {
		return player.getName() + " Wins!";
	}
	else if (dealerValue > playerValue) {
		return "Dealer beats " + player.getName() + "!";
	}
	
	else {
		return player.getName() + " pushed!";
	}

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

void Game::dealerTurn(const Player& player1, const Player& player2) {

	if (calculateHand(dealerHand) >= 17) {
		cout << "Dealer stays" << endl;
	}

	else {
		while (calculateHand(dealerHand) <= 17) {
			cout << "Dealer hits" << endl;
			dealerHand.push_back(deck.dealCard());
			for (const auto& card : dealerHand) {
				cout << card.toString() << ", ";
			}
			cout << "\n";
		}

	}
}


Card Game::hit(Player& player) {
	Card card = deck.dealCard();
	player.addCard(card);
	return card;
}