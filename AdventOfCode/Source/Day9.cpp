#include "stdafx.h"
#include "Day9.h"

#define c(i) input[0][i]

Day9::Day9()
{
}


Day9::~Day9()
{
}

void Day9::startA(vector<string> input)
{
    int score = 0;
    int result = 0;
    bool isGarbage = false;

    for (int i = 0; i < input[0].size(); i++) {
        if (c(i) == '!'){
            i += 1;
        }
        else if (c(i) == '{') {
            if (!isGarbage)
                score += 1;
        }
        else if (c(i) == '}') {
            if(!isGarbage)
                result += score--;
        }
        else if (c(i) == '<') {
            isGarbage = true;
        }
        else if (c(i) == '>') {
            isGarbage = false;
        }
        else {

        }
    }

    cout << "Result: " << result << endl;
}

void Day9::startB(vector<string> input)
{
    int canceled = 0;
    bool isGarbage = false;

    for (int i = 0; i < input[0].size(); i++) {
        if (c(i) == '!') {
            i += 1;
        }
        else if (c(i) == '<') {
            if (isGarbage)
                canceled++;
            else
                isGarbage = true;
        }
        else if (c(i) == '>') {
            isGarbage = false;
        }
        else {
            if (isGarbage)
                canceled++;
        }
    }

    cout << "Result: " << canceled << endl;
}
