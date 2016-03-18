#include <stdio.h>
#include <stdlib.h>


class A
{
    int a;

public:
    A() 
    {
        printf("A() default constructor.\n" );
        a = 5;
    }

    A(int _a) 
    {
        printf("A() parameterized constructor.\n" );
        a = _a;
    }

};


class B
{

public:
    B(int _a)
    {
        

    }

};