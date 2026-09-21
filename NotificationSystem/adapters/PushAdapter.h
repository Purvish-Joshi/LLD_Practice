#pragma once
#include <iostream>
#include <string>
#include "IAdapter.h"
#include "..\apis\FireBase.h"
using namespace std;

class PushAdapter : public IAdapter
{
private:
    FireBase fb;

public:
    void send(const string &content) override
    {
        fb.insert(content);
    }
};