#pragma once
#include <iostream>
#include <string>
#include <memory>
#include "IStrategy.h"
#include "../adapters/IAdapter.h"
#include "../adapters/EmailAdapter.h"
using namespace std;

class EmailStrategy : public IStrategy
{
private:
    unique_ptr<IAdapter> adapter;

public:
    EmailStrategy()
    {
        adapter = make_unique<EmailAdapter>();
    }

    void send(const string &message) override
    {
        adapter->send(message);
    }
};