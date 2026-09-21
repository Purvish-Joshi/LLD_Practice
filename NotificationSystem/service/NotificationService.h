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
    static NotificationService *instance;
    NotificationEvent *event;

    NotificationService() = default;

public:
    static NotificationService *getInstance()
    {
        if (instance == nullptr)
        {
            instance = new NotificationService();
        }
        return instance;
    }
    void sendNotification(INotification *notification)
    {
        notifications.push_back(notification);
        event->setNotification(notification);
    }
};

NotificationService *NotificationService::instance = nullptr;