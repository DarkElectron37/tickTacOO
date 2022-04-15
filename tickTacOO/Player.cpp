#include <string>
#include <iostream>
#include "Player.h"

using namespace std;

Player::Player(int newPlayer, string newName, int newScore)
	:playerNumber(newPlayer), playerName(newName), playerScore(newScore) {}

string Player::getName() {
	return playerName;
}

int Player::getScore() {
	return playerScore;
}

int Player::getPlayerNumber() {
	return playerNumber;
}

void Player::updateScore(int newScore) {
	playerScore += newScore;
}

Player::~Player() {
	playerScore = 0;
}