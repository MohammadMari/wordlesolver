#include "wordList.h"
#include <iostream>
#include <algorithm>

void wordList::remove(int i)
{
	if (i > 0)
	{
		int cnt = 0;
		wordNode* node = words;

		while ((cnt < (i - 1)) && node->next)
		{
			node = node->next;
			cnt++;
		}

		wordNode* remove = node->next;
		node->next = remove->next;

		free(remove);
	}
	else
	{
		wordNode* remove = words;
		words = words->next;

		free(remove);
	}
	
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
		if (word.size() < 5)
			continue;
		push_back(word);
	}
}


string wordList::best()
{
	wordNode* node = words;

	if (!node)
		return "";

	wordNode* bestPtr = nullptr;
	float bestAmt = INT_MIN;

	while (node->next)
	{
		if (node->wordStr.strength > bestAmt)
		{
			bestAmt = node->wordStr.strength;
			bestPtr = node;
		}

		node = node->next;
	}

	return bestPtr->word;
}



int wordList::size()
{
	if (!words)
		return 0;

	int cnt = 1;

	wordNode* child = words;

	while (child->next)
	{
		child = child->next;
		cnt++;
	}

	return cnt;
}

string wordList::front()
{
	if (words)
		return words->word; // return first word
	return "";
}

void wordList::push_back(string str)
{
	if (!words)
		words = new wordNode(str);
	wordNode* child = words;

	while (child->next)
		child = child->next;

	child->next = new wordNode(str);
}

string wordList::at(int i)
{
	int cnt = 0;
	wordNode* ret = words;

	while ((cnt < i) && ret->next)
	{
		ret = ret->next;
		cnt++;
	}

	return ret->word;
}