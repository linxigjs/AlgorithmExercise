//
// Created by gjs on 19-1-9.
//

#ifndef ALGORITHMEXERCISE_CYCLE_H
#define ALGORITHMEXERCISE_CYCLE_H

#include <iostream>
#include <vector>
#include <algorithm>
#include "Graph.h"

using namespace std;

class Cycle {
public:
    Cycle(Graph G) {
        marked.assign(G.GetV(), 0);
        for(int i=0; i<G.GetV(); i++) {
            if(marked[i] != 1)
                dfs(G, i, i);
        }
    }
    bool HasCycle() const {
        return hascycle;
    }

private:
    void dfs(Graph G, int v, int father) {
        marked[v] = 1;
        for(int w : G.Adj(v)) {
            if(marked[w] != 1) {
                dfs(G, w, v);
            } else if(w != father) {
                hascycle = true;
            }
        }
    }
    vector<int> marked;
    bool hascycle = false;
};

#endif //ALGORITHMEXERCISE_CYCLE_H
