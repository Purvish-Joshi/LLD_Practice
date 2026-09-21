#pragma once
#include <string>
#include <memory>
#include <vector>
#include <algorithm>
#include "../notification/INotification.h"
#include "../event/NotificationEvent.h"
using namespace std;

class NotificationService
{
private:
    vector<INotification *> notifications;
    NotificationEvent *event = nullptr;

    NotificationService() = default;

public:
    static NotificationService *getInstance()
    {
        static NotificationService instance;
        return &instance;
    }

    void setEvent(NotificationEvent *event)
    {
        this->event = event;
    }

    void sendNotification(INotification *notification)
    {
        notifications.push_back(notification);
        event->setNotification(notification);
    }
};