#include <iostream>

class Base
{
public:
    virtual void solveLife()
    {
        std::cout<<"solved life in BASE."<<std::endl;
    }
};

class Derived : public Base
{
public:
    void solveLife() override                   // (1) you don't need virtual here again. (2) override is an optional c++11 keyword
    {
        std::cout<<"solved life in DERIVED."<<std::endl;
    }
};


int main(int argc, char const *argv[])
{
    Base* obj = new Derived();
    obj->solveLife();
    return 0;
}