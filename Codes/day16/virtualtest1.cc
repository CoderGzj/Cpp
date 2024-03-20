#include <iostream>
using std::cout;
using std::endl;

class Base1
{
public:
    Base1()
    : _iBase1(10)
    {}
    virtual
    void f()
    {
        cout << "Base1::f()" << endl;
    }
    virtual
    void g()
    {
        cout << "Base1::g()" << endl;
    }
    virtual
    void h()
    {
        cout << "Base1::h()" << endl;
    }
private:
    long _iBase1;
};

class Base2
{
public:
    Base2()
    : _iBase2(100)
    {}
    virtual 
    void f()
    {
        cout << "Base2::f()" << endl;
    }
    virtual
    void g()
    {
        cout << "Base2::g()" << endl;
    }
    virtual
    void h()
    {
        cout << "Base2::h()" << endl;
    }
private:
    int _iBase2;
};
class Base3
{
public:
    Base3()
    : _iBase3(1000)
    {}
    virtual
    void f()
    {
        cout << "Base3::f()" << endl;
    }
    virtual
    void g()
    {
        cout << "Base3::g()" << endl;
    }
    virtual
    void h()
    {
        cout << "Base3::h()" << endl;
    }
private:
    int _iBase3;
};
class Derived
: public Base1
, public Base2
, public Base3
{
public:
    Derived()
    : _iDerived(10000)
    {}
    void f()
    {
        cout << "Derived::f()" << endl;
    }
    virtual
    void g1()
    {
        cout << "Derived::g1()" << endl;
    }
private:
    int _iDerived;
};
void test()
{
     Derived d;
     Base1 *pBase1 = &d;
     Base2 *pBase2 = &d;
     Base3 *pBase3 = &d;
     Derived *pDerived = &d;
     pBase2->f();
    cout << "sizeof(Derived) = " << sizeof(Derived) << endl;

     cout << "pBase1 = " << pBase1 << endl;
     cout << "pBase2 = " << pBase2 << endl;
     cout << "pBase3 = " << pBase3 << endl;
     typedef void (*Function)();

    printf("第一个虚指针= %p\n", &d);
    printf("第一个虚表的地址 = %p\n", (long*)*(long*)&d);
    printf("第一个虚函数的地址 = %p\n", (long*)*(long*)*(long*)&d);
    Function f = (Function)*((long*)*(long*)&d);
    f();
    printf("第一个虚函数的地址 = %p\n", f);

    f = (Function)*((long*)*(long*)&d + 1);
    f();
    printf("第二个虚函数的地址 = %p\n", f);

    f = (Function)*((long*)*(long*)&d + 2);
    f();
    printf("第三个虚函数的地址 = %p\n", f);

    f = (Function)*((long*)*(long*)&d + 3);
    f();
    printf("第四个虚函数的地址 = %p\n", f);

    cout << endl;

    printf("第二个虚指针 = %p\n", (long*)pBase2);
    printf("第二个虚表的地址 = %p\n", (long*)*(long*)pBase2);
    printf("第一个虚函数的地址 = %p\n", (long*)*(long*)*(long*)pBase2);
    f = (Function)*((long*)*(long*)pBase2);
    f();
    printf("第一个虚函数的地址 = %p\n", f);

    f = (Function)*((long*)*(long*)pBase2 + 1);
    f();
    printf("第二个虚函数的地址 = %p\n", f);

    f = (Function)*((long*)*(long*)pBase2 + 2);
    f();
    printf("第三个虚函数的地址 = %p\n", f);

    // printf("第三个虚指针 = %p\n", (long*)(long*)&d + 2);
    // printf("第三个虚表的地址 = %p\n", (long*)*(long*)((long*)&d + 2));

    // printf("第四个虚指针 = %p\n", (long*)(long*)&d + 3);
    // printf("第四个虚表的地址 = %p\n", (long*)*(long*)((long*)&d + 3));
}
int main() {
    test();
}