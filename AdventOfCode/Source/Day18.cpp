#include "stdafx.h"
#include "Day18.h"


Day18::Day18()
{

}


Day18::~Day18()
{

}

bool execute(string& instr, unordered_map<char, long long>& registers, int& numInstr) {
    string action = instr.substr(0, 3);

    if (action == "snd") {
        cout << " " << registers[instr[4]];
    }
    else if (action == "set") {
        try {
            registers[instr[4]] = stoi(instr.substr(6, instr.size()));
        }
        catch (invalid_argument) {
            registers[instr[4]] = registers[instr[6]];
        }
    }
    else if (action == "add") {
        try {
            registers[instr[4]] += stoi(instr.substr(6, instr.size()));
        }
        catch (invalid_argument) {
            registers[instr[4]] += registers[instr[6]];
        }
    }
    else if (action == "mul") {
        try {
            registers[instr[4]] *= stoi(instr.substr(6, instr.size()));
        }
        catch (invalid_argument) {
            registers[instr[4]] *= registers[instr[6]];
        }
    }
    else if (action == "mod") {
        try {
            registers[instr[4]] %= stoi(instr.substr(6, instr.size()));
        }
        catch (invalid_argument) {
            registers[instr[4]] %= registers[instr[6]];
        }
    }
    else if (action == "rcv") {
        if (registers[instr[4]] != 0)
            return true;
    }
    else if (action == "jgz") {
        bool activated = false;
        try {
            if (stoi(string(instr[4] + "")) > 0)
                activated = true;
        }
        catch (invalid_argument) {
            if (registers[instr[4]] > 0) 
                activated = true;
        }
        
        if (!activated) return false;

        long long offset;
        try {
            offset = stoi(instr.substr(6, instr.size()));
        }
        catch (invalid_argument) {
            offset  = registers[instr[6]];
        }
        numInstr += static_cast<int>(offset) - 1;
    }
    else
        throw runtime_error("Unknown instruction");

    return false;
}

void Day18::startA(vector<string> input)
{
    unordered_map<char, long long> registers;

    cout << "Result: ";

    for (int instr = 0; instr < input.size(); instr++) {
        if (execute(input[instr], registers, instr)) break;
    }
    cout << endl;
}

void Day18::startB(vector<string> input)
{
    Program* prog0 = nullptr;
    Program* prog1 = new Program(1, &prog0);
    prog0 = new Program(0, &prog1);

    int instrA = 0, instrB = 0;
    
    while (true) {
        while (!prog0->execute(input[instrA], instrA)) {
            instrA++;
            if (instrA >= input.size())
                throw runtime_error("Illegal instruction");
        }
        while (!prog1->execute(input[instrB], instrB)) {
            instrB++;
            if (instrB >= input.size())
                throw runtime_error("Illegal instruction");
        }

        if (prog0->execute(input[instrA], instrA)) {
            if (prog1->execute(input[instrB], instrB)) {
                cout << "Result: " << prog1->send() << endl;
                return;
            }
            else {
                instrB++;
            }
        }
        else {
            instrA++;
        }
    }
}
