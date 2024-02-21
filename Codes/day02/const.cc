#include<iostream>
using std::cout;
using std::endl;

#define MAX 1000 

void test0()
{
    int a;
    //const int b;
    const int c = 1;
    //c = 2;

    cout << MAX << endl;
}

int main(void)
{
    test0();
    return 0;
}
