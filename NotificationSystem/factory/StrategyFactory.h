#pragma once
#include <memory>
#include "../strategies/IStrategy.h"
#include "../strategies/EmailStrategy.h"
#include "../strategies/SmsStrategy.h"
#include "../strategies/PushStrategy.h"
#include "../enums/Preferences.h"
using namespace std;

class StrategyFactory
{
public:
    unique_ptr<IStrategy> createStrategy(Preferences preference)
    {
        if (preference == Preferences::Email)
        {
            return make_unique<EmailStrategy>();
        }
        if (preference == Preferences::Sms)
        {
            return make_unique<SmsStrategy>();
        }
        else
        {
            return make_unique<PushStrategy>();
        }
    }
};