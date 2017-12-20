#include "stdafx.h"
#include "Day15.h"

#define GEN_A_VAL 16807L
#define GEN_B_VAL 48271L
#define GEN_DIVIDE 2147483647L

Day15::Day15()
{

}


Day15::~Day15()
{

}

void Day15::startA(vector<string> input)
{
    long long gen_a = stoll(input[0]);
    long long gen_b = stoll(input[1]);
    long judgeCount = 0L;
    bool isEqual = true;

    for (long i = 0; i < 40000000L; i++) {
        gen_a = (gen_a * GEN_A_VAL) % GEN_DIVIDE;
        gen_b = (gen_b * GEN_B_VAL) % GEN_DIVIDE;

        bitset<sizeof(long) * 8> bitsetA(gen_a);
        bitset<sizeof(long) * 8> bitsetB(gen_b);

        for (int bit = 0; bit < 16; bit++) {
            if (bitsetA[bit] != bitsetB[bit]) {
                isEqual = false;
                break;
            }
        }

        if (isEqual)
            judgeCount++;
        isEqual = true;
    }

    cout << "Result: " << judgeCount << endl;
}

void Day15::startB(vector<string> input)
{
    long long gen_a = stoll(input[0]);
    long long gen_b = stoll(input[1]);
    long judgeCount = 0L;
    bool isEqual = true;

    vector<bitset<sizeof(long) * 8>> valA;
    vector<bitset<sizeof(long) * 8>> valB;

    for (long i = 0; i < 40000000L; i++) {
        gen_a = (gen_a * GEN_A_VAL) % GEN_DIVIDE;
        gen_b = (gen_b * GEN_B_VAL) % GEN_DIVIDE;

        if(gen_a % 4 == 0)
            valA.push_back(bitset<sizeof(long) * 8>(gen_a));
        if(gen_b % 8 == 0)
            valB.push_back(bitset<sizeof(long) * 8>(gen_b));
    }

    vector<bitset<sizeof(long) * 8>>::iterator aIter, bIter;

    for (aIter = valA.begin(), bIter = valB.begin(); aIter != valA.end() && bIter != valB.end(); ++aIter, ++bIter)
    {
        for (int bit = 0; bit < 16; bit++) {
            if ((*aIter)[bit] != (*bIter)[bit]) {
                isEqual = false;
                break;
            }
        }

        if (isEqual)
            judgeCount++;
        isEqual = true;
    }

    cout << "Result: " << judgeCount << endl;
}
