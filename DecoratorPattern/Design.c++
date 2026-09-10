#include <iostream>
#include <memory>
#include <string>
#include <utility>
using namespace std;

class Notification
{
public:
    virtual string send(const string &message) = 0;
    virtual ~Notification() = default;
};

class BasicNotification : public Notification
{
public:
    string send(const string &message) override
    {
        cout << "Sending Notification: " << message << endl;
        return message;
    }
};

class NotificationDecorator : public Notification
{
protected:
    unique_ptr<Notification> notification;

public:
    NotificationDecorator(unique_ptr<Notification> notification) : notification(move(notification))
    {
    }
};

class SmsDecorator : public NotificationDecorator
{
public:
    SmsDecorator(unique_ptr<Notification> notification) : NotificationDecorator(move(notification)) {}

    string send(const string &message) override
    {
        string result = notification->send(message);
        cout << "Sending Sms: " << result << endl;
        return result;
    }
};

class EmailDecorator : public NotificationDecorator
{
public:
    EmailDecorator(unique_ptr<Notification> notification) : NotificationDecorator(move(notification)) {}

    string send(const string &message) override
    {
        string result = notification->send(message);
        cout << "Sending Email: " << result << endl;
        return result;
    }
};

int main()
{
    unique_ptr<Notification> notification = make_unique<BasicNotification>();

    notification = make_unique<SmsDecorator>(move(notification));

    notification = make_unique<EmailDecorator>(move(notification));

    notification->send("Server is down");

    return 0;
}