#!/bin/bash
# Double-click or run: ./run.sh   (from Terminal in this folder)
cd "$(dirname "$0")"
echo "Building..."
g++ -std=c++17 -Wall -o Hangman MAIN.cpp HangmanGame.cpp WordBank.cpp ScoreBoard.cpp 2>&1
if [ $? -ne 0 ]; then
  echo "Build FAILED. Read errors above."
  exit 1
fi
echo "Running Hangman..."
./Hangman
