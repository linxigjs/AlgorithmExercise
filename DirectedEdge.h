//
// Created by gjs on 19-1-29.
//

#ifndef ALGORITHMEXERCISE_DIRECTEDEDGE_H
#define ALGORITHMEXERCISE_DIRECTEDEDGE_H

#include <iostream>
#include <memory>

using namespace std;

class DirectedEdge {
public:
    DirectedEdge(int v, int w, double weight) : v(v), w(w), weight(weight) {}
    int From() {
        return v;
    }
    int To() {
        return w;
    }
    double Weight() {
        return weight;
    }
    friend std::ostream& operator<<(std::ostream& out, std::shared_ptr<DirectedEdge> e) {
        cout << e->v << " " << e->w << " " << e->weight << endl;
    }
    bool operator==(DirectedEdge e) {
        return (v == e.From()) && (w == e.To()) && (weight == e.weight);
    }
    bool operator==(std::shared_ptr<DirectedEdge> e) {
        return (v == e->From()) && (w == e->To()) && (weight == e->weight);
    }

private:
    int v = 0, w = 0;
    double weight = 0.0;
};

#endif //ALGORITHMEXERCISE_DIRECTEDEDGE_H
