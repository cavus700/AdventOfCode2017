#include "stdafx.h"
#include "Day13.h"


Day13::Day13()
{

}


Day13::~Day13()
{

}

void Day13::startA(vector<string> input)
{
    Firewall firewall;

    for (auto line : input) {
        istringstream istr(line);
        istream_iterator<string> iter(istr);
        istream_iterator<string> eof;
        vector<string> program(iter, eof);
    
        firewall.addLayer(stoi(program[0].substr(0, program[0].size())), stoi(program[1]));

    }

    int severity = 0;

    do{
        severity += firewall.getSeverityOfCurrentPos();
        firewall.iterate();
        firewall.moveForward();
    } while (!firewall.isFinished());

    cout << "Result: " << severity << endl;
}

void Day13::startB(vector<string> input)
{
    Firewall firewall;

    for (auto line : input) {
        istringstream istr(line);
        istream_iterator<string> iter(istr);
        istream_iterator<string> eof;
        vector<string> program(iter, eof);

        firewall.addLayer(stoi(program[0].substr(0, program[0].size())), stoi(program[1]));

    }

    int delay = 1;
    bool escaped = true;
    int layer = 0;

    firewall.save(0);

    for (delay;; delay++) {
        firewall.resetPosition();
        firewall.load(delay - 1);
        firewall.iterate();
        firewall.save(delay);

        do {
            if (firewall.gotCaught()){
                layer = 0;
                escaped = false;
                break;
            }
            firewall.iterate();
            layer++;
            firewall.moveForward();
        } while (!firewall.isFinished());
        if (escaped)
            break;
        else
            escaped = true;
    }

    cout << "Result: " << delay << endl;
    return;
}
