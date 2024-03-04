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

    void print() {
        cout << "(" << _ix << "," << _iy << ")" << endl;
    }

    ~Point() {cout <<"~Point()" << endl;}

private:
    int _ix = 10;
    int _iy = 10;
};

class Line
{
public:
    Line(int x1, int y1, int x2, int y2)
    : _pt1(x1, y1)
    , _pt2(x2, y2)
    {
        cout << "Line(int,int,int,int)" << endl;
    }

    void printLine() {
        _pt1.print();
        cout << "-->" << endl;
        _pt2.print();
    }
private:
    Point _pt1;
    Point _pt2;
};

void test0() {
    Line line(1, 2, 3, 4);
    line.printLine();
}

int main() {
    test0();
}