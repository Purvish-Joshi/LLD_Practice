#include <iostream>
using namespace std;

class Inventory
{
public:
    bool checkStock(int productId)
    {
        cout << "Checking inventory..." << endl;
        return true;
    }
};

class Payment
{
public:
    bool processPayment(double amount)
    {
        cout << "Processing payment..." << endl;
        return true;
    }
};

class Order
{
public:
    void createOrder(int productId)
    {
        cout << "Creating order..." << endl;
    }
};

class Notification
{
public:
    void sendNotification()
    {
        cout << "Sending notification..." << endl;
    }
};

class OrderFacade
{
private:
    Inventory inventory;
    Payment payment;
    Order order;
    Notification notification;

public:
    void placeOrder(int productId, double amount)
    {
        if (!inventory.checkStock(productId))
        {
            cout << "Product unavailable" << endl;
            return;
        }

        if (!payment.processPayment(amount))
        {
            cout << "Payment failed" << endl;
            return;
        }

        order.createOrder(productId);
        notification.sendNotification();

        cout << "Order placed successfully" << endl;
    }
};

int main()
{
    OrderFacade facade;

    facade.placeOrder(101, 500);
}