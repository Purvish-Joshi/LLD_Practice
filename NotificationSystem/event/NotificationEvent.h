#pragma once
#include <string>
#include <memory>
#include <vector>
#include <algorithm>
#include "../observers/IObservable.h"
#include "../observers/IObserver.h"
#include "../notification/INotification.h"
using namespace std;

class NotificationEvent : public IObservable
{
private:
    vector<IObserver *> observers;
    INotification *currentNotification;
    string message;

public:
    NotificationEvent()
    {
        currentNotification = nullptr;
    }

    void add(IObserver *observer) override
    {
        observers.push_back(observer);
    }

    void remove(IObserver *observer) override
    {
        observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
    }

    void notify(const string &message) override
    {
        for (auto observer : observers)
        {
            observer->update(message);
        }
    }

    void setNotification(INotification *notification)
    {
        if (currentNotification != nullptr)
        {
            delete currentNotification;
        }
        currentNotification = notification;
        message = notification->getContent();
        notify(message);
    }
};