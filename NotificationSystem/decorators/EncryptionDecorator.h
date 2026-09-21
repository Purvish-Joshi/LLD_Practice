#pragma once
#include <iostream>
#include <string>
#include <memory>
#include "NotificationDecorator.h"
#include "../notification/INotification.h"
using namespace std;

class EncryptionDecorator : public NotificationDecorator
{
public:
    EncryptionDecorator(unique_ptr<INotification> notification) : NotificationDecorator(move(notification)) {};

    string getContent() override
    {
        string result = notification->getContent();
        cout << "The message has been encrypted" << endl;
        return result;
    }
};