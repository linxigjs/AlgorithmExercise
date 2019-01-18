//
// Created by gjs on 19-1-18.
//

#ifndef ALGORITHMEXERCISE_PRIMMST_H
#define ALGORITHMEXERCISE_PRIMMST_H

#include <queue>
#include "EdgeWeightedGraph.h"

class PairComp {
public:
    bool operator() (const pair<double, int> a, const pair<double, int> b) {
        return a.first > b.first;
    }
};

typedef priority_queue<pair<double, int>, vector<pair<double, int>>, PairComp> PQ;

class PrimMST {
public:
    PrimMST(EdgeWeightedGraph G) {
        marked.assign(G.GetV(), 0);
        edgeto.assign(G.GetV(), make_shared<Edge>(0,0,0));
        distto.assign(G.GetV(), std::numeric_limits<double>::infinity());
        distto[0] = 0.0;
        pq.push(pair<double,int>(0.0, 0));
        while(!pq.empty()) {
            int v = pq.top().second;
            pq.pop();
            Visit(G, v);
        }
    }

    vector<shared_ptr<Edge>> GetMST() {
        vector<shared_ptr<Edge>> res;
        for(int i=0; i<edgeto.size(); i++) {
            int w = edgeto[i]->GetEither(), v = edgeto[i]->GetOther(w);
            if(distto[i] != std::numeric_limits<double>::infinity() && w != v) {
                res.emplace_back(edgeto[i]);
            }
        }
        return res;
    }

private:
    void Visit(EdgeWeightedGraph G, int v) {
        marked[v] = 1;
        for(auto e : G.GetAdj(v)) {
            int w = e->GetOther(v);
            if(marked[w] == 1) {
                continue;
            }
            if(e->GetWeight() < distto[w] || e->GetWeight() == 0) {
                edgeto[w] = e;
                distto[w] = e->GetWeight();
                if(IsContained(pq, w)) {
                    pq = ChangeElem(pq, distto[w], w);
                } else {
                    pq.push(pair<double,int>(distto[w], w));
                }
            }
        }
    }

    bool IsContained(PQ pq, int w) {
        while(!pq.empty()) {
            if(pq.top().second == w) {
                return true;
            } else {
                pq.pop();
            }
        }
        return false;
    }

    PQ ChangeElem(PQ pq, double weight, int w) {
        PQ temp;
        while(!pq.empty()) {
            if(pq.top().second == w) {
                temp.push(pair<double,int>(weight, w));
            } else {
                temp.push(pq.top());
            }
            pq.pop();
        }
        return temp;
    }

    vector<int> marked;
    vector<shared_ptr<Edge>> edgeto;
    vector<double> distto;
    PQ pq;
};

#endif //ALGORITHMEXERCISE_PRIMMST_H
