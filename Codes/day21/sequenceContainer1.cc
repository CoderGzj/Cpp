#include <iostream>
#include <vector>
#include <deque>
#include <list>
using std::cout;
using std::endl;
using std::vector;
using std::deque;
using std::list;

void test()
{
    //vector<int> number(10, 4);
    // int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    // vector<int> number(arr, arr + 10);
    vector<int> number = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    for (size_t idx = 0; idx < number.size(); ++idx)
    {
        cout << number[idx] << " ";
    }
    cout << endl;

    vector<int>::iterator it;
    for (it = number.begin(); it != number.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl; 

    for (auto &elem : number)
    {
        cout << elem << " ";
    }
    cout << endl;
}

void test1()
{
    //deque<int> number(10, 4);
    // int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    // deque<int> number(arr, arr + 10);
    deque<int> number = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    for (size_t idx = 0; idx < number.size(); ++idx)
    {
        cout << number[idx] << " ";
    }
    cout << endl;

    deque<int>::iterator it;
    for (it = number.begin(); it != number.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl; 

    for (auto &elem : number)
    {
        cout << elem << " ";
    }
    cout << endl;
}

void test2()
{
    //list<int> number(10, 4);
    // int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    // list<int> number(arr, arr + 10);
    list<int> number = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    // for (size_t idx = 0; idx < number.size(); ++idx)
    // {
    //     cout << number[idx] << " ";
    // }
    // cout << endl;

    list<int>::iterator it;
    for (it = number.begin(); it != number.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl; 

    for (auto &elem : number)
    {
        cout << elem << " ";
    }
    cout << endl;
}

int main() 
{
    test();
    test1();
    test2();
}
