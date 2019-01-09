//
// Created by gjs on 19-1-7.
//

#ifndef ALGORITHMEXERCISE_DEPTHFIRSTSEARCH_H
#define ALGORITHMEXERCISE_DEPTHFIRSTSEARCH_H

#include "Graph.h"

class DepthFirstSearch {
public:
    DepthFirstSearch(Graph G, int s) {
        marked.assign(G.GetV(), 0);
        dfs(G, s);
    }
    int Marked(int v) {
        return marked[v];
    }
    int GetCount() const {
        return count;
    }

private:
    void dfs(Graph G, int v) {
        marked[v] = 1;
        count++;
        for(auto w : G.Adj(v)) {
            if(marked[w] != 1)
                dfs(G, w);
        }
    }
    vector<int> marked;
    int count = 0;
};

#endif //ALGORITHMEXERCISE_DEPTHFIRSTSEARCH_H
