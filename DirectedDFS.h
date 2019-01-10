//
// Created by gjs on 19-1-10.
//

#ifndef ALGORITHMEXERCISE_DIRECTEDDFS_H
#define ALGORITHMEXERCISE_DIRECTEDDFS_H

#include "Digraph.h"

using namespace std;

class DirectedDFS {
public:
    DirectedDFS(Digraph G, int s) {
        marked.assign(G.GetV(), 0);
        dfs(G, s);
    }
    DirectedDFS(Digraph G, vector<int> sources) {
        marked.assign(G.GetV(), 0);
        for(int s : sources) {
            if(marked[s] != 1)
                dfs(G, s);
        }
    }
    bool Marked(int v) {
        return marked[v] == 1;
    }

private:
    void dfs(Digraph G, int v) {
        marked[v] = 1;
        for(int w : G.Adj(v)) {
            if(marked[w] != 1) {
                dfs(G, w);
            }
        }
    }

    vector<int> marked;
};

#endif //ALGORITHMEXERCISE_DIRECTEDDFS_H
