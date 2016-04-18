#include <cstdio>
#include <algorithm>
#include <cstdlib>

float medianOfThree(float a, float b, float c)
{
    if (a < b)
    {
        if (a >= c) return a;
        else return (b < c)? b : c;
    }
    else
    {
        if (a <= c) return a;
        else return (b < c)? c: b;
    }
}

float medianOfThree_2(float a, float b, float c)
{
    return (a < b)? (a >= c)?  a: (b < c)? b : c : (a <= c)?  a: (b < c)? c: b;
}

#define MEDIAN_OF_THREE(a, b, c) (((a) < (b))? ((a) >= (c))?  (a): ((b) < (c))? (b) : (c) : ((a) <= (c))?  (a): ((b) < (c))? (c): (b))


int main(int argc, char const *argv[])
{
    float a = 1;
    float b = 2;
    float c = 3;
    float ans = medianOfThree(a, b, c);
    float ans2 = MEDIAN_OF_THREE(a, b, c);
    printf("median: %f and %f\n",ans, ans2 );
    return 0;
}