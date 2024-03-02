#include <iostream>
#include <string.h>
using std::cout;
using std::endl;

class Computer
{
public: //public应该在类上部,对外提供接口
    Computer(const char * brand, float price) {
        strcpy(_brand, brand);
        _price = price;
        print();
    }

    void setBrand(const char * brand);
    void setPrice(float price);
    void print();
private:
    //类中数据成员以下划线开始，代码风格
    char _brand[20];
    float _price;
};

void Computer::setBrand(const char * brand) {
    strcpy(_brand, brand);
}

void Computer::setPrice(float price) {
    _price = price;
}

void Computer::print() {
    cout << "brand:" << _brand << endl;
    cout << "price:" << _price << endl;
}

void test() {
    int a;
    // Computer c1;
    // c1.setBrand("Mac");
    // c1.setPrice(9999);
    // c1.print();
}

int main() {
    test();
}