#include <cstdio>
#include <cstdlib>

// SchmittTrigger is an active circuit which converts an analog input signal to a digital
// output signal. The circuit is named a "trigger" because the output retains
// its value until the input changes sufficiently to trigger a change. In the
// non-inverting configuration, when the input is higher than a chosen
// threshold, the output is high. When the input is below a different (lower)
// chosen threshold the output is low, and when the input is between the two
// levels the output retains its value.
// Source: Wikipedia

class SchmittTrigger {
public:
    SchmittTrigger(float lower, float upper, bool defaultState);
    bool filter(const float raw);

private:
    float mUpperLimit;
    float mLowerLimit;
    bool mCurrentState;
};

inline SchmittTrigger::SchmittTrigger(const float lower, const float upper, const bool defaultState)
    : mLowerLimit(lower), mUpperLimit(upper), mCurrentState(defaultState) {}

inline bool SchmittTrigger::filter(const float raw) {
    if (raw <= mLowerLimit) {
        mCurrentState = false;
    } else if (raw >= mUpperLimit) {
        mCurrentState = true;
    }
    return mCurrentState;
}

int main(int argc, char const* argv[]) {
    SchmittTrigger mySchmittTrigger(2, 8, false);

    for (int i = -5; i < 15; ++i) {
        printf("Raw: %d   \tfiltered: %d\n", i, mySchmittTrigger.filter(i));
    }

    for (int i = 15; i > -5; --i) {
        printf("Raw: %d   \tfiltered: %d\n", i, mySchmittTrigger.filter(i));
    }

    return 0;
}