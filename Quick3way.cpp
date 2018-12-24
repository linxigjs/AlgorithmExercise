//
// Created by gjs on 18-10-18.
//

// 三向切分的快速排序

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <typename T>
class Solution {
public:
    void QuickSort(vector<T>& vec) {
        Sort(vec, 0, vec.size()-1);
    }
private:
    void Sort(vector<T>& vec, int lo, int hi) {
        if(lo >= hi)
            return;
        int lt = lo, i = lo+1, gt = hi;
        int v = vec[lo];
        while(i <= gt) {
            if(vec[i] < v) {
                Exchange(vec, i, lt);
                i++;
                lt++;
            } else if(vec[i] > v) {
                Exchange(vec, i, gt);
                gt--;
            } else {
                i++;
            }
        }
        Sort(vec, lo, lt-1);
        Sort(vec, gt+1, hi);
    }

    void Exchange(vector<T>& vec, int l, int r) {
        int t = vec[l];
        vec[l] = vec[r];
        vec[r] = t;
    }

};

int main() {
    vector<int> vec{33, 42, 6, 33, 2, 70, 1, 10, 40, 20, 33, 70};
    vector<int> vec2{11,2,3,4,5,6,7,8,9,10};
    Solution<int>().QuickSort(vec);
    for(auto e : vec) {
        cout << e << " ";
    }
    cout << endl;
    return 0;
}
