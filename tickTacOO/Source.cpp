#include <string>
#include <iostream>
#include <vector>
#include "Sorce.h"
#include "clearScreen.h"



Game::Game(vector<Player> newPlayers)
	:players(newPlayers) {}

string Game::getPlayerName(int number) {
	return players[number].getName();
}

int Game::getPlayerNumber() {
	return current;
}

void Game::clearBoard() {
	for (int i = 0; i < 9; i++) {
		board[i] = " ";
	}
}

string Game::showScore()
{
	int playerOneScore = players[0].getScore();
	int playerTwoScore = players[1].getScore();
	string scoreBoard = "";

	scoreBoard += "Player One: " + to_string(playerOneScore) + "\n";
	scoreBoard += "Player Two: " + to_string(playerTwoScore) + "\n";

	return scoreBoard;
}

void Game::welcome() {
	cout << "\t\t==============================================" << endl;
	cout << "\t\t\tWelcome to Tick Tack Toe!" << endl;
	cout << "\t\t==============================================" << endl;
	std::cout << "\t\t\t          |     |      \n";
	std::cout << "\t\t\t       1  |  2  |  3   \n";
	std::cout << "\t\t\t     _____|_____|_____ \n";
	std::cout << "\t\t\t          |     |      \n";
	std::cout << "\t\t\t       4  |  5  |  6   \n";
	std::cout << "\t\t\t     _____|_____|_____ \n";
	std::cout << "\t\t\t          |     |      \n";
	std::cout << "\t\t\t       7  |  8  |  9   \n";
	std::cout << "\t\t\t          |     |      \n\n";
	cout << "\t\t-------This is a game where two players-------" << endl;
	cout << "\t\t-----Compete againts each other to place------" << endl;
	cout << "\t\t--thier marker on a board with nine squares.--" << endl;
	cout << "\t\tFirst to get three in a row, either in a straight" << endl;
	cout << "\t\t--------line or a diagonal line wins!---------" << endl;
	cout << "\n\t\t------------Press enter to start------------" << endl;

	cin.ignore();

}

bool Game::isWinner() {
	bool result = false;

	//horizontal Line Check
	if ((board[0] == board[1]) && (board[1] == board[2]) && board[0] != " ")result = true;
	else if ((board[3] == board[4]) && (board[3] == board[5]) && board[3] != " ")result = true;
	else if ((board[6] == board[7]) && (board[8] == board[6]) && board[6] != " ")result = true;

	//Vertical Line Check
	else if ((board[0] == board[3]) && (board[6] == board[0]) && board[0] != " ")result = true;
	else if ((board[1] == board[4]) && (board[7] == board[1]) && board[1] != " ")result = true;
	else if ((board[2] == board[5]) && (board[8] == board[2]) && board[2] != " ")result = true;

	//Diagonal Line Check
	else if ((board[0] == board[4]) && (board[8] == board[0]) && board[0] != " ")result = true;
	else if ((board[2] == board[4]) && (board[6] == board[2]) && board[2] != " ")result = true;

	return result;
}

bool Game::isFilled() {
	bool result = true;

	for (int i = 0; i < 9; i++) {
		if (board[i] == " ")result = false;
	}

	return result;
}

void Game::getInput() {
	cout << "\tPlayer " << current << " please enter a number between 1 - 9: ";

	while (!(cin >> position)) {
		cout << "\tPlease enter a number between 1 and 9! ";
		cin.clear();
		cin.ignore();
	}

	while (board[position - 1] != " ") {
		cout << "\tOpps it looks like there is already something in that position!" << endl;
		cout << "\tPlease enter a number between 1 - 9: ";
		cin >> position;
		cout << "\n";
	}
	if (turn == 0) {
		clearScreen();
	}
	else {
		turn += 1;
	}
}

void Game::updateBoard() {
	if (players[current-1].getPlayerNumber() == 1) {
		board[position - 1] = "X";
	}
	else {
		board[position - 1] = "O";
	}
}

void Game::changePlayer(int &i) {
	if (i == 1) {
		i = 2;
	}
	else{
		i = 1;
	}
}

void Game::draw() {
	clearScreen();
	cout << "\t\t==============================================" << endl;
	cout << "\t\t\tWelcome to Tick Tack Toe!" << endl;
	cout << "\t\t==============================================" << endl;
	cout << "\t\t\t          |     |      \n";
	cout << "\t\t\t       " << board[0] << "  |  " << board[1] << "  |  " << board[2] << "\n";
	cout << "\t\t\t     _____|_____|_____ \n";
	cout << "\t\t\t          |     |      \n";
	cout << "\t\t\t       " << board[3] << "  |  " << board[4] << "  |  " << board[5] << "\n";
	cout << "\t\t\t     _____|_____|_____ \n";
	cout << "\t\t\t          |     |      \n";
	cout << "\t\t\t       " << board[6] << "  |  " << board[7] << "  |  " << board[8] << "\n";
	cout << "\t\t\t          |     |      \n";
	cout << "\t\t\t     \n";
}

void Game::play() {
	
	while (!isWinner() && !isFilled()) {

		getInput();
		updateBoard();
		draw();
		if (!isWinner() && !isFilled()) {
			changePlayer(current);
		}
	}
	
	end();
	clearBoard();

}

bool Game::end() {

	bool winner = true;

	if (isFilled()) {
		cout << "\t\tWow it was a tie!\n";
	}

	else if (isWinner()) {

		clearScreen();

		int i = 1;
		cout << "\t\tPlayer " << current << " won that round!" << endl;
		players[current - 1].updateScore(i);
		cout << showScore();
	}

	return winner;
}