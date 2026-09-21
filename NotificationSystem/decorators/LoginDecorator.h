#pragma once
#include <iostream>
#include <string>
#include <memory>
#include "NotificationDecorator.h"
#include "../notification/INotification.h"
using namespace std;

class LoginDecorator : public NotificationDecorator
{
public:
    LoginDecorator(unique_ptr<INotification> notification) : NotificationDecorator(move(notification)) {};

    string getContent() override
    {
        string result = notification->getContent();
        cout << "The User is authticated" << endl;
        return result;
    }
};