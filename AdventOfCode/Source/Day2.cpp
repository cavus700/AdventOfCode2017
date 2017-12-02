#include "stdafx.h"
#include "Day2.h"
#include <iterator>

Day2::Day2()
{
}


Day2::~Day2()
{
}

void Day2::startA(vector<string> input)
{
    istream_iterator<int> eof;
    int max = numeric_limits<int>::min(); int min = numeric_limits<int>::max();

    int result = 0;

    for (string s : input) {
        istringstream istr(s);
        istream_iterator<int> iter(istr);
        vector<int> row(iter, eof);

        for (int num : row) {
            max = num > max ? num : max;
            min = num < min ? num : min;
        }
        result += max - min;

        max = numeric_limits<int>::min(); 
        min = numeric_limits<int>::max();
    }

    cout << "Checksum is: " << result << endl;
}

void Day2::startB(vector<string> input)
{
    istream_iterator<int> eof;

    int result = 0;
    bool found = false;

    for (string s : input) {
        istringstream istr(s);
        istream_iterator<int> iter(istr);
        vector<int> row(iter, eof);

        for (int i = 0; i < row.size() - 1; i++) {
            for (int j = i + 1; j < row.size(); j++) {
                if (row[i] % row[j] == 0) {
                    result += row[i] / row[j];
                    found = true;
                    break;
                }
                if (row[j] % row[i] == 0) {
                    result += row[j] / row[i];
                    found = true;
                    break;
                }
            }
            if (found) {
                found = false;
                break;
            }
        }
    }

    cout << "Checksum is: " << result << endl;
}
