#include "HangmanGame.h"

#include <algorithm>
#include <cctype>
#include <iostream>

using namespace std;

HangmanGame::HangmanGame()
	: Game("Hangman"),
	  bank("words.txt"),
	  leaderboard("hangman_scores.txt")
{
}

string HangmanGame::toLower(string s) const
{
	for (char& c : s)
		c = static_cast<char>(tolower(static_cast<unsigned char>(c)));
	return s;
}

string HangmanGame::maskedWord(const string& secret, const string& guessed) const
{
	string display;
	for (char c : secret)
	{
		if (guessed.find(c) != string::npos)
			display += c;
		else
			display += '_';
		display += ' ';
	}
	return display;
}

bool HangmanGame::alreadyGuessed(char letter, const string& guessed) const
{
	return guessed.find(letter) != string::npos;
}

bool HangmanGame::playerWon(const string& secret, const string& guessed) const
{
	for (char c : secret)
	{
		if (guessed.find(c) == string::npos)
			return false;
	}
	return true;
}

void HangmanGame::play()
{
	cout << "\n========================================\n";
	cout << "              HANGMAN\n";
	cout << "========================================\n";

	if (bank.empty())
	{
		cout << "Could not load words. Make sure words.txt is in this folder.\n";
		return;
	}

	const int maxWrong = 6;
	string secret = toLower(bank.randomWord());
	string guessed;
	int wrong = 0;

	cout << "Guess the hidden word (" << secret.size() << " letters).\n";
	cout << "You can make " << maxWrong << " wrong guesses.\n\n";

	while (wrong < maxWrong)
	{
		cout << "Word:  " << maskedWord(secret, guessed) << "\n";
		cout << "Wrong: " << wrong << " / " << maxWrong;
		if (!guessed.empty())
			cout << "  |  Used: " << guessed;
		cout << "\n\nGuess a letter: ";

		char input = '\0';
		if (!(cin >> input))
		{
			cin.clear();
			cin.ignore(10000, '\n');
			cout << "Invalid input. Try again.\n\n";
			continue;
		}

		char letter = static_cast<char>(tolower(static_cast<unsigned char>(input)));
		if (!isalpha(static_cast<unsigned char>(letter)))
		{
			cout << "Please enter a letter (a-z).\n\n";
			continue;
		}
		if (alreadyGuessed(letter, guessed))
		{
			cout << "You already guessed '" << letter << "'.\n\n";
			continue;
		}

		guessed += letter;

		if (secret.find(letter) == string::npos)
		{
			++wrong;
			cout << "Sorry, '" << letter << "' is not in the word.\n\n";
		}
		else
		{
			cout << "Good! '" << letter << "' is in the word.\n\n";
		}

		if (playerWon(secret, guessed))
		{
			int score = static_cast<int>(secret.size()) * 10;
			cout << "You won! The word was: " << secret << "\n";
			cout << "Score: " << score << " points\n\n";

			cout << "Save score to leaderboard? (y/n): ";
			char save = 'n';
			cin >> save;
			if (save == 'y' || save == 'Y')
			{
				string name;
				cout << "Enter your name: ";
				cin >> name;
				leaderboard.record(name, score);
			}

			cout << "\n--- Hangman Leaderboard ---\n";
			leaderboard.show();
			return;
		}
	}

	cout << "Game over! The word was: " << secret << "\n\n";
	cout << "--- Hangman Leaderboard ---\n";
	leaderboard.show();
}
