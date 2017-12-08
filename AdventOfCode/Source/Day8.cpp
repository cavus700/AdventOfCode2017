#include "stdafx.h"
#include "Day8.h"


Day8::Day8()
{
}


Day8::~Day8()
{
}

void Day8::startA(vector<string> input)
{
    unordered_map<string, int> registers;
    string reg;
    bool cond;
    pair<string, int> maxReg("", numeric_limits<int>::min());

    for (string s : input) {
        istringstream stream(s);
        istream_iterator<string> line(stream);
        istream_iterator<string> eof;
        vector<string> action(line, eof);

        reg = action[0];

        if (action[5] == "<") {
            cond = registers[action[4]] < stoi(action[6]);
        }
        else if (action[5] == ">") {
            cond = registers[action[4]] > stoi(action[6]);
        }
        else if (action[5] == "<=") {
            cond = registers[action[4]] <= stoi(action[6]);
        }
        else if (action[5] == ">=") {
            cond = registers[action[4]] >= stoi(action[6]);
        }
        else if (action[5] == "==") {
            cond = registers[action[4]] == stoi(action[6]);
        }
        else if (action[5] == "!=") {
            cond = registers[action[4]] != stoi(action[6]);
        }
        else
            throw runtime_error("unrecognized condition");

        if (cond) {
            if (action[1] == "inc") {
                registers[reg] += stoi(action[2]);
            }
            else if (action[1] == "dec") {
                registers[reg] -= stoi(action[2]);
            }
            else
                throw runtime_error("unrecognized action");

            if(reg == maxReg.first && registers[reg] < maxReg.second){
                maxReg = pair<string,int>("", numeric_limits<int>::min());
                for (auto key : registers) {
                    maxReg = key.second > maxReg.second ? key : maxReg;
                }
            }
            else {
                maxReg = registers[reg] > maxReg.second ? pair<string, int>(reg, registers[reg]) : maxReg;
            }
        }
    }
    cout << "Register " << maxReg.first << " has greatest value " << maxReg.second << endl;
}

void Day8::startB(vector<string> input)
{	
    unordered_map<string, int> registers;
    string reg;
    bool cond;
    pair<string, int> maxReg("", numeric_limits<int>::min());

    for (string s : input) {
        istringstream stream(s);
        istream_iterator<string> line(stream);
        istream_iterator<string> eof;
        vector<string> action(line, eof);

        reg = action[0];

        if (action[5] == "<") {
            cond = registers[action[4]] < stoi(action[6]);
        }
        else if (action[5] == ">") {
            cond = registers[action[4]] > stoi(action[6]);
        }
        else if (action[5] == "<=") {
            cond = registers[action[4]] <= stoi(action[6]);
        }
        else if (action[5] == ">=") {
            cond = registers[action[4]] >= stoi(action[6]);
        }
        else if (action[5] == "==") {
            cond = registers[action[4]] == stoi(action[6]);
        }
        else if (action[5] == "!=") {
            cond = registers[action[4]] != stoi(action[6]);
        }
        else
            throw runtime_error("unrecognized condition");

        if (cond) {
            if (action[1] == "inc") {
                registers[reg] += stoi(action[2]);
            }
            else if (action[1] == "dec") {
                registers[reg] -= stoi(action[2]);
            }
            else
                throw runtime_error("unrecognized action");

            maxReg = registers[reg] > maxReg.second ? pair<string, int>(reg, registers[reg]) : maxReg;            
        }
    }
    cout << "Register " << maxReg.first << " has greatest value " << maxReg.second << endl;
}
