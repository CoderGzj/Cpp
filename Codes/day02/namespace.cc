#include<iostream>
using std::cout;
using std::endl;

int number = 1;

namespace wd
{

int number = 2;

void display(int number)
{
    cout << "形參number:" << number << endl;
    cout << "wd::number:" << wd::number << endl;
    cout << "全局number:" << ::number << endl;
}

}//end of namespace wd

void test0()
{
    int a = 10;
    wd::display(a);
}

int main(void)
{
    test0();
    return 0;
}
