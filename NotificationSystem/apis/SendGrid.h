#pragma once
#include <iostream>
#include <string>
using namespace std;

class SendGrid
{
public:
    void notifyUser(const string &notification)
    {
        cout << "SendGrid:sending the notification to all subscribed users" << endl;
        cout << notification << endl;
    }
};

