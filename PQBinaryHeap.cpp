//
// Created by gjs on 18-10-18.
//

// Priority Queue with binary heap

#include <iostream>
#include <algorithm>
#include "PriorityQueue.h"

using namespace std;

template <typename T>
class PQBinaryHeap : public PriorityQueue<T> {
public:
    void Insert(T v) {
        vec_.emplace_back(v);
        Swim(vec_.size()-1);
        Print();
    }

    T DeleteMax() {
        if(IsEmpty()) {
//            return -1;
            throw out_of_range("Containner is empty. NO element to delete.");
        }
        T v = vec_.back();
        if(vec_.size() == 2) {
            vec_.pop_back();
        } else {
            Exchange(vec_.size()-1, 1);
            vec_.pop_back();
            Sink(1);
        }
        Print();
        return v;
    };
    bool IsEmpty() {
        if(vec_.size() <= 1)
            cout << "Containner is empty!" << endl;
        return vec_.size() <= 1;
    };
    int Size() {
        cout << "Containner size = " << vec_.size()-1 << endl;
        return vec_.size()-1;
    }

    void Print() {
        cout << "elements in PQ: ";
        if(IsEmpty())
            return;
        for(auto e : vec_)
            cout << e << " ";
        cout << endl;
    }

private:
    vector<T> vec_ = {0};

private:
    void Sink(int ind) {
        while(2*ind < vec_.size()) {
            int j = 2*ind;
            if(j < vec_.size()-1 && vec_[j] < vec_[j+1]) {
                j++;
            }
            if(vec_[j] > vec_[ind]) {
                Exchange(j, ind);
                ind = j;
            } else {
                return;
            }
        }
    }
    void Swim(int ind) {
        while(ind/2 >= 1) {
            int j = ind/2;
            if(vec_[j] < vec_[ind]) {
                Exchange(j, ind);
                ind = j;
            } else {
                return;
            }
        }
    }
    void Exchange(int l, int r) {
        auto ele = vec_[l];
        vec_[l] = vec_[r];
        vec_[r] = ele;
    }
};

int main() {
    PQBinaryHeap<int> vec;
    vec.Insert(39);
    vec.Insert(349);
    vec.Insert(393);
    vec.Insert(31);
    vec.Insert(19);

    vec.Size();

    vec.DeleteMax();
    vec.DeleteMax();
    vec.DeleteMax();
    vec.DeleteMax();
    vec.DeleteMax();

    vec.IsEmpty();

    return 0;
}
