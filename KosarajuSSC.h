//
// Created by gjs on 19-1-17.
//

#ifndef ALGORITHMEXERCISE_KOSARAJUSSC_H
#define ALGORITHMEXERCISE_KOSARAJUSSC_H

#include "Digraph.h"
#include "DepthFirstOrder.h"

class KosarajuSSC {
public:
    KosarajuSSC(Digraph G) {
        marked.assign(G.GetV(), 0);
        id.assign(G.GetV(), 0);
        DepthFirstOrder order(G.Reverse());
        for(int w : order.ReversePost()) {
            if(marked[w] == 0) {
                dfs(G, w);
                count++;
            }
        }
    }

    bool IsStronglyConnected(int w, int v) {
        return id[w] == id[v];
    }

    int Id(int v) {
        return id[v];
    }

    int Count() {
        return count;
    }

private:
    vector<int> marked, id;
    int count = 0;

    void dfs(Digraph G, int v) {
        marked[v] = 1;
        id[v] = count;
        for(int w : G.Adj(v)) {
            if(marked[w] == 0) {
                dfs(G, w);
            }
        }
    }
};

#endif //ALGORITHMEXERCISE_KOSARAJUSSC_H
