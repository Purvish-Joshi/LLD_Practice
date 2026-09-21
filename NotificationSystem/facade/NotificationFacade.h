#pragma once
#include <string>
#include <memory>
#include <vector>
#include "../service/NotificationService.h"
#include "../event/NotificationEvent.h"
#include "../engine/NotificationEngine.h"
#include "../notification/INotification.h"
#include "../factory/StrategyFactory.h"
#include "../enums/Preferences.h"
using namespace std;

class NotificationFacade
{
private:
    NotificationService *notificationService;
    NotificationEvent *event;
    NotificationEngine *engine;
    StrategyFactory *factory;

public:
    NotificationFacade()
    {
        notificationService = NotificationService::getInstance();
        event = new NotificationEvent();
        engine = new NotificationEngine();
        factory = new StrategyFactory();
    }

    void createNotification(
        INotification *notification,
        const vector<Preferences> &preferences)
    {
        event->add(engine);

        for (const auto &preference : preferences)
        {
            auto strategy = factory->createStrategy(preference);
            engine->addStrategy(std::move(strategy));
        }

        notificationService->sendNotification(notification);
    }

    ~NotificationFacade()
    {
        delete event;
        delete engine;
        delete factory;
    }
};