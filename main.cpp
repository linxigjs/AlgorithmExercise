//
// Created by gjs on 19-1-24.
//

#include <iostream>
#include "Singleton.h"

using namespace std;

EHanSingleton EHanSingleton::ehan_;

//std::shared_ptr<LanHanSingleton> LanHanSingleton::lanhan_ = nullptr;
//std::mutex LanHanSingleton::mutex_;


int main() {
    EHanSingleton& e1 = EHanSingleton::GetInstance();
    e1.SetValue(10);
    EHanSingleton& e2 = EHanSingleton::GetInstance();
    e2.SetValue(22);
    cout << e1.GetValue() << endl;
    cout << e2.GetValue() << endl;

//    std::shared_ptr<LanHanSingleton> e3 = LanHanSingleton::GetInstance();
//    e3->SetValue(10);
//    std::shared_ptr<LanHanSingleton> e4 = LanHanSingleton::GetInstance();
//    e4->SetValue(22);
//    cout << e3->GetValue() << endl;
//    cout << e4->GetValue() << endl;

//    LanHanSingleton& e5 = LanHanSingleton::GetInstance();
//    e5.SetValue(10);
//    LanHanSingleton& e6 = LanHanSingleton::GetInstance();
//    e6.SetValue(22);
//    cout << e5.GetValue() << endl;
//    cout << e6.GetValue() << endl;

    return 0;
}