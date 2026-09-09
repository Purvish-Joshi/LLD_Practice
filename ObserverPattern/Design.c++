#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class StockObserver
{
public:
    virtual void update(const string &status) = 0;
    virtual ~StockObserver() = default;
};

class EmailObserver : public StockObserver
{
public:
    void update(const string &status) override
    {
        cout << "Email:" << status << endl;
    }
};

class MobileObserver : public StockObserver
{
public:
    void update(const string &status) override
    {
        cout << "Mobile:" << status << endl;
    }
};

class LoggerObserver : public StockObserver
{
public:
    void update(const string &status) override
    {
        cout << "Logger:" << status << endl;
    }
};

class Stock
{
private:
    vector<StockObserver *> Observers;
    string name;
    double price;

public:
    Stock(const string &name) : name(name) {}

    void attach(StockObserver *Observer)
    {
        Observers.push_back(Observer);
    }

    void detach(StockObserver *Observer)
    {
        auto it = find(Observers.begin(), Observers.end(), Observer);

        if (it != Observers.end())
            Observers.erase(it);
    }

    void notify(const string &status)
    {
        for (auto Observer : Observers)
        {
            Observer->update(status);
        }
    }

    void setPrice(double newPrice)
    {
        if (price == newPrice)
            return;

        price = newPrice;
        if (price < 1000)
        {
            notify("the price is low");
        }
        else
        {
            notify("the price is high");
        }
    }
};

int main()
{
    Stock stock("AAPL");

    MobileObserver mobile;
    EmailObserver email;

    stock.attach(&mobile);
    stock.attach(&email);

    stock.setPrice(2000);

    stock.detach(&email);

    stock.setPrice(500);

    return 0;
}