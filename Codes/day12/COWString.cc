#include <iostream>
#include <string.h>

using std::cout;
using std::endl;

class String
{
public:
    // String s1;
    String()
    : _pstr(new char[5]() + 4)
    {
        cout << "String()" << endl;
        initRefCount();
    }
    
    // String s1("hello");
    String(const char *pstr)
    : _pstr(new char[strlen(pstr) + 5]() + 4)
    {
        cout << "String(const char *pstr)" << endl;
        strcpy(_pstr, pstr);
        initRefCount();
    }

    // String s2(s1);
    String(const String &rhs)
    : _pstr(rhs._pstr) //浅拷贝
    {
        cout << "String(const String &rhs)" << endl;
        increaseRefCount();
    }

    // String s3 = s1;
    String &operator=(const String &rhs)
    {
        if (this != &rhs) // 1 自复制
        {
            // 2 释放左操作
            release();
            // 3 深拷贝(浅拷贝)
            _pstr = rhs._pstr;
            increaseRefCount();
        }
        return *this; //4 返回this
    }

    // s1[0]
    char &operator[](size_t index)
    {
        if (index < size())
        {
            if (getRefCount() > 1)
            {
                char * ptmp = new char[size() + 5]() + 4;
                strcpy(ptmp, _pstr);
                decreaseRefCount();
                _pstr = ptmp;
                initRefCount();
            }
            return _pstr[index];
        }
        else
        {
            static char charnull = '\0';
            return charnull;
        }
    }

    ~String()
    {
        cout << "~String()" << endl;
        release();
    }

    const char *c_str() const
    {
        return _pstr;
    }

    int getRefCount()
    {
        return *(int *)(_pstr - 4);
    }

private:
    size_t size() const
    {
        return strlen(_pstr);
    }

    void initRefCount() 
    {
        *(int *)(_pstr - 4) = 1;
    }

    void increaseRefCount()
    {
        ++*(int *)(_pstr - 4);
    }

    void decreaseRefCount()
    {
        --*(int *)(_pstr - 4);
    }

    void release()
    {
        decreaseRefCount();
        if (0 == getRefCount())
            delete [] (_pstr - 4);
    }

    friend std::ostream &operator<<(std::ostream &os, const String &rhs);

private:
    char *_pstr;
};

std::ostream &operator<<(std::ostream &os, const String &rhs)
{
    if (rhs._pstr)
    {
        os << rhs._pstr;
    }
    return os;
}

void test()
{
    String s1("hello");
    String s2(s1);
    cout << "s1 = " << s1 << endl;
    cout << "s2 = " << s2 << endl;
    cout << "s1.getRefCount() " << s1.getRefCount() << endl;
    cout << "s2.getRefCount() " << s2.getRefCount() << endl;
    printf("s1'address : %p\n", s1.c_str());
    printf("s2'address : %p\n", s2.c_str());

    cout << endl;
    String s3("world");
    cout << "s3 = " << s3 << endl;
    cout << "s3.getRefCount() " << s3.getRefCount() << endl;
    printf("s3'address : %p\n", s3.c_str());

    cout << endl << "s3 = s1" << endl;
    s3 = s1;
    cout << "s1 = " << s1 << endl;
    cout << "s2 = " << s2 << endl;
    cout << "s3 = " << s3 << endl;
    cout << "s1.getRefCount() " << s1.getRefCount() << endl;
    cout << "s2.getRefCount() " << s2.getRefCount() << endl;
    cout << "s3.getRefCount() " << s3.getRefCount() << endl;
    printf("s1'address : %p\n", s1.c_str());
    printf("s2'address : %p\n", s2.c_str());
    printf("s3'address : %p\n", s3.c_str());

    cout << endl << "写操作" << endl;
    s3[0] = 'H';
    cout << "s1 = " << s1 << endl;
    cout << "s2 = " << s2 << endl;
    cout << "s3 = " << s3 << endl;
    cout << "s1.getRefCount() " << s1.getRefCount() << endl;
    cout << "s2.getRefCount() " << s2.getRefCount() << endl;
    cout << "s3.getRefCount() " << s3.getRefCount() << endl;
    printf("s1'address : %p\n", s1.c_str());
    printf("s2'address : %p\n", s2.c_str());
    printf("s3'address : %p\n", s3.c_str());

}

int main() {
    test();
    return 0;
}