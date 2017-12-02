#include "stdafx.h"
#include "Day2.h"
#include <iterator>
#include <algorithm>

Day2::Day2()
{
}


Day2::~Day2()
{
}

void Day2::startA(vector<string> input)
{
    istream_iterator<int> eof;

    int result = 0;

    for (string s : input) {
        istringstream istr(s);
        istream_iterator<int> iter(istr);
        vector<int> row(iter, eof);

        auto minmax = minmax_element(row.begin(), row.end());
        result += *minmax.second - *minmax.first;
    }

    cout << "Checksum is: " << result << endl;
}

void Day2::startB(vector<string> input)
{
    int result = 0;
    bool found = false;

    auto lambda = [&](string s) {
        istream_iterator<int> eof;
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
    };

    for_each(input.begin(), input.end(), lambda);

    cout << "Checksum is: " << result << endl;
}
