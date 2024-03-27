#include <iostream>
using namespace std;

// 函数模板
//template <class T>
template <typename T>
T add (T x, T y) {
    return x + y;
}

void test()
{
    int ia = 3, ib = 4;
    double da = 3.3, db = 8.8;
    string s1 = "hello", s2 = "world";

    cout << "add(ia, ib) = " << add(ia, ib) << endl;
    cout << "add(ba, bb) = " << add(da, db) << endl;
    cout << "add(s1, s2) = " << add(s1, s2) << endl;
}

int main()
{
    test();
}