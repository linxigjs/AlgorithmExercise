//
// Created by gjs on 19-1-7.
//

#include "EdgeWeightedGraph.h"

using namespace std;

int main() {
    EdgeWeightedGraph ew("../tiny.txt");

    for(auto e : ew.GetEdges()) {
        cout << *e;
    }
    cout << endl;
    return 0;
}