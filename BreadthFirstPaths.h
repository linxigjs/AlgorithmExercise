//
// Created by gjs on 19-1-9.
//

#ifndef ALGORITHMEXERCISE_BREADTHFIRSTPATHS_H
#define ALGORITHMEXERCISE_BREADTHFIRSTPATHS_H

#include <iostream>
#include <vector>
#include <algorithm>
#include "Graph.h"

using namespace std;

class BreadthFirstPaths {
public:
    BreadthFirstPaths(Graph G, int s) {
        start = s;
        marked.assign(G.GetV(), 0);
        edgeto.assign(G.GetV(), -1);
        bfs(G, s);
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
    void bfs(Graph G, int v) {
        marked[v] = 1;
        vector<int> temp;
        temp.emplace_back(v);
        while(!temp.empty()) {
            v = temp.back();
            temp.pop_back();
            for(auto w : G.Adj(v)) {
                if(marked[w] != 1) {
                    marked[w] = 1;
                    edgeto[w] = v;
                    temp.emplace_back(w);
                }
            }
        }
    }
    vector<int> marked;
    vector<int> edgeto;
    int start;
};

#endif //ALGORITHMEXERCISE_BREADTHFIRSTPATHS_H
