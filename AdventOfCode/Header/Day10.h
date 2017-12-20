#pragma once
#include "AoCDay.h"

class Day10 : public AoCDay
{
public:
    Day10();
    ~Day10();

    void startA(vector<string> input);
    void startB(vector<string> input);

    //For Day14
    vector<unsigned char> knotHash(string s);

private:
    void swap(int pos, int len, vector<int>& list);
};

