//
// Created by gjs on 18-12-28.
//

#include <iostream>

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
    int Size() {
        return Size(root_);
    }
    VALUE Get(KEY k) {
        return Get(root_, k);
    }
    void Put(KEY k, VALUE v) {
        root_ = Put(root_, k, v);
    }
    KEY Min() {
        if(IsRootNull())
            return -1;
        return Min(root_)->key_;
    }
    KEY Max() {
        if(IsRootNull())
            return -1;
        return Max(root_)->key_;
    }
    KEY Floor(KEY k) {
        if(IsRootNull())
            return -1;
        Node* node = Floor(root_, k);
        if(!node)
            return -1;
        return node->key_;
    }
    KEY Select(RANK k) {
        if(IsRootNull() || k >= root_->N_)
            return -1;
        return Select(root_, k)->key_;
    }
    RANK Rank(KEY k) {
        if(IsRootNull())
            return 0;
        return Rank(root_, k);
    }
    void DeleteMin() {
        if(IsRootNull())
            return;
        root_ = DeleteMin(root_);
    }
    void Delete(KEY k) {
        if(IsRootNull())
            return;
        root_ = Delete(root_, k);
    }

    void MediumOrderPrint() {
        cout << "MediumOrderPrint:" << endl;
        if(IsRootNull()) {
            return;
        }
        Print(root_);
        cout << endl;
    }

    void RangePrint(KEY lo, KEY hi) {
        cout << "RangePrint:" << endl;
        if(IsRootNull()) {
            cout << " ";
            return;
        }
        RangePrint(root_, lo, hi);
        cout << endl;
    }

private:
    void RangePrint(Node* node, KEY lo, KEY hi) {
        if(!node) {
            cout << " ";
            return;
        }
        if(node->key_ > lo) {
            RangePrint(node->left_, lo, hi);
        }
        if(node->key_ < hi) {
            RangePrint(node->right_, lo, hi);
        }
        if(node->key_ >= lo && node->key_ <= hi) {
            cout << " " << node->key_ << " ";
        }

    }
    void Print(Node* node) {
        if(!node)
            return;
        Print(node->left_);
        cout << " " << node->value_ << " ";
        Print(node->right_);
    }
    Node* Delete(Node* node, KEY k) {
        if(node->key_ > k) {
            node->left_ = Delete(node->left_, k);
        } else if(node->key_ < k) {
            node->right_ = Delete(node->right_, k);
        } else {
            if(!node->left_) {
                return node->right_;
            }
            if(!node->right_) {
                return node->left_;
            }
            auto temp = node;
            node = Min(node->right_);
            node->right_ = DeleteMin(node->right_);
            node->left_ = temp->left_;
        }
        node->N_ = Size(node->left_) + Size(node->right_) + 1;
        return node;
    }
    Node* DeleteMin(Node* node) {
        if(!node->left_) {
            return node->right_;
        }
        node->left_ = DeleteMin(node->left_);
        node->N_ = Size(node->left_) + 1 + Size(node->right_);
        return node;
    }
    RANK Rank(Node* node, KEY k) {
        if(!node)
            return 0;
        if(k < node->key_) {
            return Rank(node->left_, k);
        } else if(k > node->key_) {
            return 1 + Size(node->left_) + Rank(node->right_, k);
        } else {
            return Size(node->left_);
        }
    }
    Node* Max(Node* node) {
        if(!node->right_)
            return node;
        else
            return Max(node->right_);
    }
    bool IsRootNull() {
        if(!root_) {
            cout << "Tree is empty!!!" << endl;
            return true;
        }
        return false;
    }
    int Size(Node *ro) {
        if(!ro)
            return 0;
        return ro->N_;
    }
    VALUE Get(Node *node, KEY k) {
        if(!node)
            return nullptr;
        if(node->key_ < k) {
            return Get(node->right_, k);
        } else if(node->key_ > k) {
            return Get(node->left_, k);
        } else {
            return node->value_;
        }
    }
    Node* Put(Node *node, KEY k, VALUE v) {
        if(!node) {
            return new Node(k, v, 1);
        }
        if(node->key_ < k) {
            node->right_ = Put(node->right_, k, v);
        } else if(node->key_ > k) {
            node->left_ = Put(node->left_, k, v);
        } else {
            node->value_ = v;
        }
        //无论有没有插入新节点，下一句都可以正确执行
        node->N_ = Size(node->left_) + Size(node->right_) + 1;
        return node;
    }
    Node* Min(Node* node) {
        if(!node->left_) {
            return node;
        }
        return Min(node->left_);
    }
    Node* Floor(Node* node, KEY k) {
        if(!node)
            return nullptr;
        if(node->key_ == k) {
            return node;
        } else if(node->key_ > k) {
            return Floor(node->left_, k);
        } else {
            auto temp = Floor(node->right_, k);
            if(!temp)
                return node;
            else
                return temp;
        }
    }
    Node* Select(Node* node, RANK k) {
        if(!node)
            return nullptr;
        int temp = Size(node->left_);
        if(k > temp) {
            return Select(node->right_, k-temp-1);
        } else if(k < temp) {
            return Select(node->left_, k);
        } else {
            return node;
        }
    }
private:
    Node *root_ = nullptr;
};



int main() {
//    Node* myroot = new Node(2, "abc", 1);
    BinarySearchTree mytree;
    mytree.Put(3, "a");
    cout << mytree.Get(3) << endl;
    mytree.Put(33, "g");
    mytree.Put(23, "h");
    mytree.Put(13, "e");
    mytree.Put(43, "t");
    mytree.RangePrint(20,40);
    mytree.MediumOrderPrint();
    cout << mytree.Rank(55) << endl;
    cout << mytree.Floor(30) << endl;
    cout << mytree.Max() << endl;

    cout << mytree.Min() << endl;
    mytree.DeleteMin();
    mytree.MediumOrderPrint();
    cout << mytree.Min() << endl;
    mytree.Delete(43);
    mytree.MediumOrderPrint();
    cout << mytree.Max() << endl;
    cout << mytree.Select(0) << endl;

    return 0;
}