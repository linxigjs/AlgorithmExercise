//
// Created by gjs on 19-1-7.
//

#include "DepthFirstPaths.h"


int main() {
    Graph gh("../tiny.txt");
    int start = 0;
    DepthFirstPaths ds(gh, start);

    int goal = 2;
    if(ds.HasPathTo(goal)) {
        for(auto e : ds.GetPathTo(goal))
            cout << e << " ";
        cout << endl;
    } else {
        cout << "Cannot find path to " << goal << endl;
    }

    return 0;
}