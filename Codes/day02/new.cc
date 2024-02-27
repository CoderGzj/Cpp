#include <iostream>
#include <string.h>
using std::cout;
using std::endl;

void test0()
{
    int *p = (int *)malloc(sizeof(int));
    memset(p, 0, sizeof(int));
    cout << "*p:" << *p << endl;

    //1. new
    int * pint = new int(1);
    cout << "*pint:" << *pint <<endl;
    
    free(p);
    delete pint;

    //2. new申请数组
    int * parr = new int[10];

    delete [] parr;
}

int main(void)
{
    test0();
}