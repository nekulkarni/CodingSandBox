#include <cstdlib>
#include<cstdio>
#include<iostream>

using namespace std;

template<class datatype>
class DataWrapper
{
    datatype mData[256];

public:

    DataWrapper() {mData[0] = 0;}

    datatype getFirstData() const { return mData[0]; }
};




int main()
{
    DataWrapper* obj = new DataWrapper<float>;

    std::cout<< obj->getFirstData();

    delete obj;
    return 0;
}