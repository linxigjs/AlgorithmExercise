//
// Created by gjs on 19-1-29.
//

#ifndef ALGORITHMEXERCISE_EDGEWEIGHTEDDIGRAPH_H
#define ALGORITHMEXERCISE_EDGEWEIGHTEDDIGRAPH_H

#include "DirectedEdge.h"
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <memory>

using namespace std;

class EdgeWeightedDigraph {
public:
    EdgeWeightedDigraph(string filepath) {
        ifstream infile;
        infile.open(filepath, ios::in);
        int v=0, w=0;
        double weight = 0.0;
        if(infile) {
            string s;
            getline(infile, s);
            V = stoi(s);
            for(int i=0; i<V; i++) {
                vector<shared_ptr<DirectedEdge>> temp;
                adj.emplace_back(temp);
            }
            getline(infile, s);
            while(getline(infile, s)) {
                ParseString(s, v, w, weight);
                AddEdge(v, w, weight);
            }
            infile.close();
        } else {
            cout << "Open file failed." << endl;
        }
        cout << "Graph build done." << endl;
    }

    int GetV() {
        return V;
    }

    int GetE() {
        return E;
    }

private:
    int ParseString(string str, int &v, int &w, double &weight) {
        string nospace = RemovePreAndLastSpace(str);
        auto begin = nospace.find(' ');
        if(begin == nospace.npos) {
            return stoi(nospace);
        }
        v = stoi(nospace.substr(0, begin));
        auto end = nospace.rfind(' ');
        weight = stod(nospace.substr(end+1, str.size()));
        w = stoi(nospace.substr(begin, end-1));
        return 0;
    }

    string RemovePreAndLastSpace(const string& str) {
        int length = str.size();
        int i = 0,j = length -1;
        // vc的isspace实现> 256就崩溃
        while(i < length && isspace(str[i] & 0xFF)){i++;}
        while(j >= 0 && isspace(str[j] & 0xFF)){j--;}
        if(j<i) return string();
        return str.substr(i,j-i+1);
    }

    void AddEdge(int v, int w, double weight) {
        adj[v].emplace_back(make_shared<DirectedEdge>(v, w, weight));
        E++;
    }

    vector<vector<shared_ptr<DirectedEdge>>> adj;
    int V = 0, E = 0;
};

#endif //ALGORITHMEXERCISE_EDGEWEIGHTEDDIGRAPH_H
