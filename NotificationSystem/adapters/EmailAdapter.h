#pragma once
#include <iostream>
#include <string>
#include "IAdapter.h"
#include "..\apis\SendGrid.h"
using namespace std;

class EmailAdapter : public IAdapter
{
private:
    SendGrid sg;

public:
    void send(const string &content) override
    {
        sg.notifyUser(content);
    }
};