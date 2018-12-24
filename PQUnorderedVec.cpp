//
// Created by gjs on 18-10-18.
//

// Priority Queue with unordered vector

#include <iostream>
#include <vector>
#include <algorithm>
#include "PriorityQueue.h"

using namespace std;

template <typename T>
class PQUnorderedVec : public PriorityQueue<T> {
public:
    void Insert(T v) {
        vec_.emplace_back(v);
        Print();
    }
//    T DeleteMax() {
//        sort(vec_.begin(), vec_.end());
//        T back = vec_.back();
//        vec_.pop_back();
//        cout << "deleted max element is " << back << endl;
//        Print();
//        return back;
//    };
    T DeleteMax() {
        for(int i=1; i<vec_.size(); i++) {
            if(vec_[i] < vec_[i-1]) {
                Exchange(i, i-1);
            }
        }
        T back = vec_.back();
        vec_.pop_back();
        cout << "deleted max element is " << back << endl;
        Print();
        return back;
    };
    bool IsEmpty() {
        return vec_.empty();
    };
    int Size() {
        return vec_.size();
    }
    void Print() {
        cout << "elements in PQ: ";
        for(auto& e : vec_)
            cout << e << " ";
        cout << endl;
    }

private:
    vector<T> vec_;

private:
    void Exchange(int i, int j) {
        auto temp = vec_[i];
        vec_[i] = vec_[j];
        vec_[j] = temp;
    }
};

int main() {
    PQUnorderedVec<int> vec;
    vec.Insert(39);
    vec.Insert(349);
    vec.Insert(393);
    vec.Insert(31);
    vec.Insert(19);

    vec.DeleteMax();
    vec.DeleteMax();
    vec.DeleteMax();
    return 0;
}
