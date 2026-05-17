HANGMAN — 
========================================

Author: Shayaan
Folder: Hangman_OOP_Project (all submission files are here)

FILES IN THIS FOLDER
--------------------
MAIN.cpp          Entry point (main function) — run this file
Game.h            Course base class
HangmanGame.h/cpp Your game (inherits Game, overrides play())
WordBank.h/cpp    Loads words from words.txt (composition)
ScoreBoard.h/cpp  Top-5 scores in hangman_scores.txt (composition + file I/O)
words.txt         Word list — one word per line (submit with project)
readme.txt        This file

BUILD & RUN
-----------
Open terminal in THIS folder (Hangman_OOP_Project), then:

  g++ -std=c++17 -Wall -o Hangman MAIN.cpp HangmanGame.cpp WordBank.cpp ScoreBoard.cpp
  ./Hangman

Windows: use Hangman.exe instead of ./Hangman

HOW TO PLAY
-----------
- A random word is chosen from words.txt (you do not see it).
- Type one letter at a time.
- You have 6 wrong guesses before you lose.
- Win: guess every letter. Score = word length x 10.
- Optional: save your score to hangman_scores.txt.

