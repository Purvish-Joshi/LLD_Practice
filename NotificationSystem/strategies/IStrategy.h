#pragma once
#include <iostream>
#include <string>
#include <memory>
using namespace std;

class IStrategy
{
public:
    virtual void send(const string &message) = 0;
    virtual ~IStrategy() = default;
};