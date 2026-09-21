#pragma once
#include <iostream>
#include <string>
#include <memory>
#include "IStrategy.h"
#include "../adapters/IAdapter.h"
#include "../adapters/PushAdapter.h"
using namespace std;

class PushStrategy : public IStrategy
{
private:
     unique_ptr<IAdapter> adapter;

public:
      PushStrategy()
    {
        adapter = make_unique<PushAdapter>();
    }

    void send(const string &message) override
    {
        adapter->send(message);
    }
};