//
// Created by gjs on 18-12-24.
//

#ifndef ALGORITHMEXERCISE_PRIORITYQUEUE_H
#define ALGORITHMEXERCISE_PRIORITYQUEUE_H

template <typename T>
class PriorityQueue {
public:
    virtual void Insert(T v) = 0;
    virtual T DeleteMax() = 0;
    virtual bool IsEmpty() = 0;
    virtual int Size() = 0;
    virtual void Print() = 0;
};

#endif //ALGORITHMEXERCISE_PRIORITYQUEUE_H
