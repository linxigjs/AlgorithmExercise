//
// Created by gjs on 18-10-18.
//

// quick sort and insert sort

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <typename T>
class Solution {
public:
    void QuickSort(vector<T>& vec) {
        random_shuffle(vec.begin(), vec.end());
        Sort(vec, 0, vec.size()-1);
//        InsertSort(vec, 0, vec.size()-1);
    }
private:
    void Sort(vector<T>& vec, int lo, int hi) {
        if(lo >= hi)
            return;
        if(hi-lo < 5) {
            InsertSort(vec, lo, hi);
            return;
        }
        int j = Partition(vec, lo, hi);
        Sort(vec, lo, j-1);
        Sort(vec, j+1, hi);
    }
    int Partition(vector<T>& vec, int lo, int hi) {
        int i=lo, j=hi+1, v=vec[lo];
        while(1) {
            while(vec[++i] < v && i<=hi) {
                ;
            }
            while(vec[--j] > v && j>lo) {
                ;
            }
            if(i >= j)
                break;
            Exchange(vec, i, j);
        }
        Exchange(vec, lo, j);
        return j;
    }
    void Exchange(vector<T>& vec, int l, int r) {
        int t = vec[l];
        vec[l] = vec[r];
        vec[r] = t;
    }
    void InsertSort(vector<T>& vec, int lo, int hi) {
        for(int i=lo+1; i<=hi; i++) {
            for(int j=i-1; j>=lo; j--) {
                if(vec[j] > vec[j+1]) {
                    Exchange(vec, j, j+1);
                }
            }
        }
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
