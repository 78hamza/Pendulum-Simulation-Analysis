#include "strfun.h"

# define G 9.81
# define L 1.0

// compute angular acceleration 
double  compute_acc(double *theta)
{
    return -(G/L) *  sin(*theta);
}

void    update_pendulum(double *theta, double *omega, double dt)
{
    double alpha = compute_acc(theta);

    *omega += alpha * dt;
    *theta += *omega * dt;
}
