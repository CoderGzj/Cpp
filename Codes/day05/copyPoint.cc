#include <iostream>
#include <string.h>
using std::cout;
using std::endl;

class Point
{
public:
    Point() = default; //C++ 11

    Point(int ix, int iy) //有参构造函数
    : _ix(ix)
    , _iy(iy)
    {
        cout << "Point(int, int)" << endl;
    }

    Point(const Point &rhs) //拷贝构造函数
        : _ix(rhs._ix)
        , _iy(rhs._iy)
    {
        cout << "Point(const Point&)" << endl;
    }

    void print() {
        cout << _ix << "," << _iy <<endl;
    }

    ~Point() {cout <<"~Point()" << endl;}

private:
    const int _ix = 10;
    const int _iy = 10;
};

void getpoint(Point pt) {
    cout << "pt:" << endl;
    pt.print();
}

int main() {
    Point p1(1, 2);
    p1.print();
    Point p2 = p1;
    p2.print();
    getpoint(p1);
}