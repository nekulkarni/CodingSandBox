#include <cstdio>
#include <cstdlib>

// https://en.wikipedia.org/wiki/Schmitt_trigger

// class used to set two different limits: upper limit and lower limit. and values below or equal to lower limit are set to zero and continues to be zero even is beyond the lower limit, the state is changed to 1 when in touch the upper limit and continues to 1 until it touches the lower limit.

class SchmittTrigger
{
    float mUpperLimit;
    float mLowerLimit;
    bool mCurrentState;

public:
    SchmittTrigger(float lower, float upper, bool defaultState) : mLowerLimit(lower), mUpperLimit(upper), mCurrentState(defaultState)
    {}

    bool filter(const float& raw)
    {
        if (raw <= mLowerLimit)
        {
            mCurrentState = false;
        }
        else if (raw >= mUpperLimit)
        {
            mCurrentState = true;
        }
        return mCurrentState;
    }
};


int main(int argc, char const *argv[])
{
    SchmittTrigger mySchmittTrigger(2, 8, false);

    for (int i = -5; i < 15; ++i)
    {
        printf("raw: %d ... filtered: %d\n", i, mySchmittTrigger.filter(i) );
    }

    for (int i = 15; i > -5; --i)
    {
        printf("raw: %d ... filtered: %d\n", i, mySchmittTrigger.filter(i) );
    }

    return 0;
}