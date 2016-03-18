#include <cstdio>



class Calibration
{
private: 
    float fX, fY;
    float cX, cY;
public:
    Calibration() : fX(0), fY(0), cX(0), cY(0) {};
    Calibration(float _fx, float _fy) : Calibration(), fX(_fx), fY(_fy) {}
    void print() const { printf("%f %f and %f %f\n", fX, fY, cX, cY); }
};


int main(int argc, char const *argv[])
{
    Calibration calib(10.0f, 20.0f);
    calib.print();
    return 0;
}


