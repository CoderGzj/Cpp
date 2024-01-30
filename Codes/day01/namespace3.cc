#include <iostream>
using std::cout;//只会引入这一个实体
using std::endl;

void print()
{
    cout << "hello,world" << endl;
}

void test0() 
{
    print();
}

int main(void)
{
    test0();
    return 0;
}

