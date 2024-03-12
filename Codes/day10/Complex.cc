#include <iostream>
using std::cout;
using std::endl;

class Complex
{
public:
    Complex(double real = 0, double image = 0)
    : _real(real)
    , _image(image)
    {}

private:
    double _real;
    double _image;
};
void test() {
    Complex c1(1,2), c2(3,4);
    Complex c3 = c1 + c2;
}

int main() {
    test();
}