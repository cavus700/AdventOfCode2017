#include "stdafx.h"
#include "Day5.h"


Day5::Day5()
{
}


Day5::~Day5()
{
}

void Day5::startA(vector<string> input)
{
    vector<int> maze;

    for (string s : input) {
        maze.push_back(stoi(s));
    }

    int pos = 0;
    int steps = 0;
    int offset = 0;

    while (pos >= 0 && pos < maze.size()) {
        offset = maze[pos];
        maze[pos]++;
        pos += offset;
        steps++;
    }

    cout << "Result: " << steps << endl;
}

void Day5::startB(vector<string> input)
{
    vector<int> maze;

    for (string s : input) {
        maze.push_back(stoi(s));
    }

    int pos = 0;
    int steps = 0;
    int offset = 0;

    while (pos >= 0 && pos < maze.size()) {
        offset = maze[pos];
        if (offset >= 3)
            maze[pos]--;
        else
            maze[pos]++;
        pos += offset;
        steps++;
    }

    cout << "Result: " << steps << endl;
}
