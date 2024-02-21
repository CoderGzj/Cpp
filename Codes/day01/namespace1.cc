#include <iostream>
using std::cout;
using std::endl;

namespace wd
{
int number = 1;

void display() {
    cout << "display()" << endl;

}

void pirint() {
    cout << "print()" << endl;
}

namespace dlm
{
int number = 1;

void display() {
    cout << "wd::dlm::display()" << endl;
}

void pirint() {
    cout << "wd::dlm::print()" << endl;
}

}//end of namespace dlm

}//end of namespace wd

void test0() {
    //:: 称为作用域限定符
    wd::display();
    wd::pirint();
    cout << "wd::number = " << wd::number << endl;
    cout << "wd::dlm::number = " << wd::dlm::number << endl;
    wd::dlm::display();
}

int main(void) {
    test0();
    return 0;
}