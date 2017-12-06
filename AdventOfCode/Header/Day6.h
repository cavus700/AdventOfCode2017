#pragma once
#include "AoCDay.h"

class Day6 : public AoCDay
{
public:
	Day6();
	~Day6();

	void startA(vector<string> input);
	void startB(vector<string> input);
};

class MemoryManager {
public:
    MemoryManager(vector<int> banks);

    void cycle();
    string getHash() const {
        string s = "";
        for (int i : m_banks)
            s += to_string(i) + ",";
        return s;
    }
    int getCycles() { return m_runs; }

    bool operator==(const MemoryManager &other) const
    {
        return (this->getHash() == other.getHash());
    }
    

private:
    vector<int> m_banks;
    int m_runs;
};


namespace std {
    template <>
    struct std::hash<MemoryManager>
    {
        std::size_t operator()(const MemoryManager& s) const
        {
            using std::size_t;
            using std::hash;
            using std::string;
            return hash<string>()(s.getHash());
        }
    };
}

