#include <iostream>
using namespace std;

class Payment
{
public:
    virtual void pay(double value) = 0;
    virtual ~Payment() {};
};

class UpiPayment : public Payment
{
public:
    void pay(double value) override
    {
        cout << "The amount " << value << " has been paid using UPI Payment" << endl;
    }
};

class Card : public Payment
{
public:
    void pay(double value) override
    {
        cout << "The amount " << value << " has been paid using the Card" << endl;
    }
};

class Paypal : public Payment
{
public:
    void pay(double value) override
    {
        cout << "The amount " << value << " has been paid using Paypal" << endl;
    }
};

class PaymentFactory
{
public:
    Payment *create(string &type)
    {
        if (type == "Upi")
        {
            return new UpiPayment();
        }
        else if (type == "Card")
        {
            return new Card();
        }
        else if (type == "Paypal")
        {
            return new Paypal();
        }
        else
        {
            cout << "no such payment method exist" << endl;
            return nullptr;
        }
    }
};

int main()
{
    string type = "Card";

    PaymentFactory *myFactory = new PaymentFactory;

    Payment *method = myFactory->create(type);

    method->pay(500);
}