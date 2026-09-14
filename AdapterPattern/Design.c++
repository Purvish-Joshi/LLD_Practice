#include <iostream>
#include <memory>
using namespace std;

class PaymentProcessor
{
public:
    virtual void pay(int amount) = 0;
    virtual ~PaymentProcessor() = default;
};

class RazorPay
{
public:
    void makePayment(int amount)
    {
        cout << "Payment of " << amount
             << " made using Razorpay" << endl;
    }
};

class Paypal
{
public:
    void sendPayment(int amount)
    {
        cout << "Payment of " << amount
             << " made using Paypal" << endl;
    }
};

class RazorPayAdapter : public PaymentProcessor
{
private:
    RazorPay rp;

public:
    void pay(int amount) override
    {
        rp.makePayment(amount);
    }
};

class PaypalAdapter : public PaymentProcessor
{
private:
    Paypal p;

public:
    void pay(int amount) override
    {
        p.sendPayment(amount);
    }
};

int main()
{

    unique_ptr<PaymentProcessor> payment = make_unique<RazorPayAdapter>();

    payment->pay(500);

    payment = make_unique<PaypalAdapter>();

    payment->pay(1000);
}