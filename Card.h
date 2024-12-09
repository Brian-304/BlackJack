#ifndef CARD_H
#define CARD_H
#include <string>
using namespace std;

class Card {
private:
	string rank;
	string suit;

public:
	Card(const string& r, const string& s);

	string getRank() const;

	string getSuit() const;

	string toString() const;
};

#endif
