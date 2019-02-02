//
// Created by gjs on 19-1-29.
//

#ifndef ALGORITHMEXERCISE_EDGEWEIGHTEDDIGRAPH_H
#define ALGORITHMEXERCISE_EDGEWEIGHTEDDIGRAPH_H

#include "DirectedEdge.h"
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <memory>
#include <deque>

using namespace std;

class EdgeWeightedDigraph {
public:
    EdgeWeightedDigraph() {
        V = 0;
        E = 0;
    }

    EdgeWeightedDigraph(int n) {
        V = n;
        for(int i=0; i<V; i++) {
            vector<shared_ptr<DirectedEdge>> temp;
            adj.emplace_back(temp);
        }
    }

    EdgeWeightedDigraph(string filepath) {
        ifstream infile;
        infile.open(filepath, ios::in);
        int v=0, w=0;
        double weight = 0.0;
        if(infile) {
            string s;
            getline(infile, s);
            V = stoi(s);
            for(int i=0; i<V; i++) {
                vector<shared_ptr<DirectedEdge>> temp;
                adj.emplace_back(temp);
            }
            getline(infile, s);
            while(getline(infile, s)) {
                ParseString(s, v, w, weight);
                AddEdge(v, w, weight);
            }
            infile.close();
        } else {
            cout << "Open file failed." << endl;
        }
        cout << "Graph build done." << endl;
    }

    void ParseTaskDigraph(string filepath) {
        ifstream infile;
        infile.open(filepath, ios::in);
        int edgecnt = 0;
        double weight = 0.0;
        if(infile) {
            string str;
            getline(infile, str);
            int SV = stoi(str);
            int source = 2*SV, goal = 2*SV+1;
            V = 2*SV + 2;
            for(int i=0; i<V; i++) {
                vector<shared_ptr<DirectedEdge>> temp;
                adj.emplace_back(temp);
            }
            while(getline(infile, str)) {
                vector<double> slice;
                ParseString(str, slice);
                AddEdge(edgecnt, edgecnt+SV, slice[0]);
                AddEdge(source, edgecnt, 0.0);
                AddEdge(edgecnt+SV, goal, 0.0);
                for(int i=1; i<slice.size(); i++) {
                    AddEdge(edgecnt+SV, static_cast<int>(slice[i]), 0.0);
                }
                edgecnt++;
            }
            infile.close();
        } else {
            cout << "Open file failed." << endl;
        }
        cout << "Graph build done." << endl;
    }

    int GetV() {
        return V;
    }

    int GetE() {
        return E;
    }

    vector<shared_ptr<DirectedEdge>> GetAdj(int v) {
        return adj[v];
    }

    vector<shared_ptr<DirectedEdge>> GetAllEdges() {
        vector<shared_ptr<DirectedEdge>> edges;
        for(auto e : adj) {
            edges.insert(edges.end(), e.begin(), e.end());
        }
        return edges;
    }

private:
    int ParseString(string str, int &v, int &w, double &weight) {
        string nospace = RemovePreAndLastSpace(str);
        auto begin = nospace.find(' ');
        if(begin == nospace.npos) {
            return stoi(nospace);
        }
        v = stoi(nospace.substr(0, begin));
        auto end = nospace.rfind(' ');
        weight = stod(nospace.substr(end+1, str.size()));
        w = stoi(nospace.substr(begin, end-1));
        return 0;
    }

    int ParseString(string str, vector<double>& slice) {
        string nospace = RemovePreAndLastSpace(str);
//        cout << nospace << endl;
        for(int i=0; i<str.length(); ) {
            auto gap = nospace.find(' ', i+1);
            if(gap != nospace.npos) {
//                cout << " 1-- " << str.substr(i, gap-i) << endl;
                slice.emplace_back(stod(str.substr(i, gap-i)));
                i = gap+1;
            } else {
//                cout << " 2-- " << str.substr(i, str.length()-i) << endl;
                slice.emplace_back(stod(str.substr(i, str.length()-i)));
                break;
            }
        }
        return 0;
    }

    double stod(string num)
    {
        bool minus = false;      //标记是否是负数
        string real = num;       //real表示num的绝对值
        if (num.at(0) == '-')
        {
            minus = true;
            real = num.substr(1, num.size()-1);
        }

        char c;
        int i = 0;
        double result = 0.0 , dec = 10.0;
        bool isDec = false;       //标记是否有小数
        unsigned long size = real.size();
        while(i < size)
        {
            c = real.at(i);
            if (c == '.')
            {//包含小数
                isDec = true;
                i++;
                continue;
            }
            if (!isDec)
            {
                result = result*10 + c - '0';
            }
            else
            {//识别小数点之后都进入这个分支
                result = result + (c - '0')/dec;
                dec *= 10;
            }
            i++;
        }

        if (minus == true) {
            result = -result;
        }

        return result;
    }

    string RemovePreAndLastSpace(const string& str) {
        int length = str.size();
        int i = 0,j = length -1;
        // vc的isspace实现> 256就崩溃
        while(i < length && isspace(str[i] & 0xFF)){i++;}
        while(j >= 0 && isspace(str[j] & 0xFF)){j--;}
        if(j<i) return string();
        return str.substr(i,j-i+1);
    }

public:
    void AddEdge(int v, int w, double weight) {
        adj[v].emplace_back(make_shared<DirectedEdge>(v, w, weight));
        E++;
    }

    void AddEdge(shared_ptr<DirectedEdge> edge) {
        AddEdge(edge->From(), edge->To(), edge->Weight());
    }

private:
    vector<vector<shared_ptr<DirectedEdge>>> adj;
    int V = 0;
    int E = 0;
};

#endif //ALGORITHMEXERCISE_EDGEWEIGHTEDDIGRAPH_H
