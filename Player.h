#include <iostream>

using namespace std;

<<<<<<< Updated upstream
class Player
{
private:
    string name;
public:
    Player(const string& playerName) : name(playerName) {}

    string getName() const {
        return name;
    }
=======
class Player {
private:
	string name;

public:
	Player(const string& player1) : name(player1) {}

	string getName() const {
		return name;
	}
>>>>>>> Stashed changes
};