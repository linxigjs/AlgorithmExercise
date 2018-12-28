//
// Created by gjs on 18-12-28.
//

#include <iostream>
#include <vector>

using namespace std;

typedef int KEY;
typedef int RANK;
typedef string VALUE;

class Node {
public:
    Node() : key_(-1), value_(""), left_(nullptr), right_(nullptr), N_(-1) {}
    Node(KEY k, VALUE v, int n) : key_(k), value_(v), left_(nullptr), right_(nullptr), N_(n) {}
    Node(KEY k, VALUE v, Node *l, Node *r, int n) : key_(k), value_(v), left_(l), right_(r), N_(n) {}
    KEY key_;
    VALUE value_;
    Node *left_, *right_;
    int N_;
};

class BinarySearchTree {
public:
    VALUE Get(KEY k) {
        auto p = root_;
        while(1) {
            if(p->key_ < k) {
                if(!p->right_) {
                    cout << "No element = k" << endl;
                    break;
                } else {
                    p = p->right_;
                }
            } else if(p->key_ > k){
                if(!p->left_) {
                    cout << "No element = k" << endl;
                    break;
                } else {
                    p = p->left_;
                }
            } else {
                return p->value_;
            }
        }
    }
    void Put(KEY k, VALUE v) {
        if(IsRootNull()) {
            root_ = new Node(k, v, 1);
            return;
        }
        auto p = root_;
        while(1) {
            if(p->key_ < k) {
                if(!p->right_) {
                    p->right_ = new Node(k, v, 1);
                    return;
                } else {
                    p = p->right_;
                }
            } else if(p->key_ > k){
                if(!p->left_) {
                    p->left_ = new Node(k, v, 1);
                    return;
                } else {
                    p = p->left_;
                }
            } else {
                p->value_ = v;
                return;
            }
        }
    }
    KEY Min() {
        if(IsRootNull())
            return -1;
        auto p = root_;
        while(1) {

        }
    }

    void DeleteMin() {
        if(IsRootNull())
            return;
    }
    void Delete(KEY k) {
        if(IsRootNull())
            return;
    }

    void MediumOrderPrint() {
        cout << "MediumOrderPrint:" << endl;
        if(IsRootNull()) {
            return;
        }
        auto p = root_;
        vector<Node *> stack;
        while(p || !stack.empty()) {
            if(p) {
                stack.emplace_back(p);
                p = p->left_;
            } else {
                p = stack.back();
                cout << p->value_ << " " << endl;
                stack.pop_back();
                p = p->right_;
            }
        }
        cout << endl;
    }

private:
    bool IsRootNull() {
        if(!root_) {
            cout << "Tree is empty!!!" << endl;
            return true;
        }
        return false;
    }
    Node *root_ = nullptr;
};



int main() {
//    Node* myroot = new Node(2, "abc", 1);
    BinarySearchTree mytree;
    mytree.Put(3, "3");
    mytree.Put(33, "33");
    mytree.Put(23, "23");
    mytree.Put(13, "13");
    mytree.Put(43, "43");

    mytree.MediumOrderPrint();
    cout << mytree.Get(33) << endl;

//    cout << mytree.Min() << endl;
//    mytree.DeleteMin();
//    mytree.MediumOrderPrint();
//    cout << mytree.Min() << endl;
//    mytree.Delete(43);
//    mytree.MediumOrderPrint();


    return 0;
}