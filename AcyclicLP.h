//
// Created by gjs on 19-1-30.
//

#ifndef ALGORITHMEXERCISE_ACYCLICLP_H
#define ALGORITHMEXERCISE_ACYCLICLP_H

#include <cfloat>
#include "Topological.h"

class AcyclicLP {
public:
    AcyclicLP(EdgeWeightedDigraph G, int s) {
        Topological topo(G, s);
        distto.assign(G.GetV(), -DBL_MAX);
        edgeto.assign(G.GetV(), nullptr);
        distto[s] = 0.0;
        for(int v : topo.GetTopologicalOrder()) {
            Relax(G, v);
        }
    }

    bool HasPathTo(int v) {
        return distto[v] != -DBL_MAX;
    }

    vector<shared_ptr<DirectedEdge>> GetPathTo(int v) {
        if(!HasPathTo(v)) {
            throw logic_error("Has No Path To input Node");
        }
        vector<shared_ptr<DirectedEdge>> result;
        for(auto edge = edgeto[v]; edge != nullptr; edge = edgeto[edge->From()]) {
            result.emplace_back(edge);
        }
        reverse(result.begin(), result.end());
        return result;
    }

    vector<shared_ptr<DirectedEdge>> GetAllEdges() {
        return edgeto;
    }

    double DistTo(int v) {
        return distto[v];
    }

private:
    vector<double> distto;
    vector<shared_ptr<DirectedEdge>> edgeto;
    
    void Relax(EdgeWeightedDigraph G, int v) {
        for(auto e : G.GetAdj(v)) {
            int w = e->To();
            if(distto[w] < distto[v] + e->Weight()) {
                distto[w] = distto[v] + e->Weight();
                edgeto[w] = e;
            }
        }
    }
};

#endif //ALGORITHMEXERCISE_ACYCLICLP_H
