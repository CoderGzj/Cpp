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

    double getReal() const{
        return _real;
    }
    double getImage() const{
        return _image;
    }

private:
    double _real;
    double _image;
};

// 运算符重载形式一：普通函数
Complex operator+(const Complex& lhs, const Complex& rhs)
{
    return Complex(lhs.getReal() + rhs.getReal(), 
                    rhs.getImage() + rhs.getImage());
}

void test() {
    Complex c1(1,2), c2(3,4);
    Complex c3 = c1 + c2;
    
}

int main() {
    test();
}