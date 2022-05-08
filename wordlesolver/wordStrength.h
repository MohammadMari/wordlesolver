#pragma once
#include <string>

using namespace std;

class wordStrength
{
public:
	wordStrength() {};
	wordStrength(string word)
	{
		calcWordStrength(word);
	}
	void calcWordStrength(string word);
	float strength = 0;
};


// sort words by strength (best to guess first)
