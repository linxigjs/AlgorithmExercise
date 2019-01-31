//
// Created by gjs on 19-1-31.
//

#ifndef ALGORITHMEXERCISE_BELLMANFORDSP_H
#define ALGORITHMEXERCISE_BELLMANFORDSP_H

#include "EdgeWeightedDigraph.h"
#include <queue>
#include <cfloat>

using namespace std;

class BellmanFordSP {
public:
    BellmanFordSP(EdgeWeightedDigraph G, int s) {
        distto.assign(G.GetV(), DBL_MAX);
        edgeto.assign(G.GetV(), nullptr);
        inqueue.assign(G.GetV(), false);

        distto[s] = 0.0;
        container.emplace(s);
        inqueue[s] = true;

        while(!container.empty() && !HasNegativeCycle()) {
            int v = container.front();
            container.pop();
            inqueue[v] = false;
            Relax(G, v);
        }
    }

    bool HasNegativeCycle() {
        return !cycle.empty();
    }

private:
    vector<double> distto;
    vector<shared_ptr<DirectedEdge>> edgeto;
    queue<int> container;
    vector<bool> inqueue;
    int calls;
    vector<shared_ptr<DirectedEdge>> cycle;

    void Relax(EdgeWeightedDigraph G, int s) {
        for(auto e : G.GetAdj(s)) {
            int w = e->To();
            if(distto[w] > distto[w] + e->Weight()) {
                distto[w] = distto[w] + e->Weight();
                edgeto[w] = e;
                if(!inqueue[w]) {
                    container.emplace(w);
                    inqueue[w] = true;
                }
            }
            if(calls++ % G.GetV() == 0) {
                FindNegativeCycle();
            }
        }
    }

    void FindNegativeCycle() {

    }
};

#endif //ALGORITHMEXERCISE_BELLMANFORDSP_H
