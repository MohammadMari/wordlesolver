#pragma once
#include <vector>
#include <string>
#include <iostream>
#include "wordList.h"

using namespace std;
// guess words, process of elimination

class charPos // used to store letter and position in word
{
public:
	charPos(int index, char letter)
	{
		this->index = index;
		this->letter = letter;
	}
	char letter;
	int index;
};

class guessWord
{
public:
	// give user word to guess
	void guess(wordList& list); 
				  
	// remove all words that are no longer possible
	// based off user input
	void filterList(wordList& list);



private:
	vector<charPos> yellow; // correct letter wrong pos
	vector<charPos> green; // correct letter and pos
	vector<charPos> grey; // wrong
};