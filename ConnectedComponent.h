//
// Created by gjs on 19-1-9.
//

#ifndef ALGORITHMEXERCISE_CONNECTEDCOMPONENT_H
#define ALGORITHMEXERCISE_CONNECTEDCOMPONENT_H

#include <iostream>
#include <vector>
#include <algorithm>
#include "Graph.h"

using namespace std;

class ConnectedComponent {
public:
    ConnectedComponent(Graph G) {
        marked.assign(G.GetV(), 0);
        id.assign(G.GetV(), -1);
        for(int s=0; s<G.GetV(); s++) {
            if(marked[s] != 1) {
                dfs(G, s);
                count++;
            }
        }
    }
    bool IsConnected(int v, int w) const {
        return id[v] == id[w];
    }
    int GetId(int v) const {
        return id[v];
    }
    int GetTrees() const {
        return count;
    }

private:
    void dfs(Graph G, int v) {
        marked[v] = 1;
        id[v] = count;
        for(int w : G.Adj(v)) {
            if(marked[w] != 1)
                dfs(G, w);
        }
    }
    vector<int> marked;
    vector<int> id;
    int count = 0;
};

#endif //ALGORITHMEXERCISE_CONNECTEDCOMPONENT_H
