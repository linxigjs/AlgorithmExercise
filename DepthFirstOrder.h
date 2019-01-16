//
// Created by gjs on 19-1-16.
//

#ifndef ALGORITHMEXERCISE_DEPTHFIRSTORDER_H
#define ALGORITHMEXERCISE_DEPTHFIRSTORDER_H

#include "Digraph.h"

class DepthFirstOrder {
public:
    DepthFirstOrder(Digraph G) {
        marked.assign(G.GetV(), 0);
        for(int v=0; v<G.GetV(); v++) {
            if(marked[v] == 0) {
                dfs(G, v);
            }
        }
    }
    
    vector<int> Pre() {
        return pre;
    }
    
    vector<int> Post() {
        return post;
    }

    vector<int> ReversePost() {
        revpost = post;
        reverse(revpost.begin(), revpost.end());
        return revpost;
    }

private:
    void dfs(Digraph G, int v) {
        marked[v] = 1;
        pre.emplace_back(v);
        for(int w : G.Adj(v)) {
            if(marked[w] == 0) {
                dfs(G, w);
            }
        }
        post.emplace_back(v);
    }
    
    vector<int> marked, pre, post, revpost;
};

#endif //ALGORITHMEXERCISE_DEPTHFIRSTORDER_H
