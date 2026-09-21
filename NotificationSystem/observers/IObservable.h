#pragma once
#include <string>
#include <memory>
#include "IObserver.h"
using namespace std;

class IObservable
{
public:
    virtual void add(IObserver *observer) = 0;
    virtual void remove(IObserver *observer) = 0;
    virtual void notify(const string &message) = 0;
    virtual ~IObservable() = default;
};