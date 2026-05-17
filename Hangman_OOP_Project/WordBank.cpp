#include "WordBank.h"

#include <fstream>
#include <iostream>
#include <random>
#include <stdexcept>

WordBank::WordBank(const std::string& filePath)
{
	std::ifstream in(filePath);
	if (!in)
	{
		std::cerr << "WordBank: could not open " << filePath << "\n";
		return;
	}

	std::string word;
	while (in >> word)
		words.push_back(word);
}

bool WordBank::empty() const
{
	return words.empty();
}

int WordBank::size() const
{
	return static_cast<int>(words.size());
}

std::string WordBank::randomWord() const
{
	if (words.empty())
		return "";

	static std::mt19937 rng{std::random_device{}()};
	std::uniform_int_distribution<size_t> pick(0, words.size() - 1);
	return words[pick(rng)];
}
