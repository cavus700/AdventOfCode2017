#include "stdafx.h"
#include "day6.h"


Day6::Day6()
{
}


Day6::~Day6()
{
}

void Day6::startA(vector<string> input)
{
    istringstream istr(input[0]);
    istream_iterator<int> iter(istr);
    istream_iterator<int> eof;
    vector<int> banks(iter, eof);
    MemoryManager mgr(banks);
    unordered_map<MemoryManager, string> map;

    map[mgr] = mgr.getHash();

    while (true) {
        mgr.cycle();

        if (map[mgr] == mgr.getHash()) {
            break;
        }
        else {
            map[mgr] = mgr.getHash();
        }
    }

    cout << "Result: " << mgr.getCycles() << endl;
}

void Day6::startB(vector<string> input)
{
	
}

MemoryManager::MemoryManager(vector<int> banks)
{
    m_runs = 0;
    m_banks = banks;
}

void MemoryManager::cycle()
{
    auto maxIter = max_element(m_banks.begin(), m_banks.end());
    int num = *maxIter;
    *maxIter = 0;

    while (num > 0) {
        maxIter++;

        if (maxIter == m_banks.end())
            maxIter = m_banks.begin();
        
        *maxIter = *maxIter + 1;
        num--;
    }

    m_runs++;
}
