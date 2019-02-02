//
// Created by gjs on 19-1-31.
//

#ifndef ALGORITHMEXERCISE_BELLMANFORDSP_H
#define ALGORITHMEXERCISE_BELLMANFORDSP_H

#include "EdgeWeightedDigraph.h"
#include "EdgeWeightedCycleFinder.h"
#include <queue>
#include <cfloat>

using namespace std;

class BellmanFordSP {
public:
    BellmanFordSP(EdgeWeightedDigraph& G, int s) {
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

    vector<shared_ptr<DirectedEdge>> GetCycle() {
        return cycle;
    }

private:
    vector<double> distto;
    vector<shared_ptr<DirectedEdge>> edgeto;
    queue<int> container;
    vector<bool> inqueue;
    int calls = 0;
    vector<shared_ptr<DirectedEdge>> cycle;

    void Relax(EdgeWeightedDigraph G, int s) {
        for(auto e : G.GetAdj(s)) {
            int w = e->To();
            if(distto[w] > distto[s] + e->Weight()) {
                distto[w] = distto[s] + e->Weight();
                edgeto[w] = e;
                if(!inqueue[w]) {
                    container.emplace(w);
                    inqueue[w] = true;
                }
            }
            if((calls++) % G.GetV() == 0 && calls!=0) {
                FindNegativeCycle();
            }
        }
    }

    void FindNegativeCycle() {
        int V = edgeto.size();
        EdgeWeightedDigraph spt(V);
        for(int i=0; i<V; i++) {
            if(edgeto[i] != nullptr) {
                spt.AddEdge(edgeto[i]);
            }
        }
        EdgeWeightedCycleFinder cf(spt);
        for(auto e : cf.GetCycle())
            cycle.emplace_back(e);
    }
};

#endif //ALGORITHMEXERCISE_BELLMANFORDSP_H
