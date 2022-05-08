#pragma once
#include <string>
#include <vector>
#include "wordStrength.h"

using namespace std;

class wordNode
{
public:
	wordNode(string word)
	{
		wordStr = wordStrength(word);
		this->word = word;
	}
	wordStrength wordStr;
	string word;

	//wordNode* next = nullptr; // if you choose to make a linked list you will need this.
};


class wordList // a class for wordList
{
public:
	// wordNode* head = nullptr; // if you choose to make a linked list you will need this.
	vector<wordNode> words; // if you choose to make a linked list, you will not need this.

	void remove(string word); // or maybe an index
	void add(string word);
	void sort(); // sorts by highest to lowest word strength
};
