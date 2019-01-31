//
// Created by gjs on 19-1-7.
//

#include "ParallelTaskSchedule.h"


int main() {
    EdgeWeightedDigraph task;
    task.ParseTaskDigraph("../jobsPC.txt");

    ParallelTaskSchedule schedule(task);


    cout << endl;

    return 0;
}