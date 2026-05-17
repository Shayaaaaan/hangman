#include "ScoreBoard.h"

#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

ScoreBoard::ScoreBoard(const std::string& filePath, int maxEntries)
	: path(filePath), maxEntries(maxEntries)
{
}

void ScoreBoard::record(const std::string& playerName, int score)
{
	std::vector<std::pair<std::string, int>> entries;
	std::ifstream in(path);
	std::string name;
	int s = 0;
	while (in >> name >> s)
		entries.emplace_back(name, s);

	entries.emplace_back(playerName, score);
	std::sort(entries.begin(), entries.end(),
		[](const auto& a, const auto& b) { return a.second > b.second; });
	if (static_cast<int>(entries.size()) > maxEntries)
		entries.resize(maxEntries);

	std::ofstream out(path, std::ios::trunc);
	for (const auto& e : entries)
		out << e.first << " " << e.second << "\n";
}

void ScoreBoard::show() const
{
	std::ifstream in(path);
	if (!in)
	{
		std::cout << "  (no scores yet)\n";
		return;
	}

	std::string name;
	int score = 0;
	int rank = 1;
	while (in >> name >> score)
		std::cout << "  " << rank++ << ". " << name << " — " << score << "\n";

	if (rank == 1)
		std::cout << "  (no scores yet)\n";
}
