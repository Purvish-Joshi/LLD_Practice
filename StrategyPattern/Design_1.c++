#include <iostream>
using namespace std;

class DiscountStrategy
{
public:
    virtual double discount(double price) = 0;
    virtual ~DiscountStrategy() {}
};

class RegularDiscount : public DiscountStrategy
{
public:
    double discount(double price) override
    {
        cout << "no Discount" << endl;
        return price;
    }
};

class PremiumDiscount : public DiscountStrategy
{
public:
    double
    discount(double price) override
    {
        if (price < 1000)
        {
            cout << "20% discount" << endl;
            return price - (price * 0.2);
        }
        else
        {
            cout << "30% discount" << endl;
            return price - (price * 0.3);
        }
    }
};

class FestivalDiscount : public DiscountStrategy
{

public:
    double
    discount(double price) override
    {
        if (price < 1000)
        {
            cout << "30% discount" << endl;
            return price - (price * 0.3);
        }
        else
        {
            cout << "50% discount" << endl;
            return price - (price * 0.5);
        }
    }
};

class ShoppingCart
{
protected:
    DiscountStrategy *discount;

public:
    ShoppingCart(DiscountStrategy *d)
    {
        this->discount = d;
    }

    ~ShoppingCart()
    {
        delete discount;
    }

    void setDiscountStrategy(
        DiscountStrategy *strategy)
    {
        this->discount = strategy;
    }

    double calculate(double totalPrice)
    {
        return discount->discount(totalPrice);
    }
};

int main()
{
    ShoppingCart *cart = new ShoppingCart(new RegularDiscount());

    cout<<cart->calculate(500)<<endl;
 

    cart->setDiscountStrategy(new PremiumDiscount());

    cout<<cart->calculate(500)<<endl;

    cart->setDiscountStrategy(new FestivalDiscount());

    cout<<cart->calculate(1000)<<endl;

    delete cart;

    return 0;
}