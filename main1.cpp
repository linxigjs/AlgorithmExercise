//
// Created by gjs on 19-1-7.
//

#include "DirectedDFS.h"


int main() {
    Digraph gh("../tiny.txt");
    vector<int> sources{1, 2, 6};
    DirectedDFS reachable(gh, sources);
    for(int i=0; i<gh.GetV(); i++) {
        if(reachable.Marked(i))
            cout << i << " ";
    }
    cout << endl;

    return 0;
}