
#include <math.h>

#define T 0.005
#define L 1

int main(void)
{
    double x = 0 ,y = 0, theta = 0, v = 10, delta = 30;

    double beta;

    //this should run every 5ms
    {
        beta = atan(0.5 * tan( delta * M_PI /180 ));
        x += v * cos((theta+beta) * M_PI / 180) * T;
        y += v * sin((theta+beta) * M_PI / 180) * T;
        theta += v * cos(beta * M_PI / 180) * tan(delta * M_PI / 180) / L;
    }

    return 0;
}