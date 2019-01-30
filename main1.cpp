//
// Created by gjs on 19-1-7.
//

#include "DijkstraSP.h"


int main() {
    EdgeWeightedDigraph gh("../tinyEWD.txt");
//    for(auto e : gh.GetAllEdges()) {
//        cout << e;
//    }
//    cout << endl;

    DijkstraSP sp(gh, 0);

    for(int i=1; i<gh.GetV(); i++) {
        cout << "0 --> " << i << " : " << endl;
        for(auto e : sp.GetPathTo(i)) {
            cout << e;
        }
        cout << endl;
    }


    cout << endl;

    return 0;
}