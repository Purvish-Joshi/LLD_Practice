#pragma once
#include <iostream>
#include <string>
#include "IAdapter.h"
#include "..\apis\Twilio.h"
using namespace std;

class SmsAdapter : public IAdapter
{
private:
    Twilio t;

public:
    void send(const string &content) override
    {
        t.publish(content);
    }
};