#pragma once
#include <iostream>
#include <string>
using namespace std;

class FireBase
{
public:
    void insert(const string &notification)
    {
        cout << "FireBase:Pushing the notification to database" << endl;
        cout << notification << endl;
    }
};