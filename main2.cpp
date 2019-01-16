//
// Created by gjs on 19-1-7.
//

#include "DirectedCycle.h"


int main() {
    Digraph gh("../tiny.txt");
    DirectedCycle dc(gh);
    if(dc.HasCycle()) {
        cout << "Has cycle : " << endl;
        for(int e : dc.GetCycle()) {
            cout << e << " ";
        }
    } else {
        cout << "Has no cycle." << endl;
    }
    cout << endl;

    return 0;
}