#include <iostream>
#include <math.h>
using namespace std;

class Point {
    friend float distance(const Point& lhs, const Point& rhs);
public:
    Point(int x = 0, int y = 0)
    :_ix(x)
    ,_iy(y) 
    {}

    void print() const {
        cout << "(" << _ix << "," << _iy << ")" << endl;
    }

private:
    int _ix;
    int _iy;
};

float distance(const Point& lhs, const Point& rhs) {
    return hypot(lhs._ix - rhs._ix, lhs._iy - rhs._iy);
}

void test() {
    Point pt1(1,2);
    pt1.print();
    Point pt2(4,6);
    pt2.print();
    cout << distance(pt1, pt2) << endl;
}

int main() {
    test();
}