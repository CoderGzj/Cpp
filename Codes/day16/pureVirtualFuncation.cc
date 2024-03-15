#include <iostream>
using std::cout;
using std::endl;

class Base
{
public:
    virtual void print() const = 0;
    virtual void display() const = 0;
};

class Derived
: public Base
{
public:
    virtual void print() const
    {
        cout << "Derived::print()" << endl;
    }
    virtual void display() const
    {
        cout << "Derived::diaplay()" << endl;
    }
};

int main()
{
    Derived derived;
    derived.print();
}