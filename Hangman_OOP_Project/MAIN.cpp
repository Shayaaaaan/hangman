#include "HangmanGame.h"

#include <iostream>

using namespace std;

int main()
{
	cout << "=================================\n";
	cout << "   GameHub — Hangman\n";
	cout << "=================================\n";

	HangmanGame hangman;
	hangman.play();

	cout << "\nThanks for playing!\n";
	return 0;
}
