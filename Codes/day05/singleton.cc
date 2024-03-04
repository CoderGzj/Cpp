#include <iostream>
#include <string.h>
using std::cout;
using std::endl;

class Singleton
{
public:
    static Singleton* getInstance() {
        if (nullptr == _pInstance) {
            _pInstance = new Singleton();
        }
        return _pInstance;
    }

    static void destory() {
        if (_pInstance) 
            delete _pInstance;
    }

private:
    Singleton() {cout << "Singleton()" << endl;}
    ~Singleton() {cout << "~Singleton()" << endl;}
    static Singleton* _pInstance;
};

Singleton * Singleton::_pInstance = nullptr;

void test0() {
    Singleton* ps1 = Singleton::getInstance();

    Singleton::destory();
}

int main() {
    test0();
}