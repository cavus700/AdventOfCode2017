#include "stdafx.h"
#include "Day14.h"
#include "Day10.h"

Day14::Day14()
{

}


Day14::~Day14()
{

}

void Day14::startA(vector<string> input)
{
    Day10 day10;
    vector<vector<unsigned char>> hashes;

    for (int i = 0; i < 128; i++) {
        hashes.push_back(day10.knotHash(input[0] + "-" + to_string(i)));
    }

    int used = 0;

    for (auto hash : hashes) {
        for (unsigned char byte : hash) {
            bitset<8> bits(byte);
            for (int i = 0; i < 8; i++) {
                if (bits[i] == 1)
                    used++;
            }
        }
    }

    cout << "Result: " << used << endl;
}

void markRegion(int i, int j, vector<bitset<128>>& bitField) {
    if (bitField[i][j] != 1)
        return;

    bitField[i][j] = 0;

    //Left
    if (j > 0) {
        markRegion(i, j - 1, bitField);
    }
    //Up
    if (i > 0) {
        markRegion(i - 1, j, bitField);
    }
    //Right
    if (j < 127) {
        markRegion(i, j + 1, bitField);
    }
    //down
    if (i < 127) {
        markRegion(i + 1, j, bitField);
    }
}

void Day14::startB(vector<string> input)
{
    vector<bitset<128>> bitField(128);
    vector<vector<unsigned char>> hashes;
    Day10 day10;

    for (int i = 0; i < 128; i++) {
        hashes.push_back(day10.knotHash(input[0] + "-" + to_string(i)));
    }
    
    int i = 0, j = 0;

    for (auto hash : hashes) {
        for (unsigned char byte : hash) {
            bitset<8> bits(byte);
            for (int bit = 7; bit >= 0; bit--) {
                bitField[i][j] = bits[bit];
                j++;
            }
        }        
        i++; j = 0;
    }

    int regions = 0;
    
    for (int row = 0; row < 128; row++) {
        for (int bit = 0; bit < 128; bit++) {
            if (bitField[row][bit] == 1) {
                regions++;
                markRegion(row, bit, bitField);
            }
        }
    }

    cout << "Result: " << regions << endl;
}
