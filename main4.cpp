//
// Created by gjs on 19-1-7.
//

#include "KosarajuSSC.h"

void Print(const vector<int> &vec) {
    for(auto e : vec) {
        cout << e << " ";
    }
    cout << endl;
}

int main() {
    Digraph gh("../tiny2.txt");
    KosarajuSSC dc(gh);

    cout << dc.Count() << " components." << endl;
    for(int i=0; i<dc.Count(); i++) {
        cout << "id " << i << ": ";
        for(int j=0; j<gh.GetV(); j++) {
            if(dc.Id(j) == i) {
                cout << j << " ";
            }
        }
        cout << endl;
    }

    cout << endl;

    return 0;
}