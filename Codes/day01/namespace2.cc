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

using namespace wd;

void test0() {
    display();
    cout << "wd::number = " << number << endl;
}

int main(void) {
    test0();
    return 0;
}