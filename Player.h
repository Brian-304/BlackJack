#include <iostream>

using namespace std;
class Player
{
private:
    string name;
public:
    Player(const string& playerName) : name(playerName) {}

    string getName() const {
        return name;
    }

};