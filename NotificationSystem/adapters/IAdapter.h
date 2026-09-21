#pragma once
#include <iostream>
#include <string>
#include <memory>
using namespace std;

class IAdapter
{
public:
    virtual void send(const string &content) = 0;
    virtual ~IAdapter() = default;
};