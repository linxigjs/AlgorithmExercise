//
// Created by gjs on 19-1-7.
//

#include "DepthFirstSearch.h"


int main() {
    Graph gh("../tiny.txt");
    DepthFirstSearch ds(gh, 0);

    for(int i=0; i<gh.GetV(); i++) {
        if(ds.Marked(i) == 1)
            cout << i << " ";
    }
    if(ds.GetCount() != gh.GetV())
        cout << "Not Connect" << endl;
    else
        cout << "Connect" << endl;

    return 0;
}