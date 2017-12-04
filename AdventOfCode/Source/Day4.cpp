#include "stdafx.h"
#include "Day4.h"


Day4::Day4()
{
}


Day4::~Day4()
{
}

void Day4::startA(vector<string> input)
{
    istream_iterator<string> eof;

    int result = 0;
    bool valid = true;

    for (string s : input) {
        istringstream istr(s);
        istream_iterator<string> iter(istr);
        vector<string> passphrase(iter, eof);
        std::unordered_map<std::string, std::string> map;
        string mapVal;
        
        for (string word : passphrase) {
            if (map[word] != "") {
                valid = false;
                break;
            }
            map[word] = word;
        }

        if (valid)
            result++;

        valid = true;
    }

    cout << "Result: " << result << endl;

}

bool isEqual(string first, string second) {
    size_t pos;
    for (char c : first) {
        pos = second.find_first_of(c);
        if (pos != string::npos) {
            second = second.substr(0, pos) + second.substr(pos + 1, second.size());
        }
    }
    return second.size() == 0 ? true : false;
}

void Day4::startB(vector<string> input)
{
    istream_iterator<string> eof;
    bool valid = true;
    int result = 0;

    for (string s : input) {
        istringstream istr(s);
        istream_iterator<string> iter(istr);
        vector<string> passphrase(iter, eof);

        for (int i = 0; i < passphrase.size() - 1; i++) {
            for (int j = i + 1; j < passphrase.size(); j++) {
                if (passphrase[i].size() == passphrase[j].size() && isEqual(passphrase[i], passphrase[j])) {
                    valid = false;
                    break;
                }
            }
            if (!valid)
                break;
        }

        if (valid)
            result++;
        valid = true;
    }

    cout << "Result: " << result << endl;
}
