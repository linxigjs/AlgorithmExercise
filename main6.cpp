//
// Created by gjs on 19-1-7.
//

#include "BellmanFordSP.h"

using namespace std;

int main() {
    EdgeWeightedDigraph task;
    task.ParseTaskDigraph("../jobsPC.txt");

    
    queue<int> con;
    con.emplace(1);
    con.emplace(2);
    con.emplace(3);
    con.emplace(4);
    con.emplace(5);
    
    cout << con.front() << " " << con.back() << endl;
    con.pop();
    cout << con.front() << " " << con.back() << endl;

    cout << endl;

    return 0;
}