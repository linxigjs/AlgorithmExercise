//
// Created by gjs on 19-1-17.
//

#ifndef ALGORITHMEXERCISE_EDGE_H
#define ALGORITHMEXERCISE_EDGE_H

#include <iostream>
using namespace std;

class Edge {
public:
    Edge(int v, int w, double wei) : start_(v), end_(w), weight_(wei) {}
    double GetWeight() const {
        return weight_;
    }
    int GetEither() const {
        return start_;
    }
    int GetOther(int v) const {
        if(v == start_)
            return end_;
        else if(v == end_)
            return start_;
        else
            throw(std::logic_error("Inconsistent edge."));
    }
    int CompareTo(const Edge &that) {
        if(weight_ > that.GetWeight())
            return 1;
        else if(weight_ < that.GetWeight())
            return -1;
        else
            return 0;
    }
    friend ostream& operator<<(ostream &output, const Edge &that) {
        output << "(" << that.start_ << ", " << that.end_ << ", " <<that.weight_ << ")" << endl;
        return output;
    }

private:
    int start_=-1, end_=-1;
    double weight_=0.0;
};

#endif //ALGORITHMEXERCISE_EDGE_H
