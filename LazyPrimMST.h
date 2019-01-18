//
// Created by gjs on 19-1-18.
//

#ifndef ALGORITHMEXERCISE_LAZYPRIMMST_H
#define ALGORITHMEXERCISE_LAZYPRIMMST_H

#include <queue>
#include "EdgeWeightedGraph.h"

class EdgeCompare {
public:
    bool operator()(const shared_ptr<Edge> l, const shared_ptr<Edge> r) {
        return l->GetWeight() > r->GetWeight();
    }
};

class LazyPrimMST {
public:
    LazyPrimMST(EdgeWeightedGraph G) {
        marked.assign(G.GetV(), 0);
        Visit(G, 0);
        while(!pq.empty()) {
            shared_ptr<Edge> eptr = pq.top();
            pq.pop();
            int v = eptr->GetEither(), w = eptr->GetOther(v);
            if(marked[v] == 1 && marked[w] == 1) {
                continue;
            }
            mst.emplace_back(eptr);
            if(!marked[v]) {
                Visit(G, v);
            }
            if(!marked[w]) {
                Visit(G, w);
            }
        }
    }

    vector<shared_ptr<Edge>> GetMST() {
        return mst;
    }

private:
    void Visit(EdgeWeightedGraph G, int v) {
        marked[v] = 1;
        for(auto e : G.GetAdj(v)) {
            if(marked[e->GetOther(v)] == 0) {
                pq.push(e);
            }
        }
    }

    vector<int> marked;
    vector<shared_ptr<Edge>> mst;
    priority_queue<shared_ptr<Edge>, vector<shared_ptr<Edge>>, EdgeCompare> pq;
};

#endif //ALGORITHMEXERCISE_LAZYPRIMMST_H
