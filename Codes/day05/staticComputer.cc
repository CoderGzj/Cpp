#include <iostream>
#include <string.h>
using std::cout;
using std::endl;

class Computer
{
public: //public应该在类上部,对外提供接口
    Computer(const char * brand, float price)
    : _brand(new char[strlen(brand) + 1]())
    , _price(price) 
    {
        _totalPrice += price;
        cout << "Compute(const char*, float)" << endl;
        strcpy(_brand, brand);
    } 

    void print();

    static void printtotalprice() {
        cout << "totalprice:" << _totalPrice << endl;
    }

    ~Computer() {
        if (_brand) {
            delete [] _brand;
            _brand = nullptr;
        }
        cout <<"~Computer()" << endl;
    }

private:
    //类中数据成员以下划线开始，代码风格
    char *_brand;
    float _price;
    static double _totalPrice;
};

double Computer::_totalPrice = 0;

void Computer::print() {
    cout << "brand:" << _brand << endl;
    cout << "price:" << _price << endl;
}

void test() {
    int a;
    Computer c1("mac", 9999);
    c1.print();
    c1.printtotalprice();
    Computer c2("xiaomi", 6999);
    c2.print();
    c2.printtotalprice();
    Computer::printtotalprice();
}

int main() {
    test();
}