//
// Created by gjs on 19-1-7.
//

#include "AcyclicSP.h"


int main() {
    EdgeWeightedDigraph gh("../tinyEWDAG.txt");
//    for(auto e : gh.GetAllEdges()) {
//        cout << e;
//    }
//    cout << endl;

    int s=5;
    AcyclicSP topo(gh, s);

    for(int i=0; i<gh.GetV(); i++) {
        cout << s << " --> " << i << ": " << endl;
        for(auto e : topo.GetPathTo(i)) {
            cout << e;
        }
        cout << endl;
    }


    cout << endl;

    return 0;
}