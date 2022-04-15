#include <string>
#include <iostream>

using namespace std;

class Player {

private:
	int playerNumber;
	int playerScore;
	string playerName;

public:
	Player(int newPlayer, string newName, int newScore=0);
	string getName();
	int getScore();
	void updateScore(int newScore);
	int getPlayerNumber();
	~Player();

};
