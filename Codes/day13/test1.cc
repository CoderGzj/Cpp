#include <iostream>
using std::cout;
using std::endl;

class A 
{
public:
    void print()
    {
        cout << "A" << endl;
    }
};

class B
{
public:
    void print()
    {
        cout << "B" << endl;
    }
};

class C 
: public A 
, public B
{

};

void test() {
    C c;
    c.A::print();
    c.B::print();
}

int main() {
    test();
    return 0;
}