#include "stdafx.h"
#include "Day7.h"


Day7::Day7()
{
}


Day7::~Day7()
{
}

void Day7::startA(vector<string> input)
{
    unordered_map<string, string> isHoldByAnOtherProgram;
    unordered_map<string, string> isHoldingPrograms;

    for (string s : input) {
        istringstream istr(s);
        istream_iterator<string> iter(istr);
        istream_iterator<string> eof;
        vector<string> program(iter, eof);

        if (program.size() == 2)
            continue;

        isHoldingPrograms[program[0]] = program[0];

        for (int i = 3; i < program.size(); i++) {
            if (i == program.size() - 1)
                isHoldByAnOtherProgram[program[i]] = program[i];
            else
                isHoldByAnOtherProgram[program[i].substr(0, program[i].size() - 1)] = program[i].substr(0, program[i].size() - 1);
        }
                
    }

    for (auto key : isHoldingPrograms) {
        if (isHoldByAnOtherProgram[key.first] == "") {
            cout << "Program " << key.first << " is root of tree" << endl;
            return;
        }

    }
}

void Day7::startB(vector<string> input)
{
    unordered_map<string, vector<string>> holdingPrograms;
    unordered_map<string, int> programWeights;

    for (string s : input) {
        istringstream istr(s);
        istream_iterator<string> iter(istr);
        istream_iterator<string> eof;
        vector<string> program(iter, eof);
                
        if (holdingPrograms[program[0]].size() != 0)
            return;
        programWeights[program[0]] = stoi(program[1].substr(1, program[1].size() - 1));

        for (int i = 3; i < program.size(); i++) {
            if (i == program.size() - 1)
                holdingPrograms[program[0]].push_back(program[i]);
             else
                 holdingPrograms[program[0]].push_back(program[i].substr(0,program[i].size()-1));
        }
    }


    cout << "All programs with unbalanced programs. Selected the one, which is the deepest, in the tree, beginning from the root." << endl;

    for (auto program : holdingPrograms) {
        if (program.second.size() <= 1)
            continue;

        vector<int> holding;
        vector<int> ownWeight;

        for (auto holdProg : program.second) {
            ownWeight.push_back(programWeights[holdProg]);
            holding.push_back(getWeight(holdProg, holdingPrograms, programWeights));
        }

        auto result = minmax_element(holding.begin(), holding.end());

        if (*result.first != *result.second) {
            cout << "Balance values are (own weight, holding): ";
            for (int v = 0; v < holding.size(); v++)
                cout << "(" << ownWeight[v] << "," << holding[v] << ")" << ", ";
            cout << endl;
        }
    }

}

int Day7::getWeight(string program, unordered_map<string, vector<string>>& holdingProgram, unordered_map<string, int>& programWeights) {
    int weight = programWeights[program];

    if (holdingProgram[program].size() == 0)
        return weight;

    for (auto prog : holdingProgram[program])
        weight += getWeight(prog, holdingProgram, programWeights);

    return weight;
}
