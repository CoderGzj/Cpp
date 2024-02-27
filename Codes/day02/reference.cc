#include <iostream>
using std::cout;
using std::endl;

void test0()
{
    int a = 1;
    cout << "a:" << a << endl;
    int & ref1 = a;

    //int &ref2; //引用不能独立存在

    ref1 = 10;
    cout << "ref1:" << ref1 << endl
         << "a:" << a << endl;
}

int main(void)
{
    test0();
}