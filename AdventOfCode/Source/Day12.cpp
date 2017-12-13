#include "stdafx.h"
#include "Day12.h"


Day12::Day12()
{

}


Day12::~Day12()
{

}

void mark(vector<string>& program, vector<vector<string>>& programs, unordered_map<string, bool>& connections, int& count) {
    if (connections[program[0]]) {
        return;
    }
    connections[program[0]] = true;
    count++;
    for (int i = 2; i < program.size(); i++) {
        mark(programs[stoi(program[i])], programs, connections, count);
    }
    return;
}

void mark(vector<string>& program, vector<vector<string>>& programs, unordered_map<string, bool>& connections) {
    if (connections[program[0]]) {
        return;
    }
    connections[program[0]] = true;
    for (int i = 2; i < program.size(); i++) {
        mark(programs[stoi(program[i])], programs, connections);
    }
    return;
}

void Day12::startA(vector<string> input)
{
    int programsConnected = 0;

    unordered_map<string, bool> connections;
    vector<vector<string>> programs;

    for (auto line : input) {
        istringstream istr(line);
        istream_iterator<string> iter(istr);
        istream_iterator<string> eof;
        vector<string> program(iter, eof);
        
        for (int i = 2; i < program.size() - 1; i++)
            program[i] = program[i].substr(0, program[i].size() - 1);

        connections[program[0]] = false;

        programs.push_back(program);
    }
    
    mark(programs[0],programs, connections, programsConnected);

    cout << "Result: " << programsConnected << endl;
}

void Day12::startB(vector<string> input)
{
    int groups = 0;

    unordered_map<string, bool> connections;
    vector<vector<string>> programs;

    for (auto line : input) {
        istringstream istr(line);
        istream_iterator<string> iter(istr);
        istream_iterator<string> eof;
        vector<string> program(iter, eof);

        for (int i = 2; i < program.size() - 1; i++)
            program[i] = program[i].substr(0, program[i].size() - 1);

        connections[program[0]] = false;

        programs.push_back(program);
    }

    for (auto prog : programs) {
        if (!connections[prog[0]])
            groups++;
        mark(prog, programs, connections);
    }

    cout << "Result: " << groups << endl;
}
