//
// Created by gjs on 19-1-31.
//

#ifndef ALGORITHMEXERCISE_PARALLELTASKSCHEDULE_H
#define ALGORITHMEXERCISE_PARALLELTASKSCHEDULE_H

#include "AcyclicLP.h"

class ParallelTaskSchedule {
public:
    ParallelTaskSchedule(EdgeWeightedDigraph G) {
        int s = G.GetV()- 2, t = s+1;
        AcyclicLP lp(G, s);
        for(int i=0; i<G.GetV(); i++) {
            cout << i << " : " << lp.DistTo(i) << endl;
        }
        cout << endl;
        for(auto e : lp.GetPathTo(t)) {
            cout << e;
        }
        cout << endl;
    }


private:

};

#endif //ALGORITHMEXERCISE_PARALLELTASKSCHEDULE_H
