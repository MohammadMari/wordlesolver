#include "guessWord.h"


void guessWord::guess(wordList& list)
{
	string wordToGuess = list.words.front().word;
	cout << "Guess: " << wordToGuess << endl;

	cout << "Enter G for green, Y for Yellow or W for wrong" << endl;
	for (int i = 0; i < wordToGuess.size(); i++)
	{
		char input;
		cout << "Letter #" << i << " (" << wordToGuess.at(i) << "): ";
		cin >> input;

		switch (toupper(input))
		{
		case 'G': green.push_back(charPos(i, wordToGuess.at(i))); break;
		case 'Y': yellow.push_back(charPos(i, wordToGuess.at(i))); break;
		default: grey.push_back(charPos(i, wordToGuess.at(i))); break;
		}
	}
}


void guessWord::filterList(wordList& list)
{
	for (int i = 0; i < list.words.size(); i++)
	{
		string word = list.words.at(i).word;
		bool out = false;

		for (int j = 0; j < word.size(); j++)
		{

			for (auto letter : grey)
			{
				if (letter.letter == word.at(j))
				{
					list.remove(word);
					out = true;
					break;
				}
			}
		}

		if (out)
		{
			i--;
			continue;
		}

		for (auto letter : yellow)
		{
			if (word.at(letter.index) == letter.letter)
			{
				list.remove(word);
				out = true;
				break;
			}
		}

		if (out)
		{
			i--;
			continue;
		}

		for (auto letter : green)
		{
			if (word.at(letter.index) != letter.letter)
			{
				list.remove(word);
				out = true;
				break;
			}
		}

		if (out)
		{
			i--;
			continue;
		}
	}
}