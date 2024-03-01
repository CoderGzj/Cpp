#include <iostream>
using std::cout;
using std::endl;

void display(int *p) {
    *p = 10;
    cout << "*p:" << *p << endl;
    cout <<"p:" << p << endl;
}

void test0() {
    int *p = static_cast<int *> (malloc(sizeof(int)));
    
    const int a = 1;
    display(const_cast<int *>(&a));
    cout << "a:" << a << endl;
    cout << "&a:" << &a << endl;
}

int main() {
    test0();
}