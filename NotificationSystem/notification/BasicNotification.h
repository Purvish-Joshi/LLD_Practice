#pragma once
#include <iostream>
#include <string>
#include <memory>
#include "INotification.h"
using namespace std;

class BasicNotification : public INotification
{
    string message;

public:
    BasicNotification(const string &message) : message(message) {};

    string getContent() override
    {
        return message;
    }
};