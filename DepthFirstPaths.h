//
// Created by gjs on 19-1-9.
//

#ifndef ALGORITHMEXERCISE_DEPTHFIRSTPATHS_H
#define ALGORITHMEXERCISE_DEPTHFIRSTPATHS_H

#include <iostream>
#include <vector>
#include <algorithm>
#include "Graph.h"

using namespace std;

class DepthFirstPaths {
public:
    DepthFirstPaths(Graph G, int s) {
        start = s;
        marked.assign(G.GetV(), 0);
        edgeto.assign(G.GetV(), -1);
        dfs(G, s);
    }
    bool HasPathTo(int v) {
        return marked[v] == 1;
    }
    vector<int> GetPathTo(int v) {
        vector<int> path;
        if(!HasPathTo(v))
            return path;
        while(v != start) {
            path.emplace_back(v);
            v = edgeto[v];
        }
        path.emplace_back(v);
        reverse(path.begin(), path.end());
        return path;
    }

private:
    void dfs(Graph G, int v) {
        marked[v] = 1;
        for(auto w : G.Adj(v)) {
            if(marked[w] != 1) {
                edgeto[w] = v;
                dfs(G, w);
            }
        }
    }
    vector<int> edgeto;
    vector<int> marked;
    int start;
};

#endif //ALGORITHMEXERCISE_DEPTHFIRSTPATHS_H
