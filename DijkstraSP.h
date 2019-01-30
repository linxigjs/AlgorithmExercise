//
// Created by gjs on 19-1-29.
//

#ifndef ALGORITHMEXERCISE_DijkstraSP_H
#define ALGORITHMEXERCISE_DijkstraSP_H

#include <cfloat>
#include <algorithm>
#include <queue>
#include <map>
#include "EdgeWeightedDigraph.h"

using namespace std;

class EdgeComp {
public:
    bool operator()(pair<int, double> l, pair<int, double> r) {
        return l.second > r.second;
    }
};

class DijkstraSP {
public:
    DijkstraSP(EdgeWeightedDigraph G, int s) {
        distto.assign(G.GetV(), DBL_MAX);
        edgeto.assign(G.GetV(), shared_ptr<DirectedEdge>());
        distto[s] = 0.0;
        pq.emplace(make_pair(s, 0.0));
        while(!pq.empty()) {
            int v = pq.begin()->first;
            pq.erase(pq.begin());
            Relax(G, v);
        }
    }

    bool HasPathTo(int v) {
        return distto[v] != DBL_MAX;
    }

    vector<shared_ptr<DirectedEdge>> GetPathTo(int v) {
        if(!HasPathTo(v)) {
            throw logic_error("Havs No Path To input Node");
        }
        vector<shared_ptr<DirectedEdge>> result;
        for(auto edge = edgeto[v]; edge != nullptr; edge = edgeto[edge->From()]) {
            result.emplace_back(edge);
        }
        reverse(result.begin(), result.end());
        return result;
    }

    double DistTo(int v) {
        return distto[v];
    }

private:
    vector<double> distto;
    vector<shared_ptr<DirectedEdge>> edgeto;
    map<int, double> pq;

    void Relax(shared_ptr<DirectedEdge> e) {
        int v = e->From(), w = e->To();
        if(distto[w] > distto[v] + e->Weight()) {
            distto[w] = distto[v] + e->Weight();
            edgeto[w] = e;
        }
    }

    void Relax(EdgeWeightedDigraph G, int v) {
        for(auto e : G.GetAdj(v)) {
            int w = e->To();
            if(distto[w] > distto[v] + e->Weight()) {
                distto[w] = distto[v] + e->Weight();
                edgeto[w] = e;
                auto iter = pq.find(w);
                if(iter == pq.end()) {
                    pq.insert(pair<int, double>(w, distto[w]));
                } else {
                    iter->second = distto[w];
                }
            }
        }
    }
};

#endif //ALGORITHMEXERCISE_DijkstraSP_H