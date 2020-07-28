//
// Created by gjs on 19-1-24.
//

#ifndef ALGORITHMEXERCISE_SINGLETON_H
#define ALGORITHMEXERCISE_SINGLETON_H

#include <mutex>
#include <iostream>
#include <memory>

using namespace std;

class EHanSingleton {
public:
    EHanSingleton(const EHanSingleton&)=delete;
    EHanSingleton& operator=(const EHanSingleton&)=delete;

    static EHanSingleton& GetInstance() {
        static EHanSingleton ehan;
        return ehan;
    }

    ~EHanSingleton(){
        std::cout << "ehan destructor called!" << std::endl;
    }

    void SetValue(int v) {
        num_ = v;
    }

    int GetValue() const {
        return num_;
    }

private:
    EHanSingleton() {
        std::cout << "ehan constructor called!" << std::endl;
    }

    int num_ = 0;
};

/*
class LanHanSingleton {
public:

    LanHanSingleton(const LanHanSingleton&)=delete;
    LanHanSingleton& operator=(const LanHanSingleton&)=delete;

    static std::shared_ptr<LanHanSingleton> GetInstance() {
        if(nullptr == lanhan_) {
            std::lock_guard<std::mutex> lk(mutex_);
//            mutex_.lock();
            if(nullptr == lanhan_) {
                //make_shared 函数模板并非类的友元函数，其访问了私有构造函数，最简单的方法就是用new替代make_shared
//                lanhan_ = std::make_shared<LanHanSingleton>();  //error
                lanhan_ = std::shared_ptr<LanHanSingleton>(new LanHanSingleton);

            }
//            mutex_.unlock();
        }
        return lanhan_;
    }

    ~LanHanSingleton(){
        std::cout << "lanhan destructor called!" << std::endl;
    }

    void SetValue(int v) {
        num_ = v;
    }

    int GetValue() const {
        return num_;
    }

private:
    LanHanSingleton() {
        std::cout << "lanhan constructor called!" << std::endl;
    }

    static std::shared_ptr<LanHanSingleton> lanhan_;

    static std::mutex mutex_;

    int num_ = 0;
};
*/

/*
class LanHanSingleton {
public:

    LanHanSingleton(const LanHanSingleton&)=delete;
    LanHanSingleton& operator=(const LanHanSingleton&)=delete;

    static LanHanSingleton& GetInstance() {
        static LanHanSingleton lanhan;
        return lanhan;
    }

    ~LanHanSingleton(){
        std::cout << "lanhan destructor called!" << std::endl;
    }

    void SetValue(int v) {
        num_ = v;
    }

    int GetValue() const {
        return num_;
    }

private:
    LanHanSingleton() {
        std::cout << "lanhan constructor called!" << std::endl;
    }

    int num_ = 0;
};
*/

#endif //ALGORITHMEXERCISE_SINGLETON_H
