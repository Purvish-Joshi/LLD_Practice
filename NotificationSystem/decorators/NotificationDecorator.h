#pragma once
#include <iostream>
#include <string>
#include <memory>
#include "../notification/INotification.h"
using namespace std;

class NotificationDecorator : public INotification
{
protected:
    unique_ptr<INotification> notification;

public:
    NotificationDecorator(unique_ptr<INotification> notification) : notification(move(notification))
    {
    }
};