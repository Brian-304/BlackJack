#include "Player.h"
#include <iostream>

using namespace std;

Player::Player(const string& playerName) : name(playerName) {}
    


vector<Card> Player::getHand() const {
    return hand;
}

string Player::getName() const {
    return name;
}

void Player::addCard(const Card& card) {
    hand.push_back(card);
}

void Player::displayHand() const {
    cout << name << "'s hand: ";
    for (const auto& card : hand) {
        cout << card.toString() << ", ";
    }
    cout << "\n";
}

void Player::clearHand() {
    hand.clear();
}