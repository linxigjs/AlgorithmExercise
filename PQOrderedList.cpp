//
// Created by gjs on 18-10-18.
//

// Priority Queue with ordered list

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
class PQOrderedList : public PriorityQueue<T> {
public:
    void Insert(T v) {
        Node<T>* create = new Node<T>(v);
        if(!front_ && !rear_) {
            front_ = create;
            rear_ = create;
        } else {
            if(front_->val_ < v) {
                create->next_ = front_;
                front_ = create;
            } else {
                auto p = front_, last = front_;
                while(p && p->val_ > v) {
                    last = p;
                    p = p->next_;
                }
                if(!p) {
                    last->next_ = create;
                    rear_ = create;
                } else {
                    last->next_ = create;
                    create->next_ = p;
                }
            }
        }
        Print();
    }

    T DeleteMax() {
        if(IsEmpty()) {
//            return -1;
            throw out_of_range("List is empty. NO element to delete.");
        }
        T v = front_->val_;
        if(!front_->next_) {
            front_ = nullptr;
            rear_ = nullptr;
        } else {
            front_ = front_->next_;
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
    PQOrderedList<int> vec;
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
