#include "stdafx.h"
#include "Day1.h"


Day1::Day1()
{
}


Day1::~Day1()
{
}

void Day1::startA(vector<string> input)
{
    string str = input[0];
    vector<int> numbers;

    for (char c : str) {
        numbers.push_back(c - '0');
    }

    if (numbers[0] == numbers[numbers.size() - 1]) {
        numbers.push_back(numbers[0]);
    }

    int result = 0;
    int last = -1;

    for (int num : numbers) {
        if (num != last) {
            last = num;
        }
        else {
            result += num;
        }
    }

    cout << "Result: " << result << endl;
}

void Day1::startB(vector<string> input)
{
    string str = input[0];
    vector<int> numbers;

    for (char c : str) {
        numbers.push_back(c - '0');
    }

    size_t half = numbers.size() / 2;

    int result = 0;

    for (int i = 0; i < numbers.size(); i++) {
        if (numbers[i] == numbers[(i + half) % numbers.size()])
            result += numbers[i];
    }
    
    cout << "Result: " << result << endl;
}