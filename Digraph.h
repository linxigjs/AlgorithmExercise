//
// Created by gjs on 19-1-10.
//

#ifndef ALGORITHMEXERCISE_DIGRAPH_H
#define ALGORITHMEXERCISE_DIGRAPH_H

#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

class Digraph {
private:
    vector<vector<int>> adj_;
    int V_ = 0, E_ = 0;
public:
    Digraph(int n) {
        V_ = n;
        E_ = 0;
        for(int i=0; i<V_; i++) {
            vector<int> temp;
            adj_.emplace_back(temp);
        }
    }
    Digraph(string filepath) {
        ifstream infile;
        infile.open(filepath, ios::in);
        vector<int> vec;
        if(infile) {
            string s;
            while(getline(infile, s)) {
//                cout << s << endl;
                ParseString(s, vec);
            }
            infile.close();
        } else {
            cout << "Open file failed." << endl;
        }
//        for(auto e : vec) {
//            cout << e << " ";
//        }
//        cout << endl;
        if(!vec.empty()) {
            V_ = vec[0];
            for(int i=0; i<V_; i++) {
                vector<int> temp;
                adj_.emplace_back(temp);
            }
            for(int i=1; i<vec.size()-1; i+=2) {
                AddEdge(vec[i], vec[i+1]);
            }
        }
        cout << "Graph build done." << endl;
    }
    vector<int> Adj(int v) const {
        return adj_[v];
    }
    int GetV() const {
        return V_;
    };
    int GetE() const {
        return E_;
    };
    Digraph Reverse() const {
        Digraph r = Digraph(V_);
        for(int i=0; i<V_; i++) {
            for(int w : Adj(i))
                r.AddEdge(w, i);
        }
        return r;
    }

private:
    void ParseString(string str, vector<int> &vec) {
        str += ' ';
        vector<int> temp;
        for(int i=0; i<str.size(); i++) {
            int num = 0;
            if(str[i] >= '0' && str[i] <= '9') {
                temp.emplace_back(static_cast<int>(str[i] - '0'));
            } else if(!temp.empty()) {
                if(temp.size() == 1) {
                    num = temp[0];
                } else {
                    for(int j=0; j<temp.size(); j++) {
                        num = temp[j] + num*10;
                    }
                }
                temp.clear();
                vec.emplace_back(num);
            }
        }
    }
    void AddEdge(int v, int w) {
        if(find(adj_[v].begin(), adj_[v].end(), w) == adj_[v].end()) {
            adj_[v].emplace_back(w);
            E_++;
        }
    }
};

#endif //ALGORITHMEXERCISE_DIGRAPH_H
