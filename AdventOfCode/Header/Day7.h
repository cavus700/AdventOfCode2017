#pragma once
#include "AoCDay.h"

class Day7 : public AoCDay
{
public:
	Day7();
	~Day7();

	void startA(vector<string> input);
	void startB(vector<string> input);

private:
    int getWeight(string program, unordered_map<string, vector<string>>& holdingProgram, unordered_map<string, int>& programWeights);
};

