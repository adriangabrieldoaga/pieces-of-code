#include "cpp-my-file-of-constants.h"

#include <iostream>

using std::cout;

int main()
{
    cout << "Constants\n";
    cout << "1. Mathematical constants\n";
    cout << "PI = " << PI << "\n";
    cout << "E = " << E << "\n";
    cout << "GOLDEN_RATIO = " << GOLDEN_RATIO << "\n";
    cout << "SQRT_2 = " << SQRT_2 << "\n";
    cout << "SQRT_3 = " << SQRT_3 << "\n\n";

    cout << "2. Physical constants\n";
    cout << "SPEED_OF_LIGHT = " << SPEED_OF_LIGHT << " m / s\n";
    cout << "GRAVITATIONAL_CONSTANT = " << GRAVITATIONAL_CONSTANT << " m^3 * kg^-1 * s^-2\n";
    cout << "PLANCK_CONSTANT = " << PLANCK_CONSTANT << " m^2 * kg / s\n";
    cout << "BOLTZMANN_CONSTANT = " << BOLTZMANN_CONSTANT << " m^2 * kg * s^-2 * K^-1\n";
    cout << "AVOGADRO_CONSTANT = " << AVOGADRO_CONSTANT << " mol^-1" << "\n\n";

    cout << "3. Other constants\n";
    cout << "EARTH_RADIUS = " << EARTH_RADIUS << " m\n";
    cout << "ATMOSPHERIC_PRESSURE = " << ATMOSPHERIC_PRESSURE << " Pa\n";

    return 0;
}
