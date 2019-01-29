//
// Created by gjs on 19-1-29.
//

#ifndef ALGORITHMEXERCISE_SP_H
#define ALGORITHMEXERCISE_SP_H

#include <cfloat>
#include <algorithm>
#include "EdgeWeightedDigraph.h"

class SP {
public:
    SP(EdgeWeightedDigraph G, int s) {
        distto.assign(G.GetV(), DBL_MAX);
        edgeto.assign(G.GetV(), nullptr);
    }
    bool HasPathTo(int v) {
        return distto[v] != DBL_MAX;
    }
    vector<shared_ptr<DirectedEdge>> GetPathTo(int v) {
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
};

#endif //ALGORITHMEXERCISE_SP_H
