#include "stdafx.h"
#include "Day11.h"


Day11::Day11()
{

}


Day11::~Day11()
{

}

void Day11::startA(vector<string> input)
{
    std::string delimiter = ",";

    int pos1 = 0, pos2 = 0;
    size_t pos = 0;
    std::string token;
    while ((pos = input[0].find(delimiter)) != std::string::npos) {
        token = input[0].substr(0, pos);
        if (token == "n"){ pos2--; }
        else if (token == "ne") { if (pos1 % 2 == 0) pos2--;  pos1++; }
        else if (token == "se") { if (pos1 % 2 == 1) pos2++;  pos1++; }
        else if (token == "s") { pos2++; }
        else if (token == "sw") { if (pos1 % 2 == 1) pos2++;  pos1--; }
        else if (token == "nw") { if (pos1 % 2 == 0) pos2--;  pos1--; }
        input[0].erase(0, pos + delimiter.length());
    }

    if (input[0] == "n") { pos2--; }
    else if (input[0] == "ne") { if (pos1 % 2 == 0) pos2--;  pos1++; }
    else if (input[0] == "se") { if (pos1 % 2 == 1) pos2++;  pos1++; }
    else if (input[0] == "s") { pos2++; }
    else if (input[0] == "sw") { if (pos1 % 2 == 1) pos2++;  pos1--; }
    else if (input[0] == "nw") { if (pos1 % 2 == 0) pos2--;  pos1--; }

    int distance = 0;

    while (pos1 < 0) {
        distance++;
        if ((-pos1) % 2 == 1)
            pos2++;
        pos1++;
    }

    distance += 2 * (-pos2) + 1;
    cout << "Result: " << distance << endl;
}

void Day11::startB(vector<string> input)
{

}
