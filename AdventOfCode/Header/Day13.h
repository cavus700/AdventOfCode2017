#pragma once
#include "AoCDay.h"

class Day13 : public AoCDay
{
public:
	Day13();
	~Day13();

	void startA(vector<string> a_input);
	void startB(vector<string> a_input);
};

class Firewall {
    typedef pair<vector<bool>, bool> layer;
public:
    Firewall() : m_position(0), m_firewall(new unordered_map<int, pair<vector<bool>, bool>>()) {};

    void addLayer(int num, int depth) {
        (*m_firewall)[num] = layer(vector<bool>(depth), false);
        if (depth > 0)
            (*m_firewall)[num].first[0] = true;

        if (num > m_numLayer)
            m_numLayer = num;
    }

    void moveForward() {
        m_position++;
    }

    bool isFinished() {
        return m_position > m_numLayer;
    }

    int getSeverityOfCurrentPos() {
        if ((*m_firewall)[m_position].first.size() > 0 && (*m_firewall)[m_position].first[0])
            return m_position * static_cast<int>((*m_firewall)[m_position].first.size());
        return 0;
    }

    bool gotCaught() {
        if ((*m_firewall)[m_position].first.size() > 0 && (*m_firewall)[m_position].first[0])
            return true;
        return false;
    }

    void iterate() {
        for (auto& layer : (*m_firewall)) {
            for (int pos = 0; pos < layer.second.first.size(); pos++) {
                if (layer.second.first[pos]) {
                    layer.second.first[pos] = false;

                    //Reached end
                    if (pos == layer.second.first.size() - 1) {
                        layer.second.second = true;
                        layer.second.first[pos - 1] = true;
                    }
                    //Reached begining and came from end
                    else if (pos == 0 && layer.second.second) {
                        layer.second.second = false;
                        layer.second.first[1] = true;
                    }
                    else {
                        //Moves backward
                        if(layer.second.second)
                            layer.second.first[pos - 1] = true;
                        else
                            layer.second.first[pos + 1] = true;
                    }
                    break;
                }
            }
        }
    }

    void reset(){
        m_position = 0;
        for (auto& layer : (*m_firewall)) {
            for (int pos = 0; pos < layer.second.first.size(); pos++) {
                layer.second.first[pos] = false;
            }
            if(layer.second.first.size() > 0)
                layer.second.first[0] = true;
            layer.second.second = false;
        }
    }

    void resetPosition() { m_position = 0; }

    void save(int iteration) {
        m_last = new unordered_map<int, pair<vector<bool>, bool>>(*m_firewall);
    }

    void load(int iteration) {
        delete m_firewall;
        m_firewall = m_last;
    }

private:
    int m_position;
    int m_numLayer;
    unordered_map<int, pair<vector<bool>,bool>> *m_firewall;
    unordered_map<int, pair<vector<bool>, bool>>* m_last;
};

