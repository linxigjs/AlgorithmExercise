//
// Created by gjs on 19-1-7.
//

#include "Cycle.h"


int main() {
    Graph gh("../tiny.txt");
    int start = 0;
    Cycle cc(gh);

    cout << boolalpha << cc.HasCycle() << endl;

    return 0;
}