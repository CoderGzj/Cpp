#include <iostream>
using std::cout;
using std::endl;

class Father
{
public:
    Father()
    {
        cout << "Father()" << endl;
    }

    virtual 
    void print()
    {
        cout << "Father" << endl;
    }

    ~Father()
    {
        cout << "~Father()" << endl;
    }
};

class Son
: public Father
{
public:
    Son()
    : Father()
    {
        cout << "Son()" << endl;
    }
    void print()
    {
        cout << "Son" << endl;
    }

    ~Son()
    {
        cout << "~Son()" << endl;
    }

};

void func(Father & rhs)
{
    rhs.print();
}

void test()
{
    Son s; 
    func(s);
}

int main() {
    test();
}