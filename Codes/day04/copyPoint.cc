#include <iostream>
#include <string.h>
using std::cout;
using std::endl;

class Point
{
public:
    Point(int ix = 0, int iy = 0) //有参构造函数
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
    int _ix;
    int _iy;
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