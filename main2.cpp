//
// Created by gjs on 19-1-7.
//

#include "PrimMST.h"

using namespace std;

int main() {
    EdgeWeightedGraph ew("../tinyEWG.txt");
    PrimMST mst(ew);
    for(auto e : mst.GetMST()) {
        cout << *e;
    }
    cout << endl;
    return 0;
}