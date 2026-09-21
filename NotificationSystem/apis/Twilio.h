#pragma once
#include <iostream>
#include <string>
using namespace std;

class Twilio
{
public:
    void publish(const string &notification)
    {
        cout << "Twilio:Publising the notification" << endl;
        cout << notification << endl;
    }
};