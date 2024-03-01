#include <iostream>
using std::cout;
using std::endl;
#include "head.h"


int add(int a, int b, int c) {
    return a + b + c;
}

long add(long a, long b) {
    return a + b;
}

int add(int a, long b) {
    return a + b;
}

int add(long a, int b) {
    return a + b;
}

int main() {
    
}