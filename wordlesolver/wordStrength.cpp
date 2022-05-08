#include "wordStrength.h"

// Returns something along the lines of how common a letter appears in words.
// The more words we can get rid of, the faster we can guess the word.
float letterStrength(char letter)
{
	letter = (char)toupper(letter);
	if (letter == 'E')
	{
		return 11.1607;
	}

	if (letter == 'A')
	{
		return 8.4966;
	}

	if (letter == 'R')
	{
		return 7.5809;
	}

	if (letter == 'I')
	{
		return 7.5448;
	}

	if (letter == 'O')
	{
		return 7.1635;
	}

	if (letter == 'T')
	{
		return 6.9509;
	}

	if (letter == 'N')
	{
		return 6.6544;
	}

	if (letter == 'S')
	{
		return 5.7351;
	}

	if (letter == 'L')
	{
		return 5.4893;
	}

	if (letter == 'C')
	{
		return 4.5388;
	}

	if (letter == 'U')
	{
		return 3.6308;
	}

	if (letter == 'D')
	{
		return 3.3844;
	}

	if (letter == 'P')
	{
		return 3.1671;
	}

	if (letter == 'M')
	{
		return 3.0129;
	}

	if (letter == 'H')
	{
		return 3.0034;
	}

	if (letter == 'G')
	{
		return 2.4705;
	}

	if (letter == 'B')
	{
		return 2.0720;
	}

	if (letter == 'F')
	{
		return 1.8121;
	}

	if (letter == 'Y')
	{
		return 1.7779;
	}

	if (letter == 'W')
	{
		return 1.2899;
	}

	if (letter == 'K')
	{
		return 1.1016;
	}

	if (letter == 'V')
	{
		return 1.2899;
	}

	if (letter == 'X')
	{
		return 0.2902;
	}

	if (letter == 'Z')
	{
		return 0.2722;
	}

	if (letter == 'J')
	{
		return 0.1965;
	}

	if (letter == 'Q')
	{
		return 0.1962;
	}
}

void wordStrength::calcWordStrength(string word)
{
	strength = 0;

	for (int i = 0; i < word.size(); i++)
	{
		strength += letterStrength(word.at(i));
		for (int j = 0; j < word.size(); j++)
		{
			if (i == j)
			{
				continue;
			}

			if (word.at(i) == word.at(j))
			{
				strength -= letterStrength(word.at(i)) * 2;
			}
		}
	}
}
