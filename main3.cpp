//
// Created by gjs on 19-1-7.
//

#include "DepthFirstOrder.h"

void Print(const vector<int> &vec) {
    for(auto e : vec) {
        cout << e << " ";
    }
    cout << endl;
}

int main() {
    Digraph gh("../tiny3.txt");
    DepthFirstOrder dc(gh);
    Print(dc.Pre());
    Print(dc.Post());
    Print(dc.ReversePost());

    cout << endl;

    return 0;
}