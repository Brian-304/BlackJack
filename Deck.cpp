#include "Deck.h"
#include <algorithm>
#include <ctime>
#include <cstdlib>

Deck::Deck() {
	string ranks[] = { "Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King" };
	string suits[] = { "Hearts", "Diamonds", "Clubs", "Spades" };

	for (const auto& suit : suits) {
		for (const auto& rank : ranks) {
			cards.push_back(Card(rank, suit));
		}
	}
}

void Deck::shuffle() {
	srand(time(0));
	random_shuffle(cards.begin(), cards.end());
}

Card Deck::dealCard() {
	Card card = cards.back();
	cards.pop_back();
	return card;
}