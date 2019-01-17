//
// Created by gjs on 19-1-17.
//

#ifndef ALGORITHMEXERCISE_TRANSITIVECLOSURE_H
#define ALGORITHMEXERCISE_TRANSITIVECLOSURE_H

#include "Digraph.h"
#include "DirectedDFS.h"

class TransitiveClosure {
public:
    TransitiveClosure(Digraph G) {
        for(int i=0; i<G.GetV(); i++) {
            DirectedDFS dd(G, i);
            all_marked.emplace_back(dd);
        }
    }

    //w is reachable from v?
    bool IsReachable(int v, int w) {
        return all_marked[v].Marked(w);
    }

private:
    vector<DirectedDFS> all_marked;

};

#endif //ALGORITHMEXERCISE_TRANSITIVECLOSURE_H
