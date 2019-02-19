//
// Created by gjs on 19-1-30.
//

#ifndef ALGORITHMEXERCISE_ACYCLICSP_H
#define ALGORITHMEXERCISE_ACYCLICSP_H

#include <cfloat>
#include "Topological.h"

class Shorter {
public:
    Shorter(EdgeWeightedDigraph G, int s) {
        source = s;
        srcmap = G;
        Topological topo(G, s);
        shortest_distto.assign(G.GetV(), DBL_MAX);
        shortest_edgeto.assign(G.GetV(), nullptr);
        shortest_distto[s] = 0.0;
        for(int v : topo.GetTopologicalOrder()) {
            Relax(G, v);
        }
    }

    bool HasPathTo(int t) {
        return shortest_distto[t] != DBL_MAX;
    }

    vector<shared_ptr<DirectedEdge>> GetShortestPathTo(int t) {
        vector<shared_ptr<DirectedEdge>> result;
        if(!HasPathTo(t)) {
//            throw logic_error("Has No Path To input Node");
            return result;
        }
        for(auto edge = shortest_edgeto[t]; edge != nullptr; edge = shortest_edgeto[edge->From()]) {
            result.emplace_back(edge);
        }
        reverse(result.begin(), result.end());
        return result;
    }

    vector<shared_ptr<DirectedEdge>> GetShorterPathTo(int t) {
        double res = DBL_MAX;
        vector<shared_ptr<DirectedEdge>> shorter_path, temp;
        auto shortest_path = GetShortestPathTo(t);
        if(shortest_path.empty()) {
            cout << "没有找到最短路径" << endl;
            return shorter_path;
        }
        for(auto e : shortest_path) {
            shortermap = srcmap;
            shortermap.RemoveEdge(e);
            auto ser = Shorter(shortermap, source);
            temp = ser.GetShortestPathTo(t);
            if(temp.empty()) {
                cout << "暂时没有找到最短路径" << endl;
                continue;
            }
            if(ser.DistTo(t) > DistTo(t) && ser.DistTo(t) < res) {
                res = ser.DistTo(t);
                shorter_path = temp;
            }
        }
        cout << "最短路径长度：" << DistTo(t) << endl;
        cout << "次短路径长度：" << res << endl;
        return shorter_path;
    }

    double DistTo(int t) {
        return shortest_distto[t];
    }

private:
    int source, goal;
    vector<double> shortest_distto, shorter_distto;
    vector<shared_ptr<DirectedEdge>> shortest_edgeto, shorter_edgeto, temp_edgeto;
    EdgeWeightedDigraph srcmap, shortermap;

    
    void Relax(EdgeWeightedDigraph G, int v) {
        for(auto e : G.GetAdj(v)) {
            int w = e->To();
            if(shortest_distto[w] > shortest_distto[v] + e->Weight()) {
                shortest_distto[w] = shortest_distto[v] + e->Weight();
                shortest_edgeto[w] = e;
            }
        }
    }
};

#endif //ALGORITHMEXERCISE_ACYCLICSP_H
