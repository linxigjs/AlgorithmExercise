//
// Created by gjs on 19-1-24.
//

#include "Singleton.h"

EHanSingleton* EHanSingleton::ehan = new EHanSingleton();

//LanHanSingleton* LanHanSingleton::lanhan = new LanHanSingleton();     //这样就成饿汉了，懒汉是需要时才实例化
LanHanSingleton* LanHanSingleton::lanhan = nullptr;