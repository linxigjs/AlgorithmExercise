//
// Created by gjs on 19-1-7.
//

#include "KruskalMST.h"

using namespace std;

int main() {
    EdgeWeightedGraph ew("../tinyEWG.txt");
    KruskalMST mst(ew);
    for(auto e : mst.GetMST()) {
        cout << *e;
    }
    cout << endl;
    return 0;
}