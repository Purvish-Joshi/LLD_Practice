#pragma once
#include <iostream>
#include <string>
#include <memory>
#include "IStrategy.h"
#include "../adapters/IAdapter.h"
#include "../adapters/SmsAdapter.h"
using namespace std;

class SmsStrategy : public IStrategy
{
private:
    unique_ptr<IAdapter> adapter;

public:
    SmsStrategy()
    {
        adapter = make_unique<SmsAdapter>();
    }

    void send(const string &message) override
    {
        adapter->send(message);
    }
};