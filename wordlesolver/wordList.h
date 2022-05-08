
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

	string best()
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


	
	int size()
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

	string front()
	{
		if (words)
			return words->word; // return first word
		return "";
	}

	void push_back(string str)
	{
		if (!words)
			words = new wordNode(str);
		wordNode* child = words;

		while (child->next)
			child = child->next;

		child->next = new wordNode(str);
	}

	string at(int i)
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
};