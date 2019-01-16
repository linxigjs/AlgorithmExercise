//
// Created by gjs on 19-1-16.
//

#ifndef ALGORITHMEXERCISE_TOPOLOGICAL_H
#define ALGORITHMEXERCISE_TOPOLOGICAL_H

#include "DirectedCycle.h"
#include "DepthFirstOrder.h"

class Topological {
public:
    Topological(Digraph G) {
        DirectedCycle cycleFinder(G);
        if(!cycleFinder.HasCycle()) {
            DepthFirstOrder dep(G);
            order = dep.ReversePost();
        }
    }

    vector<int> GetOrder() const {
        return order;
    }

private:
    vector<int> order;
};

#endif //ALGORITHMEXERCISE_TOPOLOGICAL_H
