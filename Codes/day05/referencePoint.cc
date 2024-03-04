#include <iostream>
#include <string.h>
using std::cout;
using std::endl;

class Point
{
public:
    Point(int ix, int iy, int & num) //有参构造函数
    : _ix(ix)
    , _iy(iy)
    , _ref(num)
    {
        cout << "Point(int, int)" << endl;
    }

    void print() {
        cout << _ix << "," << _iy <<endl;
    }

    ~Point() {cout <<"~Point()" << endl;}

private:
    int _ix = 10;
    int _iy = 10;
    int & _ref;
};

void getpoint(Point pt) {
    cout << "pt:" << endl;
    pt.print();
}

int main() {
    int c(1);
    Point p1(1, 2, c);
    p1.print();
    Point p2 = p1;
    p2.print();
    getpoint(p1);
}