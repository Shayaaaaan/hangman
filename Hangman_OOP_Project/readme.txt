HANGMAN — Individual OOP Game (CSC-213)
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

OOP FOR VIVA
------------
Inheritance:   HangmanGame : public Game
Override:      void play()
Composition:   WordBank bank, ScoreBoard leaderboard
Encapsulation: private helper methods in HangmanGame
File I/O:      words.txt in, hangman_scores.txt out
Polymorphism:  (later in full GameHub) vector<unique_ptr<Game>> and Game*->play()

AI DISCLOSURE
-------------
Tools used: Cursor. I reviewed and can explain all code in this project.

GITHUB (deadline 16 May)
------------------------
Upload this folder's .h, .cpp, words.txt, and readme.txt to your GitHub.
Share the link on Classroom so classmates can integrate your game.
