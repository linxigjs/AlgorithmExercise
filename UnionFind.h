//
// Created by gjs on 19-1-22.
//

#ifndef ALGORITHMEXERCISE_UNIONFIND_H
#define ALGORITHMEXERCISE_UNIONFIND_H

#include <vector>

using namespace std;

class UnionFind {
public:
    UnionFind(int n) {
        for(int i=0; i<n; i++) {
            id.emplace_back(i);
        }
        count = n;
    }

    int GetCount() {
        return count;
    }

    bool IsConnected(int p, int q) {
        return find(p) == find(q);
    }

    void Union(int p, int q) {
        if(IsConnected(p, q))
            return;
        int qroot = find(q), proot = find(p);
        id[proot] = qroot;
        count--;
    }

private:
    int find(int p) {
        while (id[p] != p)
            p = id[p];
        return p;
    }

    vector<int> id;
    int count;
};

#endif //ALGORITHMEXERCISE_UNIONFIND_H
