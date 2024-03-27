#include <iostream>
#include <string>
using namespace std;

template <typename T, size_t kSize = 10> 
class Stack
{
public:
    Stack()
    : _top(-1)
    , _data(new T[kSize]())
    {}
    ~Stack();
    bool empty() const;
    bool full() const;
    void push(const T &t);
    void pop();
    T top() const;
private:
    int _top;
    T * _data;
};

template <typename T, size_t kSize>
Stack<T, kSize> :: ~Stack()
{
    if (_data)
    {
        delete [] _data;
        _data = nullptr;
    }
}

template <typename T, size_t kSize>
bool Stack<T, kSize> :: empty() const
{
    return _top == -1;
}

template <typename T, size_t kSize>
bool Stack<T, kSize> :: full() const
{
    return _top == kSize - 1;
}

template <typename T, size_t kSize>
void Stack<T, kSize> :: push(const T &t)
{
    if (!full())
    {
        _data[++_top] = t;
    }
    else
    {
        cout << "The stack is full" << endl;
    }
}

template <typename T, size_t kSize>
void Stack<T, kSize> :: pop()
{
    if (!empty())
    {
        _top--;
    }
    else
    {
        cout << "The stack is empty" << endl;
    }
}

template <typename T, size_t kSize>
T Stack<T, kSize> :: top() const
{
    return _data[_top];
}

void test()
{
    Stack<int, 8> st;
    st.push(1);
    cout << st.top() << endl;
    st.pop();
    cout << st.empty() << endl;
}

int main()
{
    test();
}