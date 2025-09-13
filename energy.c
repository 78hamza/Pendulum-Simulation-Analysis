#include "strfun.h"

# define G 9.82
# define L 1.0
# define M 1.0

double  kinetic_energy(double   omega)
{
    return 0.5 *  pow(L * omega, 2);
}

double potential_energy(double theta)
{
    return M * G * L * (1 - cos(theta));
}

double total_energy(double theta, double omega)
{
    return (kinetic_energy(omega) + potential_energy(theta));
} 
