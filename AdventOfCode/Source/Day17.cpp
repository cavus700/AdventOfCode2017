#include "stdafx.h"
#include "Day17.h"


Day17::Day17()
{

}


Day17::~Day17()
{

}

void Day17::startA(vector<string> input)
{
    int steps = stoi(input[0]);

    vector<int> buffer;
    buffer.push_back(0);

    int pos = 0;

    for (int step = 1; step <= 2017; step++) {
        pos = (pos + steps) % buffer.size();
        buffer.insert(buffer.begin() + ++pos, step);
    }

    cout << "Result: " << buffer.at(pos + 1) << endl;
}

void Day17::startB(vector<string> input)
{
    int steps = stoi(input[0]);
    
    int pos = 0;
    int inserted = 1;

    int valOnPosOne;

    for (int step = 1; step <= 50000000; step++) {
        pos = (pos + steps) % inserted;
        if (++pos == 1)
            valOnPosOne = step;
        inserted++;
    }

    cout << "Result: " << valOnPosOne << endl;
}
