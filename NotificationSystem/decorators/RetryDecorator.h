#pragma once
#include <iostream>
#include <string>
#include <memory>
#include "NotificationDecorator.h"
#include "../notification/INotification.h"
using namespace std;

class RetryDecorator : public NotificationDecorator
{
public:
    RetryDecorator(unique_ptr<INotification> notification) : NotificationDecorator(move(notification)) {};

    string getContent() override
    {
        string result = notification->getContent();
        cout << "Notifying the user again due to some error" << endl;
        return result;
    }
};