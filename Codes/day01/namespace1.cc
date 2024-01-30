#include <iostream>
using std::cout;
using std::endl;

namespace wd
{
int number = 1;

void display() {
    cout << "wd::display()" << endl;
}

namespace dlm
{
int number = 1;

void display() {
    cout << "wd::dlm::display()" << endl;
}

}//end of namespace dlm

}//end of namespace wd

void test0() {
    //:: 称为作用域限定符
    wd::display();
    cout << "wd::number = " << wd::number << endl;
    wd::dlm::display();
    cout << "wd::dlm::number = " << wd::dlm::number << endl;

}

int main(void) {
    test0();
    return 0;
}