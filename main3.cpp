//
// Created by gjs on 19-1-7.
//

#include "BreadthFirstPaths.h"


int main() {
    Graph gh("../tiny.txt");
    int start = 0;
    BreadthFirstPaths bs(gh, start);

    int goal = 4;
    if(bs.HasPathTo(goal)) {
        for(auto e : bs.GetPathTo(goal))
            cout << e << " ";
        cout << endl;
    } else {
        cout << "Cannot find path to " << goal << endl;
    }

    return 0;
}