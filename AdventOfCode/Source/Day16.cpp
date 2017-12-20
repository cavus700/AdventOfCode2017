#include "stdafx.h"
#include "Day16.h"


Day16::Day16()
{

}


Day16::~Day16()
{

}

void dance(vector<string>& moves, string& programs) {
    int posA, posB;
    char tmp;
    int size;

    for (string move : moves) {
        switch (move[0]) {
        case 's':
            size = stoi(move.substr(1, move.size()));
            programs = programs.substr(programs.size() - size) + programs.substr(0, programs.size() - size);
            break;
        case 'x':
            posA = stoi(move.substr(1, move.find('/')));
            posB = stoi(move.substr(move.find('/') + 1, move.size()));
            tmp = programs[posA];
            programs[posA] = programs[posB];
            programs[posB] = tmp;
            break;
        case 'p':
            posA = static_cast<int>(string(programs).find(move[1]));
            posB = static_cast<int>(string(programs).find(move[3]));
            tmp = programs[posA];
            programs[posA] = programs[posB];
            programs[posB] = tmp;
            break;
        default: throw runtime_error("Unknown dance move");
        }
    }
}

void Day16::startA(vector<string> input)
{
    istringstream iss{ input[0] };
    vector<string> moves;
    string s;
    while (getline(iss, s, ',')) {
        moves.push_back(s);
    }

    string programs("abcdefghijklmnop");

    dance(moves, programs);

    cout << "Result: " << programs << endl;
}

void Day16::startB(vector<string> input)
{
    istringstream iss{ input[0] };
    vector<string> moves;
    string s;
    while (getline(iss, s, ',')) {
        moves.push_back(s);
    }

    string programs("abcdefghijklmnop");

    unordered_map<string, int> mapMoves;
    dance(moves, programs);
    mapMoves[programs] = 0;

    for (int i = 1; i < 1000000000; i++) {
        
        dance(moves, programs);
       
        if (mapMoves[programs] == 0) {
            mapMoves[programs] = i;
        }
        else {
            int diff = i - mapMoves[programs];
            while (i < 1000000000)
                i += diff;

            i -= diff;
            i++;
            for (i; i < 1000000000; i++)
                dance(moves, programs);

            cout << "Result: " << programs << endl;
            return;
        }        
    }   
}
