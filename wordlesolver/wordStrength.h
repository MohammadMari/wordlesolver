#pragma once
#include <string>

using namespace std;

class wordStrength
{
public:
	wordStrength() {};
	wordStrength(string word)
	{
		this->word = word;
		calcWordStrength();
	}
	void calcWordStrength();
	string word;
	float strength = 0;

};


// sort words by strength (best to guess first)
