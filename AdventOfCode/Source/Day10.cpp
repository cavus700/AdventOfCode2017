#include "stdafx.h"
#include "Day10.h"

Day10::Day10() {

}

Day10::~Day10()
{
}

void Day10::swap(int pos, int len, vector<int>& list) {
    int tmp;

    for (int i = 0; i < len / 2; i++) {
        tmp = list[(i + pos) % list.size()];
        list[(i + pos) % list.size()] = list[(pos + len - 1 - i) % list.size()];
        list[(pos + len - 1 - i) % list.size()] = tmp;
    }
}

void Day10::startA(vector<string> input)
{
    istringstream iss{ input[0] };
    vector<int> lengths;
    string s;
    while (getline(iss, s, ',')) {
        lengths.push_back(stoi(s));
    }
    
    int skip = 0;
    int pos = 0;
    vector<int> list(256);
    iota(list.begin(), list.end(), 0);

    for (int len : lengths) {
        if (len > list.size())
            continue;
        swap(pos, len, list);
        
        pos = (pos + len + skip++) % list.size();
    }

    cout << "Result: " << list[0] * list[1] << endl;
}

void Day10::startB(vector<string> input)
{
    vector<int> lengths;

    for (char c : input[0])
        lengths.push_back(c);

    lengths.push_back(17);
    lengths.push_back(31);
    lengths.push_back(73);
    lengths.push_back(47);
    lengths.push_back(23);

    int skip = 0;
    int pos = 0;

    vector<int> list(256);
    iota(list.begin(), list.end(), 0);

    for (int round = 0; round < 64; round++) {
        for (int len : lengths) {
            if (len > list.size())
                continue;
            swap(pos, len, list);

            pos = (pos + len + skip++) % list.size();
        }
    }

    vector<unsigned char> denseHash;
    unsigned char tmpByte = static_cast<unsigned char>(list[0]);

    for (int i = 1; i < 256; i++) {
        if (i % 16 == 0) {
            denseHash.push_back(tmpByte);
            tmpByte = list[i];
            continue;
        }
        tmpByte = tmpByte ^ static_cast<unsigned char>(list[i]);
    }

    denseHash.push_back(tmpByte);

    cout << "Result: ";

    for (unsigned char c : denseHash)
        cout << setw(2) << setfill('0') << hex << (int)c;
    cout << endl;
}

vector<unsigned char> Day10::knotHash(string s)
{
    vector<int> lengths;

    for (char c : s)
        lengths.push_back(c);

    lengths.push_back(17);
    lengths.push_back(31);
    lengths.push_back(73);
    lengths.push_back(47);
    lengths.push_back(23);

    int skip = 0;
    int pos = 0;

    vector<int> list(256);
    iota(list.begin(), list.end(), 0);

    for (int round = 0; round < 64; round++) {
        for (int len : lengths) {
            if (len > list.size())
                continue;
            swap(pos, len, list);

            pos = (pos + len + skip++) % list.size();
        }
    }

    vector<unsigned char> denseHash;
    unsigned char tmpByte = static_cast<unsigned char>(list[0]);

    for (int i = 1; i < 256; i++) {
        if (i % 16 == 0) {
            denseHash.push_back(tmpByte);
            tmpByte = list[i];
            continue;
        }
        tmpByte = tmpByte ^ static_cast<unsigned char>(list[i]);
    }

    denseHash.push_back(tmpByte);
    return denseHash;
}
