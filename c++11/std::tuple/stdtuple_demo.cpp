#include <iostream>
#include <string>
#include <tuple>

// Class template std::tuple is a fixed-size collection of heterogeneous values. It is a generalization of std::pair.

using std::string;

std::tuple<string, int, float> getNameMarksPercentage()
{
    string name = "bappa";
    int marks = 45;
    float percentage = 90.0f;
    return std::make_tuple(name, marks, percentage);
}


int main(int argc, char const *argv[])
{
    string a;
    int b;
    float c;

    std::tie(a,b,c) = getNameMarksPercentage();
    std::cout<<"tuple: "<<"("<<a<<","<<b<<","<<c<<")"<<std::endl;
    return 0;
}

