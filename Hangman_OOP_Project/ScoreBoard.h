#pragma once

#include <string>

// Top scores saved to a text file (file I/O for individual marks).
class ScoreBoard
{
public:
	explicit ScoreBoard(const std::string& filePath, int maxEntries = 5);

	void record(const std::string& playerName, int score);
	void show() const;

private:
	std::string path;
	int maxEntries;
};
