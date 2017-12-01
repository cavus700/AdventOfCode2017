// AdventOfCode.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <Day1.h>
#include "Day2.h"
#include "Day3.h"
#include "Day4.h"
#include "Day5.h"
#include "Day6.h"
#include "Day7.h"
#include "Day8.h"
#include "Day9.h"
#include "Day10.h"
#include "Day11.h"
#include "Day12.h"
#include "Day13.h"
#include "Day14.h"
#include "Day15.h"
#include "Day16.h"
#include "Day17.h"
#include "Day18.h"
#include "Day19.h"
#include "Day20.h"
#include "Day21.h"
#include "Day22.h"
#include "Day23.h"
#include "Day24.h"
#include "Day25.h"

#define INPUT_TEXT_PRE "../input/day"
#define INPUT_TEXT_SUFF ".txt"

using namespace std;
using namespace chrono;

int main(int argc, char** argv)
{
    int day = -1;
    bool gotDay = false;

    if (argc >= 2) {
        try {
            day = stoi(argv[1]);
            gotDay = true;
        }
        catch (invalid_argument) {
            cerr << "Argument was not a number (1-25)" << endl;
        }
        catch (out_of_range) {
            cerr << "Number was out of range (1-25)" << endl;
        }
    }
    

    cout << "Please enter a valid number for the day you want to execute (1-25): ";
    do {
        cin >> day;
        if (!cin.fail() && (day >= 0 && day <= 25))
            gotDay = true;
        else {
            cout << "Please enter a valid number for the day you want to execute (1-25): ";
            cin.clear();
            cin.ignore(std::numeric_limits<int>::max(), '\n');
        }
    } while (!gotDay);
    
    vector<string> input;
	string tmpIn;
	ifstream reader(INPUT_TEXT_PRE + to_string(day) + INPUT_TEXT_SUFF);
	time_point<high_resolution_clock> start, end;

    if (!reader.is_open()) {
        cerr << "Could not open file: " << INPUT_TEXT_PRE << to_string(day) << INPUT_TEXT_SUFF << endl;
        return -1;
    }

	while (getline(reader, tmpIn))
		input.push_back(tmpIn);

	reader.close();

    AoCDay* aocday;

    switch (day) {
    case 1: aocday = new Day1(); break;
    case 2: aocday = new Day2(); break;
    case 3: aocday = new Day3(); break;
    case 4: aocday = new Day4(); break;
    case 5: aocday = new Day5(); break;
    case 6: aocday = new Day6(); break;
    case 7: aocday = new Day7(); break;
    case 8: aocday = new Day8(); break;
    case 9: aocday = new Day9(); break;
    case 10: aocday = new Day10(); break;
    case 11: aocday = new Day11(); break;
    case 12: aocday = new Day12(); break;
    case 13: aocday = new Day13(); break;
    case 14: aocday = new Day14(); break;
    case 15: aocday = new Day15(); break;
    case 16: aocday = new Day16(); break;
    case 17: aocday = new Day17(); break;
    case 18: aocday = new Day18(); break;
    case 19: aocday = new Day19(); break;
    case 20: aocday = new Day20(); break;
    case 21: aocday = new Day21(); break;
    case 22: aocday = new Day22(); break;
    case 23: aocday = new Day23(); break;
    case 24: aocday = new Day24(); break;
    case 25: aocday = new Day25(); break;
    }
	
	start = chrono::high_resolution_clock::now();
	aocday->startA(input);
	end = chrono::high_resolution_clock::now();
	duration<float> secs = end - start;
	cout << "Part A lasted " << secs.count() << " seconds or " << duration_cast<milliseconds>(secs).count() << " milliseconds." << endl << endl;

	start = chrono::high_resolution_clock::now();
	aocday->startB(input);
	end = chrono::high_resolution_clock::now();
	secs = end - start;
	cout << "Part B lasted " << secs.count() << " seconds or " << duration_cast<milliseconds>(secs).count() << " milliseconds." << endl << endl;
	
    delete aocday;

	system("pause");
	return 0;
}

