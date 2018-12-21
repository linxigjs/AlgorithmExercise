//
// Created by gjs on 18-10-18.
//

//自底向上的归并排序

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void GBSort(vector<int>& vec) {
        temp = vec;
        int len = vec.size();
        for(int sz=1; sz<len; sz *= 2) {
            for(int lo=0; lo<len-sz; lo += 2*sz) {
                Merge(vec, lo, lo+sz-1, min(len-1, lo+2*sz-1));
            }
        }
    }
private:
    void Merge(vector<int>& vec, int lo, int mid, int hi) {
        if(lo >= hi)
            return;
        if(vec[mid] <= vec[mid+1])
            return;
        for(int i=lo; i<=hi; i++)
            temp[i] = vec[i];
        int i=lo, j=mid+1;
        for(int k=lo; k<=hi; k++) {
            if(i>mid)
                vec[k] = temp[j++];
            else if(j>hi)
                vec[k] = temp[i++];
            else if(temp[i] > temp[j])
                vec[k] = temp[j++];
            else
                vec[k] = temp[i++];
        }
    }
    vector<int> temp;
};

int main() {
    vector<int> vec{100, 4, 23, 14, 46, 90, 24, 54, 46, 20};
    Solution().GBSort(vec);
    cout << endl << "result : " << endl;
    for(auto e : vec) {
        cout << e << " ";
    }
    cout << endl;
    return 0;
}
