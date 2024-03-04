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
        cout << "Compute(const char*, float)" << endl;
        strcpy(_brand, brand);
    }

    Computer(const Computer &rhs) 
    : _brand(new char[strlen(rhs._brand) + 1]())
    , _price(rhs._price)
    { //深拷贝，先申请堆空间，再拷贝字符串内容
        cout << "Computer(const Computer&)" <<endl;
        strcpy(_brand, rhs._brand);
    }

    Computer& operator=(const Computer& rhs) {
        if (this != &rhs) {
            if (_brand) 
                delete [] this->_brand; //回收左操作数的空间
            _brand = new char[strlen(rhs._brand) + 1] ();
            strcpy(_brand, rhs._brand);
            _price = rhs._price;
            cout << "Computer operator=(const Computer&)" << endl;
        }
        return *this;
    }

    void setBrand(const char * brand);
    void setPrice(float price);
    void print();

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
};
/*
void Computer::setBrand(const char * brand) {
    strcpy(_brand, brand);
}
*/

void Computer::setPrice(float price) {
    _price = price;
}

void Computer::print() {
    cout << "brand:" << _brand << endl;
    cout << "price:" << _price << endl;
}

void test() {
    int a;
    Computer c1("mac", 9999);
    c1.print();
    Computer c2("xiaomi", 6999);
    c2.print();
    c2.operator=(c1);
    c2.print();
}

int main() {
    test();
}