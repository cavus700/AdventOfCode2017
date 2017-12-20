#pragma once
#include "AoCDay.h"

class Day18 : public AoCDay
{
public:
	Day18();
	~Day18();

	void startA(vector<string> input);
	void startB(vector<string> input);
};

class Program {
private:
    unordered_map<char, long long> registers;
    vector<long long> queue;
    Program** prog;
    int sendValues;
     
public:
    Program(int id, Program** p) { registers['p'] = id; prog = p; sendValues = 0; }

    void push(long long val) { queue.push_back(val); }

    int send() { return sendValues; }

    bool execute(string& instr, int& numInstr) {
        string action = instr.substr(0, 3);

        if (action == "snd") {
            (*prog)->push(registers[instr[4]]);
            sendValues++;
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
            if (queue.empty()) {
                return true;
            }

            registers[instr[4]] = queue.front();
            queue.erase(queue.begin());

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
                offset = registers[instr[6]];
            }

            numInstr += static_cast<int>(offset) - 1;
        }
        else
            throw runtime_error("Unknown instruction");

        return false;
    }
};