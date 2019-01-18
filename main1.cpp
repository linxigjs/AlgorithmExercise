//
// Created by gjs on 19-1-7.
//

#include "LazyPrimMST.h"

using namespace std;

int main() {
    EdgeWeightedGraph ew("../tinyEWG.txt");
    LazyPrimMST mst(ew);
    for(auto e : mst.GetMST()) {
        cout << *e;
    }
    cout << endl;
    return 0;
}