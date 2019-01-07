//
// Created by gjs on 19-1-7.
//

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

class Graph {
private:
    int V_ = -1;
    int E_ = -1;
    vector<vector<int>> adj_;
public:
    Graph(int v) {
        V_ = v;
        E_ = 0;
        for(int i=0; i<V_; i++) {
            vector<int> temp;
            adj_.emplace_back(temp);
        }
    }
    Graph(string filepath) {
        ifstream infile;
        infile.open(filepath, ios::in);
        vector<int> vec;
        if(infile) {
            string s;
            while(getline(infile, s)) {
                cout << s << endl;
                ParseString(s, vec);
            }
            infile.close();
        } else {
            cout << "Open file failed." << endl;
        }
        for(auto e : vec) {
            cout << e << " ";
        }
        cout << endl;
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
    }
    vector<int> Adj(int v) {
        return adj_[v];
    }
    int GetV() const {
        return V_;
    }
    int GetE() const {
        return E_;
    }
private:
    void AddEdge(int l, int r) {
        E_++;

        adj_[l].emplace_back(r);
    }
    void ParseString(string str, vector<int> &vec) {
        vector<int> temp;
        for(int i=0; i<str.size(); i++) {
            int num = 0;
            if(str[i] >= '0' && str[i] <= '9') {
                temp.emplace_back(static_cast<int>(str[i] - '0'));
            }
            if(!temp.empty() && (str[i] == ' ' || str[i] == '\n')) {
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
};

