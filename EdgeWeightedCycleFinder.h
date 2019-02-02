//
// Created by gjs on 19-2-2.
//

#ifndef ALGORITHMEXERCISE_EDGEWEIGHTEDCYCLEFINDER_H
#define ALGORITHMEXERCISE_EDGEWEIGHTEDCYCLEFINDER_H

#include "EdgeWeightedDigraph.h"

class EdgeWeightedCycleFinder {
public:
    EdgeWeightedCycleFinder(EdgeWeightedDigraph G) {
        marked.assign(G.GetV(), 0);
        edgeto.assign(G.GetV(), nullptr);
        onstack.assign(G.GetV(), false);
        for(int i=0; i<G.GetV(); i++) {
            if(marked[i] == 0) {
                dfs(G, i);
            }
        }
    }

    bool HasCycle() {
        return !cycle.empty();
    }

    vector<shared_ptr<DirectedEdge>> GetCycle() {
        return cycle;
    }

private:
    vector<int> marked;
    vector<shared_ptr<DirectedEdge>> edgeto;
    vector<shared_ptr<DirectedEdge>> cycle;
    vector<bool> onstack;

    void dfs(EdgeWeightedDigraph G, int v) {
        marked[v] = 1;
        onstack[v] = true;
        for(auto e : G.GetAdj(v)) {
            if(HasCycle())
                return;
            int w = e->To();
            if(marked[w] == 0) {
                edgeto[w] = e;
                dfs(G, w);
            } else if(onstack[w]) {
                cycle.emplace_back(e);
                for(auto temp=edgeto[v]; temp->From()!=v; temp=edgeto[temp->From()]) {
                    cycle.emplace_back(temp);
                }
                cycle.emplace_back(edgeto[w]);
                return;
            }
        }
        onstack[v] = false;
    }
};

#endif //ALGORITHMEXERCISE_EDGEWEIGHTEDCYCLEFINDER_H
