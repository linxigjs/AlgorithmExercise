//
// Created by gjs on 19-1-7.
//

#include "Shorter.h"

using namespace std;

int main() {
    EdgeWeightedDigraph task("../tinyEWDss.txt");

    Shorter bell(task, 0);

    for(auto e : bell.GetShorterPathTo(4)) {
        cout << e;
    }


    cout << endl;

    return 0;
}