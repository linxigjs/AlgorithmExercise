//
// Created by gjs on 19-1-29.
//

#ifndef ALGORITHMEXERCISE_DIRECTEDEDGE_H
#define ALGORITHMEXERCISE_DIRECTEDEDGE_H

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

private:
    int v = 0, w = 0;
    double weight = 0.0;
};

#endif //ALGORITHMEXERCISE_DIRECTEDEDGE_H
