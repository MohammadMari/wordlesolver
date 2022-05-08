#include "wordList.h"
#include <iostream>
#include <algorithm>

void wordList::remove(int i)
{
	int size = words.size();
	if (size <= (i)) // whyyyy, I have no clue why but this breaks things sometimes.
	{
		cout << "pls fix" << endl;
		return;
	}

	words.erase(words.begin() + i);
}

struct great
{
	bool operator()(wordNode const& a, wordNode const& b) const { return a.wordStr.strength > b.wordStr.strength; }
};

// sort words by their strength
void wordList::sort()
{
	std::sort(words.begin(), words.end(), great());
}

// read the text file, put it in vector.
void wordList::readFile()
{
	ifstream file;
	file.open("5letterwords.txt");
	if (!file.is_open()) return;

	string word;
	while (file >> word)
	{
		words.push_back(word);
	}
}

