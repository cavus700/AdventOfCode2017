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

void Day3::startB(vector<string> input)
{
	
}
