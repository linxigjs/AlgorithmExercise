//
// Created by gjs on 19-1-7.
//

#include "AcyclicLP.h"


int main() {
    EdgeWeightedDigraph gh("../tinyEWDAG.txt");

    int s=5;
    AcyclicLP topo(gh, s);

    for(auto e : topo.GetAllEdges()) {
        if(e)
            cout << e;
    }
    cout << endl;

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