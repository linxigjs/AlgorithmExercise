//
// Created by gjs on 19-1-17.
//

#ifndef ALGORITHMEXERCISE_EDGEWEIGHTEDGRAPH_H
#define ALGORITHMEXERCISE_EDGEWEIGHTEDGRAPH_H

#include <vector>
#include <fstream>
#include <algorithm>
#include <memory>
#include "Edge.h"

class EdgeWeightedGraph {
public:
    EdgeWeightedGraph(int n) {
        V = n;
        E = 0;
        for(int i=0; i<V; i++) {
            vector<shared_ptr<Edge>> temp;
            adj.emplace_back(temp);
        }
    }

    EdgeWeightedGraph(string filepath) {
        ifstream infile;
        infile.open(filepath, ios::in);
        int v=0, w=0;
        double weight = 0.0;
        if(infile) {
            string s;
            getline(infile, s);
            V = stoi(s);
            for(int i=0; i<V; i++) {
                vector<shared_ptr<Edge>> temp;
                adj.emplace_back(temp);
            }
            getline(infile, s);
            while(getline(infile, s)) {
                ParseString(s, v, w, weight);
                AddEdge(make_shared<Edge>(v, w, weight));
            }
            infile.close();
        } else {
            cout << "Open file failed." << endl;
        }
        cout << "Graph build done." << endl;
    }

    int GetV() const {
        return V;
    }

    int GetE() const {
        return E;
    }

    vector<shared_ptr<Edge>> GetEdges() const {
        vector<shared_ptr<Edge>> res;
        for(int i=0; i<V; i++) {
            for(const auto &e : adj[i]) {
                if(e->GetOther(i) > i)
                    res.emplace_back(e);
            }
        }
        return res;
    }

private:
    int V=0, E=0;
    vector<vector<shared_ptr<Edge>>> adj;

    void AddEdge(shared_ptr<Edge> e) {
        int v = e->GetEither(), w = e->GetOther(v);
        adj[v].emplace_back(e);
        adj[w].emplace_back(e);
        E++;
    }

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
};

#endif //ALGORITHMEXERCISE_EDGEWEIGHTEDGRAPH_H
