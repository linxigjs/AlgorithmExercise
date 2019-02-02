//
// Created by gjs on 19-1-7.
//

#include "BellmanFordSP.h"

using namespace std;

int main() {
    EdgeWeightedDigraph task("../tinyEWDnc.txt");

    BellmanFordSP bell(task, 0);
    if(bell.HasNegativeCycle()) {
        for(auto e : bell.GetCycle()) {
            cout << e;
        }
    }

    cout << endl;

    return 0;
}