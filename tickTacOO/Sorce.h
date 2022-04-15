#include <string>
#include <iostream>
#include <vector>
#include "Player.h"

using namespace std;

class Game {
private:
	vector<Player> players;
	string board[9] = { " "," "," "," "," "," " ," "," "," " };
	int position = 0;
	int turn = 0;
	int current = 1;

public:
	Game(vector<Player> newPlayers);
	string getPlayerName(int number);
	string showScore();
	bool isWinner();
	bool isFilled();
	bool end();
	int getPlayerNumber();
	void welcome();
	void getInput();
	void updateBoard();
	void changePlayer(int &i);
	void draw();
	void play();
	void clearBoard();
	
};