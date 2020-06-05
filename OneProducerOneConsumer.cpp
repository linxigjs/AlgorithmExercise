//
// Created by gjs on 19-1-24.
//

#include <iostream>
#include <zconf.h>
#include <thread>
#include "repository.h"

using namespace std;

void ProduceItem(ItemRepository& repo, int val) {
  unique_lock<mutex> lk(repo.mtx);
  while((repo.produce_index+1)%repo_size == repo.consume_index) {
    std::cout << "Producer is waiting for an empty slot...\n";
    repo.not_full.wait(lk);
  }
  repo.buffer[repo.produce_index++] = val;
  if(repo.produce_index >= repo_size) {
    repo.produce_index = 0;
  }
  repo.not_empty.notify_all();
  lk.unlock();
}

int ConsumeItem(ItemRepository& repo) {
  int data;
  unique_lock<mutex> lk(repo.mtx);
  while(repo.produce_index == repo.consume_index) {
    std::cout << "Consumer is waiting for items...\n";
    repo.not_empty.wait(lk);
  }
  data = repo.buffer[repo.consume_index];
  repo.buffer[repo.consume_index] = -1;
  repo.consume_index++;
  if(repo.consume_index >= repo_size) {
    repo.consume_index = 0;
  }
  repo.not_full.notify_all();
  lk.unlock();
  return data;
}

void ProduceTask(ItemRepository& repo) {
  for(int i=0; i<kToProduce; i++) {
    sleep(1);
    std::cout << "Produce the " << i << "^th item..." << std::endl;
    ProduceItem(repo, i);
  }
}

void ConsumeTask(ItemRepository& repo) {
  int cnt=0;
  while(1) {
    cnt++;
    sleep(2);
    int val = ConsumeItem(repo);
    std::cout << "Consume the " << val << "^th item" << std::endl;
    if(cnt == kToProduce) {
      break;
    }
  }
}

void InitItemRepository(ItemRepository& repo) {
  repo.buffer = vector<int>(repo_size, -1);
  repo.consume_index = 0;
  repo.produce_index = 0;
}

int main() {
  ItemRepository repo;
  InitItemRepository(repo);

  std::thread producer(ProduceTask, ref(repo));
  std::thread consumer(ConsumeTask, ref(repo));

  producer.join();
  consumer.join();

  cout << "------- END -------" << endl;

  return 0;
}