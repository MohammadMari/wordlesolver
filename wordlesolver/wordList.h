
#pragma once
#include <string>
#include <vector>
#include "fstream"
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

	wordNode* next = nullptr; // if you choose to make a linked list you will need this.
};


class wordList // a class for wordList
{
public:
	wordNode* words = nullptr;
	void remove(int i); // or maybe an index
	void readFile();

	string best();
	int size();
	string front();
	void push_back(string str);
	string at(int i);
};