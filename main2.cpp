//
// Created by gjs on 19-1-7.
//

#include "Topological.h"


int main() {
    EdgeWeightedDigraph gh("../tinyEWDAG.txt");
//    for(auto e : gh.GetAllEdges()) {
//        cout << e;
//    }
//    cout << endl;

    Topological topo(gh, 5);

    for(int i : topo.GetTopologicalOrder()) {
        cout << i << " " << endl;

    }


    cout << endl;

    return 0;
}