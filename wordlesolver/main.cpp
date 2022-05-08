#include <iostream>
#include <string>
#include "guessWord.h"
#include "wordStrength.h"

using namespace std;

int main()
{
	wordList list;

	list.readFile();
	list.sort();

	guessWord guess;
	
	for (int i = 0; i < 7; i++)
	{
		guess.guess(list);
		guess.filterList(list);
	}

	return 0;
}