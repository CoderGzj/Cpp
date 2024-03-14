#include <iostream>
using std::cout;
using std::endl;

class A 
{
public:
    void set(int ix)
    {
        _ix = ix;
    }

    void print()
    {
        cout << "_ix = " << _ix << endl;
    }
private:
    int _ix;
};

class B
: virtual public A
{

};

class C 
: virtual public A 
{

};

class D
: public B
, public C
{

};

void test() {
    D d;
    d.set(10);
    d.print();
}

int main() {
    test();
    return 0;
}