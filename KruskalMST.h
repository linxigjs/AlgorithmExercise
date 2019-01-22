//
// Created by gjs on 19-1-22.
//

#ifndef ALGORITHMEXERCISE_KRUSKALMST_H
#define ALGORITHMEXERCISE_KRUSKALMST_H

#include <queue>
#include "EdgeWeightedGraph.h"
#include "UnionFind.h"

using namespace std;

class EdgeComp {
public:
    bool operator()(shared_ptr<Edge> l, shared_ptr<Edge> r) {
        return l->GetWeight() > r->GetWeight();
    }
};

class KruskalMST {
public:
    KruskalMST(EdgeWeightedGraph G) {
        for(const auto &e : G.GetEdges()) {
            pq.emplace(e);
        }
        UnionFind uf(G.GetV());
        while(mst.size() < G.GetV()-1) {
            auto e = pq.top();
            pq.pop();
            int w = e->GetEither(), v = e->GetOther(w);
            if(uf.IsConnected(w, v))
                continue;
            mst.push_back(e);
            uf.Union(w, v);
        }
    }

    vector<shared_ptr<Edge>> GetMST() {
        return mst;
    }

private:
    priority_queue<shared_ptr<Edge>, vector<shared_ptr<Edge>>, EdgeComp> pq;
    vector<shared_ptr<Edge>> mst;
};

#endif //ALGORITHMEXERCISE_KRUSKALMST_H
