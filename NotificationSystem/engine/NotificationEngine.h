#pragma once
#include <string>
#include <memory>
#include <vector>
#include "../strategies/IStrategy.h"
#include "../observers/IObserver.h"
#include <algorithm>
using namespace std;

class NotificationEngine : public IObserver
{
private:
    vector<unique_ptr<IStrategy>> strategies;

public:
    void addStrategy(unique_ptr<IStrategy> strategy)
    {
        strategies.push_back(move(strategy));
    }

    void removeStrategy(IStrategy *strategy)
    {
        strategies.erase(
            remove_if(
                strategies.begin(),
                strategies.end(),
                [strategy](const unique_ptr<IStrategy> &current)
                {
                    return current.get() == strategy;
                }),
            strategies.end());
    }

    void update(const string &message) override
    {
        for (const auto &strategy : strategies)
        {
            strategy->send(message);
        }
    }
};