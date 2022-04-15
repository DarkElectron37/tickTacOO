#include <string>
#include <iostream>
#include <vector>
#include "Sorce.h"
#include "clearScreen.h"

using namespace std;

int main() {
	int numberOfGames = 1;



	string playerOneName, playerTwoName;
	cout << "Please Enter Player Ones Name: ";
	cin >> playerOneName;

	cout << "Please Enter Player Two's Name: ";
	cin >> playerTwoName;

	clearScreen();

	Player player1(1, playerOneName);
	Player player2(2, playerTwoName);

	vector<Player> players = {player1, player2};

	Game newGame(players);

	newGame.welcome();

	cout << "How many games do you want to play? ";
	cin >> numberOfGames;

	for (int i = 1; i <= numberOfGames; i++) {
		newGame.play();
	}

	

}