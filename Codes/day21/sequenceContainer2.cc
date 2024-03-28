#include <iostream>
#include <vector>
#include <deque>
#include <list>
using std::cout;
using std::endl;
using std::vector;
using std::deque;
using std::list;

template<class Container>
void display(const Container &con)
{
    for (auto& elem : con)
    {
        cout << elem << " ";
    }
    cout << endl;
}

void test()
{
    vector<int> number = {1, 2, 3, 4, 5, 6, 7, 8};
    display(number);

    number.push_back(9);
    number.push_back(10);
    display(number);
    number.pop_back();
    display(number);
}
void test1()
{
    deque<int> number = {1, 2, 3, 4, 5, 6, 7, 8};
    display(number);

    number.push_back(9);
    number.push_back(10);
    display(number);
    number.pop_back();
    display(number);

    number.push_front(111);
    number.push_front(222);
    display(number);
    number.pop_front();
    display(number);
}
void test2()
{
    list<int> number = {1, 2, 3, 4, 5, 6, 7, 8};
    display(number);

    number.push_back(9);
    number.push_back(10);
    display(number);
    number.pop_back();
    display(number);

    number.push_front(111);
    number.push_front(222);
    display(number);
    number.pop_front();
    display(number);

    cout << endl << "在list中间插入" << endl;
    auto cit = number.begin();
    ++cit;
    ++cit;
    auto it = number.insert(cit, 300);
    display(number);
}
int main() 
{
    test();
    test1();
    test2();
}
