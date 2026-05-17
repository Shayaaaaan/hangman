#pragma once

#include "Game.h"
#include "ScoreBoard.h"
#include "WordBank.h"

#include <string>

class HangmanGame : public Game
{
public:
	HangmanGame();

	void play() override;

private:
	WordBank bank;
	ScoreBoard leaderboard;

	std::string toLower(std::string s) const;
	std::string maskedWord(const std::string& secret, const std::string& guessed) const;
	bool alreadyGuessed(char letter, const std::string& guessed) const;
	bool playerWon(const std::string& secret, const std::string& guessed) const;
};
