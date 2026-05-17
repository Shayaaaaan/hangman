#pragma once

#include <string>
#include <vector>

// Composition helper: Hangman "has-a" WordBank (not "is-a").
// Loads words from a text file — one word per line.
class WordBank
{
public:
	explicit WordBank(const std::string& filePath);

	bool empty() const;
	std::string randomWord() const;
	int size() const;

private:
	std::vector<std::string> words;
};
