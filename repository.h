#ifndef REPOSITORY_H_
#define REPOSITORY_H_

#include <vector>
#include <condition_variable>

using namespace std;

const int kToProduce = 11, repo_size = 4;


struct ItemRepository {
    //for OneProducerOneConsumer
    vector<int> buffer;
    condition_variable not_full, not_empty;
    mutex mtx, ano;
    int produce_index = 0, consume_index = 0;

    //for OneProducerManyConsumers
    mutex consume_count_mtx;
    int consume_count = 0;
};

#endif