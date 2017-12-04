#include "stdafx.h"
#include "Day3.h"


Day3::Day3()
{
}


Day3::~Day3()
{
}

void Day3::startA(vector<string> input)
{
	int number = stoi(input[0]);
	int ring = 1;
	int elements = 9;
	int elementsOnRing = 8;

	while (elements < number) {
		ring++;
		elementsOnRing += 8;
		elements += elementsOnRing;
	}

	int indexOnRing = elementsOnRing - (elements - number);

	int quarterOfRing = elementsOnRing / 4;

	int indexInQuarter = indexOnRing % quarterOfRing;

	int distanceToMiddleOfQuarter = (indexInQuarter)-(quarterOfRing) / 2;
	if (distanceToMiddleOfQuarter < 0)
		distanceToMiddleOfQuarter *= -1;

	cout << "Steps to port: " << distanceToMiddleOfQuarter + ring << endl;
}

typedef vector<vector<int>> field;

bool compute(int i, int j, field* arr, int &find) {
	if ((*arr)[i][j] != 0)
		return false;

	int cummulative = 0;

	cummulative += (*arr)[i-1][j+1];
	cummulative += (*arr)[i][j+1];
	cummulative += (*arr)[i+1][j+1];
	cummulative += (*arr)[i+1][j];
	cummulative += (*arr)[i+1][j-1];
	cummulative += (*arr)[i][j-1];
	cummulative += (*arr)[i-1][j-1];
	cummulative += (*arr)[i-1][j];

    (*arr)[i][j] = cummulative;
    
	if (cummulative > find) {
		cout << "Result: " << cummulative << endl;
		return true;
	}
	return false;
}

void Day3::startB(vector<string> input)
{
	int number = stoi(input[0]);
	int size = sqrt(number);
	field* arr = new vector<vector<int>>(size, vector<int>(size, 0));

	int mid = size / 2 + 1;
	(*arr)[mid][mid] = 1;
	int layer = 1;
    int startOffset = 0;

	while (true) {
		for (int i = mid + startOffset; i >= mid - layer; i--) {
			if (compute(i, mid + layer, arr, number))
				return;
		}
		for (int j = mid + layer; j >= mid - layer; j--) {
			if (compute(mid - layer, j, arr, number))
				return;
		}
		for (int i = mid - layer; i <= mid + layer; i++) {
			if (compute(i, mid - layer, arr, number))
				return;
		}
		for (int j = mid - layer; j <= mid + layer; j++) {
			if (compute(mid + layer, j, arr, number))
				return;
		}
		for (int i = mid + layer; i > mid + startOffset; i--) {
			if (compute(i, mid + layer, arr, number))
				return;
		}
		layer++;
        startOffset++;
	}
	
}
