#include "Card.h"

using namespace std;

Card::Card(const string& r, const string& s) {
	rank = r;
	suit = s;

}

string Card::getRank() const {
	return rank;
}

string Card::getSuit() const {
	return suit;
}

string Card::toString() const {
	return rank + " of " + suit;
}