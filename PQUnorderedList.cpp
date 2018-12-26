//
// Created by gjs on 18-10-18.
//

// Priority Queue with unordered list

#include <iostream>
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
        if(!front_ && !rear_) {
            front_ = create;
            rear_ = create;
        } else {
            rear_->next_ = create;
            rear_ = rear_->next_;
        }
        Print();
    }

    T DeleteMax() {
        if(IsEmpty()) {
//            return -1;
            throw out_of_range("List is empty. NO element to delete.");
        }
        int i=0, maxelem = INT32_MIN, maxind = -1;
        Node<T>* p = front_;
        while(p) {
            if(p->val_>maxelem) {
                maxind = i;
                maxelem = p->val_;
                i++;
            }
            p = p->next_;
        }
        T v = -1;
        if(maxind != 0) {
            p = front_;
            for(i=0; i<maxind-1; i++) {
                p = p->next_;
            }
            if(p->next_ == rear_) {
                rear_ = p;
                p->next_ = nullptr;
            } else {
                v = p->next_->val_;
                p->next_ = p->next_->next_;
            }
        } else {
            v = front_->val_;
            if(!front_->next_) {
                front_ = nullptr;
                rear_ = nullptr;
            } else {
                front_ = front_->next_;
            }

        }

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
        if(IsEmpty())
            return;
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
    vec.DeleteMax();
    vec.DeleteMax();
    vec.DeleteMax();

    return 0;
}