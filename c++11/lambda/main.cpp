#include <iostream>
#include <vector>
#include <functional>

using std::vector;
using std::cout;
using std::endl;


// Q. WHAT IS A LAMBDA FUNCTION?
// A: A lambda function is an anonymous, temporary, usually small function. 


int main(int argc, char const *argv[])
{


    // We are creating (anonymous) lambdas and storing them into std::function objects.

    // Simple, no argument and returns void

    std::function<void()> myFunc = []() { cout<<"Simple function, doing nothing."<<endl; };
    myFunc();


    // One integer argument, returns void

    std::function<void(int)> myFunc1 = [](int x) { cout<<"Simple function, recieved integer "<<x<<endl; };
    myFunc1(5);


    // One integer argument, returns integer

    std::function<int(int)> myFunc2 = [](int x) { cout<<"Simple function, doubling "<<x<<endl; return 2*x; };
    cout<<"Doubled: "<< myFunc2(5) <<endl;


    // access outside variable by capturing
    // Quick Gyan: 
    // [] captures nothing, 
    // [&] captures all automatic variables odr-used in the body of the lambda by reference
    // [=] captures all automatic variables odr-used in the body of the lambda by value
    // [a,&b] where a is captured by value and b is captured by reference.


    int outsideVar = 5;
    std::function<void()> myFunc3 = [&]() { cout<<"Simple function, captures outside variable = "<< outsideVar <<endl; };
    myFunc3();



    // Now : Leaving lambda unnamed and calling it right away

    cout<<"Result of the unnamed lambda: "<< []() { return 55; }() << endl;

    // Note what's happening: In "[]() { return 55; }()", "[]() { return 55; }" is the lambda definition
    // which is equivalent to an unnamed std::function or a function pointer, and the "()" after the lambda
    // definition simply goes ahead and invokes this unnamed lambda.

    cout<<"Result of the unnamed lambda: "<< [](int arg) { return arg; }(100) << endl;





    // a more complicated example

    // without lambda function

    vector<int> vecNumbers = {1,2, 3, 4, 5, 6, 7, 8};
    int low = 4, high = 9, found = -1;

    // with lambda function

    std::function<int(const vector<int>&, const int&, const int&)> findNumberInInterval = 
    [&](const vector<int> &_vecNumbers, const int &_low, const int &_high) 
    {
        for (auto i: _vecNumbers)
        {
            if (i > _low && i < _high)
            {
                found = i;
                return i;
            }
        }
        return -1;
    };

    found = findNumberInInterval(vecNumbers, low, high);

    std::cout<<"found:"<<found<<std::endl;


    
    return 0;
}