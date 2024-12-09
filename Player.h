#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include "Card.h"

using namespace std;

class Player
{
private:
    string name;
    vector<Card> hand;
public:
    Player(const string& player1Name);
    string getName() const;
    vector<Card> getHand() const;
    void addCard(const Card& card);
    void displayHand() const;
    void clearHand();

};

#endif