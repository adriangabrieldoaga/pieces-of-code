# -*- coding: utf-8 -*-

# Copyright notice:
# © 2025 Adrian-Gabriel Doaga. All Rights Reserved.
# Email: adriangabrieldoaga@gmail.com
# Website: https://github.com/adriangabrieldoaga/pieces-of-code
# Bibliography:
# http://www.physics.pub.ro/Referate/BN031A/Verificarea_legii_lui_MOSELEY_prin_fluorescenta_de_raze_X.pdf

import math
import numpy as np
import matplotlib.pyplot as plt
from sklearn.linear_model import LinearRegression

# Experimental data (the values are fabricated for demonstration purposes, but reflect the typical trends observed in real experiments)
E_K_alpha_in_keV = [8.6, 17.2, 24.5, 30.9, 54.4]
# Zinc, Molybdenum, SnCl2, BaSO4, Wolfram
E_K_alpha_unknown_element_in_keV = 52.9 # keV; Tantalum

# Data that is set
Z = [30, 42, 50, 56, 74] # the atomic numbers of metals only

# Constants
h_in_SI = 6.626e-34 # J*s; Planck's constant
c_in_SI = 3e8 # m/s; Speed of light in vacuum

# Experimental data processing
Z_minus_1_square = [(Z_element - 1)**2 for Z_element in Z]
print("Z_minus_1_square =", Z_minus_1_square)

# Reshape n for linear regression
Z_minus_1_square = np.array(Z_minus_1_square).reshape(-1, 1)

# Perform linear regression
model = LinearRegression()
model.fit(Z_minus_1_square, E_K_alpha_in_keV)
plt.figure(figsize=(7,7))
plt.scatter(Z_minus_1_square, E_K_alpha_in_keV, color='blue')
plt.plot(Z_minus_1_square, model.predict(Z_minus_1_square), color='blue', label=f'slope = {round(model.coef_[0], 5)} keV, intercept = {round(model.intercept_, 5)} keV')

# Labels and title
plt.xlabel('(Z-1)^2')
plt.ylabel('E_K_alpha (keV)')
plt.title("f((Z-1)^2)) = E_K_alpha")
plt.grid(True)
plt.legend()
plt.show()

# Get the slope and intercept of linear regression
slope_in_keV = round(model.coef_[0], 5)
intercept_in_keV = round(model.intercept_, 5)

# y = mx + n
# x = (y-n)/m
Z_minus_1_square_unknown_element = round((E_K_alpha_unknown_element_in_keV - intercept_in_keV)/slope_in_keV, 1)
print("Z_minus_1_square_unknown_element =", Z_minus_1_square_unknown_element)
Z_unknown_element = round(math.sqrt(Z_minus_1_square_unknown_element) + 1, 1)
print("Z_unknown_element =", Z_unknown_element, "(Tantalum)")

slope_in_J = round(slope_in_keV*1000*1.6*(10**-19), 21)
print("slope_in_J =", slope_in_J)
R_in_SI = round((4/3) * slope_in_J / (h_in_SI*c_in_SI), 1)
print("R_in_SI =", R_in_SI, "m^(-1)")

# Output:
# Z_minus_1_square = [841, 1681, 2401, 3025, 5329]
# 
# [image-output.png]
# Z_minus_1_square_unknown_element = 5183.8
# Z_unknown_element = 73.0 (Tantalum)
# slope_in_J = 1.632e-18
# R_in_SI = 10946775.3 m^(-1)