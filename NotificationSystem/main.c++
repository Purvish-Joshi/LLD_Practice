#include <string>
#include <memory>
#include <vector>
#include "facade/NotificationFacade.h"
#include "notification/BasicNotification.h"
#include "enums/Preferences.h"
using namespace std;

int main()
{

    BasicNotification notification("The app has been updated");

    NotificationFacade facade;

    vector<Preferences> preferences = {
        Preferences::Email,
        Preferences::Sms,
        Preferences::Push};

    facade.createNotification(&notification, preferences);

    return 0;
}