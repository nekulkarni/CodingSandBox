#include <stdio.h>

class A
{
    int mP;

    A(int _p) : mP(_p) {} // ONLY parameterized constructor defined by the programmer. No default constructor written.
};



int main(int argc, char const *argv[])
{
    A a;    // default constructor invoked!

    return 0;
}