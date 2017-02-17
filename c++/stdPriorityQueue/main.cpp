#include<stdio.h>
#include<queue>


typedef struct Time
{
    int h;
    int m;
} Time;



class CompareTime
// Assumes a 24-hour time
{

public:
    bool operator()(const Time& t1, const Time& t2)
    {
        if (t1.h < t2.h)
        {
            return true;
        }
        else if (t1.h == t2.h)
        {
            if (t1.m < t2.m)
            {
                return true;
            }
            else return false;
        }
        else return false;
    }
};


int main(int argc, char const *argv[])
{
    priority_queue<Time> q1;

    return 0;
}