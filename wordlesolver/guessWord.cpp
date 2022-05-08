#include "guessWord.h"


void guessWord::guess(wordList& list)
{
	if (!list.words.size())
		return; // shouldn't happen but uhhh.

	string wordToGuess = list.words.front().word; // sorted by strength, best word should be first
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
		}
	}

	// if we get the same letter twice, one grey and one a different color, this will give us issues.
	// code below makes sure any letters that are green/yellow aren't put in the grey pile

	vector<char> allLetters; // push all yellow and green letters in vector
	for (auto let : green)
		allLetters.push_back(let.letter);

	for (auto let : yellow)
		allLetters.push_back(let.letter);

	// loop through word, if those letters aren't in it, put it in grey pile.
	for (int i = 0; i < wordToGuess.size(); i++)
	{
		bool found = false;

		for (char letter : allLetters)
		{
			if (wordToGuess.at(i) == letter)
				found = true;
		}

		if (!found)
			grey.push_back(charPos(i, wordToGuess.at(i)));
	}
}


void guessWord::filterList(wordList& list)
{
	cout << "Filtering..." << endl;

	// easiest check, we check to see if the word has the green letter in that specific index.
	// if it doesn't we remove it.
	for (auto letter : green)
	{
		for (int i = 0; i < list.words.size(); i++)
		{
			string word = list.words.at(i).word;
			if (word.at(letter.index) != letter.letter)
			{
				list.remove(i);
				i--; // we decrement i to account for removing the word. This will shift everything back one.
			}
		}
	}

	for (auto letter : yellow)
	{
		// remove all words with that letter in that pos
		for (int i = 0; i < list.words.size(); i++)
		{
			string word = list.words.at(i).word;
			if (word.at(letter.index) == letter.letter) // is there the yellow letter in this pos? get rid of it
			{
				list.remove(i);
				i--;
				continue;
			}

			bool found = false;

			// is the yellow letter not in the word at all? get rid of it
			for (int j = 0; j < word.size(); j++)
			{
				if (word.at(j) == letter.letter)
				{
					found = true;
					break;
				}
			}


			if (!found)
			{
				list.remove(i);
				i--;
			}
		}
	}

	// is the letter in the word? remove it 
	for (auto letter : grey)
	{
		for (int i = 0; i < list.words.size(); i++)
		{
			string word = list.words.at(i).word;

			for (int j = 0; j < word.size(); j++)
			{
				if (letter.letter == word.at(j))
				{
					list.remove(i);
					i--;
				}
			}

		}
	}

	// we don't really need to clear it, but it will make future runs faster c:
	green.clear();
	yellow.clear();
	grey.clear();
}