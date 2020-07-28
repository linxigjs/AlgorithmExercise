//
// Created by gjs on 19-1-24.
//

#ifndef ALGORITHMEXERCISE_SINGLETON_H
#define ALGORITHMEXERCISE_SINGLETON_H

#include <mutex>
#include <iostream>

using namespace std;

class EHanSingleton {
public:
    EHanSingleton(const EHanSingleton&)=delete;
    EHanSingleton& operator=(const EHanSingleton&)=delete;

    static EHanSingleton& GetInstance() {
        static EHanSingleton ehan;
        return ehan;
    }

    void SetValue(int v) {
        num = v;
    }

    int GetValue() const {
        return num;
    }

private:
    EHanSingleton() {}

    int num = 0;
};

/*
class LanHanSingleton {
public:
    static LanHanSingleton* GetInstance() {
        if(lanhan == nullptr) {
            std::mutex m;
            m.lock();
            if(lanhan == nullptr) {
                cout << "懒汉模式构造" << endl;
                lanhan = new LanHanSingleton();
            }
            m.unlock();
        }
        return lanhan;
    }

    void SetValue(int v) {
        num = v;
    }

    int GetValue() const {
        return num;
    }

private:

    LanHanSingleton() {}

    static LanHanSingleton* lanhan;

    int num = 0;
};
*/

#endif //ALGORITHMEXERCISE_SINGLETON_H
