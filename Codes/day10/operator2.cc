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
friend std::ostream &operator<<(std::ostream &os, const Complex &rhs);

private:
    double _real;
    double _image;
};

std::ostream &operator<<(std::ostream &os, const Complex &rhs) {
    os << rhs._real << "+" << rhs._image;
    return os;
}

void test() {
    Complex c1(1,2);
    cout << "c1 = " << c1 << endl;
    operator<<(operator<<(cout, "c1 = "), c1).operator<<(endl);
}

int main() {
    test();
}