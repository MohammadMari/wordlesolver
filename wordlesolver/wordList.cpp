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
