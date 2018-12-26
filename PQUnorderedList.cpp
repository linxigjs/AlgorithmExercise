//
// Created by gjs on 18-10-18.
//

// Priority Queue with unordered list

#include <iostream>
#include <vector>
#include <algorithm>
#include "PriorityQueue.h"

using namespace std;

template <typename T>
struct Node{
    Node(T v) : val_(v), next_(nullptr) {}
    Node(T v, Node* n) : val_(v), next_(n) {}
    Node<T>* next_;
    T val_;
};

template <typename T>
class PQUnorderedList : public PriorityQueue<T> {
public:
    void Insert(T v) {
        Node<T>* create = new Node<T>(v);
        if(!front_)
            front_ = create;
        if(!rear_)
            rear_ = create;
        else {
            rear_->next_ = create;
            rear_ = rear_->next_;
        }
        Print();
    }

    T DeleteMax() {
        int i=0, maxelem = INT32_MIN, maxind = -1;
        Node<T>* p = front_;
        while(p) {
            if(p->val_>maxelem) {
                maxind = i;
                maxelem = p->val_;
            }
            p = p->next_;
            i++;
        }
        p = front_;
        for(i=0; i<maxind-1; i++) {
            p = p->next_;
        }
        T v = p->next_->val_;
        p->next_ = p->next_->next_;
        Print();
        return v;
    };
    bool IsEmpty() {
        if(!front_)
            cout << "list is empty!" << endl;
        return !front_;
    };
    int Size() {
        int i=0;
        Node<T>* p = front_;
        while(p) {
            p = p->next_;
            i++;
        }
        cout << "List size = " << i << endl;
        return i;
    }

    void Print() {
        cout << "elements in PQ: ";
        Node<T>* p = front_;
        while(p) {
            cout << p->val_ << " ";
            p = p->next_;
        }
        cout << endl;
    }

private:
    Node<T>* front_ = nullptr;
    Node<T>* rear_ = nullptr;

private:

};

int main() {
    PQUnorderedList<int> vec;
    vec.Insert(39);
    vec.Insert(349);
    vec.Insert(393);
    vec.Insert(31);
    vec.Insert(19);
    vec.IsEmpty();

    vec.DeleteMax();
    vec.DeleteMax();
    vec.DeleteMax();
    return 0;
}
