#pragma once
#include <string>
#include <memory>
using namespace std;

class IObserver
{
public:
    virtual void update(const string &message) = 0;
    virtual ~IObserver() = default;
};