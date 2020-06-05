//
// Created by goujs on 20-6-5.
//

#include "repository.h"

#include <iostream>
#include <thread>
#include <zconf.h>

using namespace std;


void ProduceItem(ItemRepository& repo, int val) {
  unique_lock<mutex> lk(repo.mtx);
  if((repo.produce_index+1) % repo_size == repo.consume_index) {
    std::cout << "Producer is waiting for an empty slot...\n";
    repo.not_full.wait(lk);
  }
  if(-1 != repo.buffer[repo.produce_index]) {
    cerr << "error in produce" << endl;
    return;
  }
  repo.buffer[repo.produce_index++] = val;
  if(repo.produce_index >= repo_size) {
    repo.produce_index = 0;
  }
  repo.not_empty.notify_all();
  lk.unlock();
}

int ConsumeItem(ItemRepository& repo) {
  unique_lock<mutex> lk(repo.mtx);
  if(repo.consume_index == repo.produce_index) {
    std::cout << "Consumer is waiting for items...\n";
    repo.not_empty.wait(lk);
  }
  int data = repo.buffer[repo.consume_index];
  if(-1 == data) {
    cerr << "error in consume" << endl;
    return data;
  }
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
  bool exit = false;
  while(1) {
    sleep(3);
    unique_lock<mutex> lk(repo.produce_count_mtx);
    if(repo.produce_count < kToProduce) {
      ProduceItem(repo, repo.produce_count);
      std::cout << "Producer thread " << std::this_thread::get_id()
                << " is producing the " << repo.produce_count
                << "^th item" << std::endl;
      repo.produce_count++;
    } else {
      exit = true;
    }
    lk.unlock();
    if(exit) {
      break;
    }
  }
  std::cout << "Producer thread " << std::this_thread::get_id()
            << " is exiting..." << std::endl;
}

void ConsumeTask(ItemRepository& repo) {
  bool exit = false;
  while(1) {
    sleep(2);
    unique_lock<mutex> lk(repo.consume_count_mtx);
    if(repo.consume_count < kToProduce) {
      int val = ConsumeItem(repo);
      std::cout << "Consumer thread " << std::this_thread::get_id()
                << " is consuming the " << val
                << "^th item" << std::endl;
      repo.consume_count++;
    } else {
      exit = true;
    }
    lk.unlock();
    if(exit) {
      break;
    }
  }
  std::cout << "Consumer thread " << std::this_thread::get_id()
            << " is exiting..." << std::endl;
}

void InitItemRepository(ItemRepository& repo) {
  repo.buffer = vector<int>(repo_size, -1);
  repo.consume_index = 0;
  repo.produce_index = 0;
  repo.consume_count = 0;
  repo.produce_count = 0;
}

int main()
{
  ItemRepository repo;
  InitItemRepository(repo);
  std::thread producer1(ProduceTask, ref(repo));
  std::thread producer2(ProduceTask, ref(repo));
  std::thread producer3(ProduceTask, ref(repo));
  std::thread producer4(ProduceTask, ref(repo));

  std::thread consumer1(ConsumeTask, ref(repo));
  std::thread consumer2(ConsumeTask, ref(repo));
  std::thread consumer3(ConsumeTask, ref(repo));
  std::thread consumer4(ConsumeTask, ref(repo));


  producer1.join();
  producer2.join();
  producer3.join();
  producer4.join();
  consumer1.join();
  consumer2.join();
  consumer3.join();
  consumer4.join();

  cout << "------- END -------" << endl;

  return 0;
}