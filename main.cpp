//
// Created by gjs on 18-10-18.
//

// Top-down merge sort + insert sort when array is small

#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class Solution {
public:
    Solution() {}
    void Sort(vector<T> &vec) {
        temp = vec;
        Sort(vec, 0, vec.size()-1);
//        InsertSort2(vec, 0, vec.size()-1);
    }
private:
    void Sort(vector<T> &vec, int lo, int hi) {
        if(lo >= hi)
            return;
        int mid = (lo+hi) / 2;
        Sort(vec, lo, mid);
        Sort(vec, mid+1, hi);
        if(vec[mid] > vec[mid+1])
            Merge(vec, lo, mid, hi);
    }
    void InsertSort(vector<T> &vec, int lo, int hi) {
        for(int i=lo+1; i<=hi; i++) {
            for(int j=i-1; j>=lo; j--) {
                if(vec[j] > vec[j+1]) {
                    int tt = vec[j+1];
                    vec[j+1] = vec[j];
                    vec[j] = tt;
                }
            }
        }
    }
    void InsertSort2(vector<T> &vec, int lo, int hi) {
        for(int i=lo+1; i<=hi; i++) {
            int tt = vec[i], j=i-1;
            while(j>=lo && vec[j] > tt) {
                vec[j+1] = vec[j];
                j--;
            }
            vec[j+1] = tt;
        }
    }
    void Merge(vector<T> &vec, int lo, int mid, int hi) {
        if(hi - lo < 5) {
            InsertSort(vec, lo, hi);
            return;
        }
        for(int i=lo; i<=hi; i++) {
            temp[i] = vec[i];
        }
        int i=lo, j=mid+1;
        for(int k=lo; k<=hi; k++) {
            if(i>mid)
                vec[k] = temp[j++];
            else if(j>hi)
                vec[k] = temp[i++];
            else if(temp[i] < temp[j])
                vec[k] = temp[i++];
            else
                vec[k] = temp[j++];
        }
    }
    vector<T> temp;
};

int main() {
    vector<int> vec{100, 4, 6, 3, 2, 7, 1, 23, 14, 46, 90, 24, 54, 46, 20};
    Solution<int>().Sort(vec);
    cout << endl << "result : " << endl;
    for(auto e : vec) {
        cout << e << " ";
    }
    cout << endl;
    return 0;
}
