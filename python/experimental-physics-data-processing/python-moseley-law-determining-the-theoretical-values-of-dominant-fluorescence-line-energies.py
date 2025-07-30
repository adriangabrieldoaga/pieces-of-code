# -*- coding: utf-8 -*-

# The Unlicense
# This is basic code, you can use it freely, without any restrictions or attribution.
# Creator: Adrian-Gabriel Doaga
# Email: adriangabrieldoaga@gmail.com
# Website: https://github.com/adriangabrieldoaga/pieces-of-code
# Year: 2025
# Bibliography:
# http://www.physics.pub.ro/Referate/BN031A/Verificarea_legii_lui_MOSELEY_prin_fluorescenta_de_raze_X.pdf

# Constants
h_in_SI = 6.62607015e-34 # J*s; Planck's constant
c_in_SI = 299792458 # m/s; Speed of light in vacuum
R_in_SI = 1.0973731568160e7 # m^-1; Rydberg's constant
sigma = 1 # Shielding factor
eV_to_J = 1.602176634e-19
# Transition for K_alpha spectral line
m = 1
n = 2

# Atomic numbers of metals only
elements = {
    "Zinc": 30,
    "Molybdenum": 42,
    "SnCl2": 50,
    "BaSO4": 56,
    "Tantalum": 73,
    "Wolfram": 74
}

E_K_alpha_in_keV = {}
for element, Z in elements.items():
    E_K_alpha_in_J = h_in_SI * c_in_SI * R_in_SI * ((Z - sigma)**2) * (1/(m**2) - 1/(n**2))
    E_K_alpha_in_eV = E_K_alpha_in_J / eV_to_J
    E_K_alpha_in_keV[element] = E_K_alpha_in_eV * (10**-3)

print("E_K_alpha_in_keV =", E_K_alpha_in_keV)

# Output:
# E_K_alpha_in_keV = {'Zinc': 8.581790937328613, 'Molybdenum': 17.15337760481498, 'SnCl2': 24.500451891231865, 'BaSO4': 30.867916272793163, 'Tantalum': 52.898934862201585, 'Wolfram': 54.3785539893272}
