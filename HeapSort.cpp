//
// Created by gjs on 18-12-27.
//

#include <iostream>
#include <vector>

using namespace std;

class HeapSort {
public:
    HeapSort() {}
    void Sort(vector<int>& vec) {
        int len = vec.size()-1;
        for(int k = (vec.size()-1) / 2; k>=1; k--) {
            Sink(vec, k, len);
        }
        for(int i=0; i<vec.size()-1; i++) {
            Exchange(vec, len--, 1);
            Sink(vec, 1, len);
        }
    }
private:
    void Sink(vector<int>& vec, int ind, int len) {
        while(2*ind <= len) {
            int j = 2*ind;
            if(j<len && vec[j] < vec[j+1]) {
                j++;
            }
            if(vec[j] > vec[ind]) {
                Exchange(vec, j, ind);
                ind = j;
            } else {
                return;
            }
        }
    }
    void Exchange(vector<int>& vec, int l, int r) {
        auto t = vec[l];
        vec[l] = vec[r];
        vec[r] = t;
    }
};

void Print(const vector<int> vec) {
    cout << "Element in vec : " << endl;
    for(auto e : vec)
        cout << e << " " << endl;
    cout << endl;
}

int main() {
    vector<int> vec{-1, 46, 34, 67, 2, 54, 111, 333};
    vector<int> vec2{-1, 46};
    HeapSort().Sort(vec);
    Print(vec);
    HeapSort().Sort(vec2);
    Print(vec2);
}
