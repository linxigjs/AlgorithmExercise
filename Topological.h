//
// Created by gjs on 19-1-30.
//

#ifndef ALGORITHMEXERCISE_TOPOLOGICAL_H
#define ALGORITHMEXERCISE_TOPOLOGICAL_H

#include <algorithm>
#include "EdgeWeightedDigraph.h"

class Topological {
public:
    Topological(EdgeWeightedDigraph G, int s) {
        marked.assign(G.GetV(), 0);
        if(marked[s] != 1) {
            dfs(G, s);
        }
        for(int i=0; i != s && i<G.GetV(); i++) {
            if(marked[i] != 1) {
                dfs(G, i);
            }
        }
        reverse(reverse_post.begin(), reverse_post.end());
    }

    vector<int> GetTopologicalOrder() {
        return reverse_post;
    }

private:
    vector<int> marked;
    vector<int> reverse_post;

    void dfs(EdgeWeightedDigraph G, int v) {
        marked[v] = 1;
        for(auto e : G.GetAdj(v)) {
            int w = e->To();
            if(marked[w] != 1) {
                dfs(G, w);
            }
        }
        reverse_post.emplace_back(v);
    }
};

#endif //ALGORITHMEXERCISE_TOPOLOGICAL_H
