//
// Created by gjs on 19-1-7.
//

#include "ConnectedComponent.h"


int main() {
    Graph gh("../tiny.txt");
    int start = 0;
    ConnectedComponent cc(gh);

    cout << "There are " << cc.GetTrees() << " components." << endl;
    for(int i = 0; i<cc.GetTrees(); i++) {
        cout << i << ": ";
        for(int j=0; j<gh.GetV(); j++) {
            if(cc.GetId(j) == i)
                cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}