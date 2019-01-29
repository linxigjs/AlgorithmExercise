//
// Created by gjs on 19-1-7.
//

#include "SP.h"


int main() {
    EdgeWeightedDigraph gh("../tinyEWD.txt");

    SP sp(gh, 3);

    for(auto e : sp.GetPathTo(5)) {
        cout << e;
    }

    cout << endl;

    return 0;
}