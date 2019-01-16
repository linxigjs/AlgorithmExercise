//
// Created by gjs on 19-1-16.
//

#ifndef ALGORITHMEXERCISE_DIRECTEDCYCLE_H
#define ALGORITHMEXERCISE_DIRECTEDCYCLE_H

#include "Digraph.h"

using namespace std;

class DirectedCycle {
public:
    DirectedCycle(Digraph G) {
        marked.assign(G.GetV(), 0);
        edgeto.assign(G.GetV(), -1);
        onstack.assign(G.GetV(), 0);
        for(int v=0; v<G.GetV(); v++) {
            if(marked[v] == 0) {
                dfs(G, v);
            }
        }
    }

    bool HasCycle() {
        return !cycle.empty();
    }

    vector<int> GetCycle() {
        return cycle;
    }

private:
    void dfs(Digraph G, int v) {
        marked[v] = 1;
        onstack[v] = 1;
        for(int w : G.Adj(v)) {
            if(HasCycle()) {
                return;
            } else if(marked[w] == 0) {
                edgeto[w] = v;
                dfs(G, w);
            } else if(onstack[w]) {
                for(int x=v; x!=w; x=edgeto[x]) {
                    cycle.emplace_back(x);
                }
                cycle.emplace_back(w);
                cycle.emplace_back(v);
            }
        }
        onstack[v] = 0;
    }

    vector<int> marked, edgeto, cycle, onstack;
};

#endif //ALGORITHMEXERCISE_DIRECTEDCYCLE_H
