#pragma once
#include <iostream>
#include <string>
#include <memory>
using namespace std;

class INotification
{
public:
    virtual string getContent() = 0;
    virtual ~INotification() = default;
};