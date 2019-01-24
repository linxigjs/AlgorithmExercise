//
// Created by gjs on 19-1-24.
//

#include <iostream>
#include "Singleton.h"

using namespace std;

int main() {
    EHanSingleton *e1 = EHanSingleton::GetInstance();
    e1->SetValue(100);

    EHanSingleton *e2 = EHanSingleton::GetInstance();
    e2->SetValue(220);

    cout << e1->GetValue() << endl;
    cout << e2->GetValue() << endl;

    LanHanSingleton *e3 = LanHanSingleton::GetInstance();
    e3->SetValue(10);

    LanHanSingleton *e4 = LanHanSingleton::GetInstance();
    e4->SetValue(22);

    cout << e3->GetValue() << endl;
    cout << e4->GetValue() << endl;

    return 0;
}