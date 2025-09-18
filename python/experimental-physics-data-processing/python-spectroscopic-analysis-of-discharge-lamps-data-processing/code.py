# -*- coding: utf-8 -*-

# Copyright notice:
# © 2025 Adrian-Gabriel Doaga. All Rights Reserved.
# Email: adriangabrieldoaga@gmail.com
# Website: https://github.com/adriangabrieldoaga/pieces-of-code
# Bibliography:
# http://www.physics.pub.ro/Referate/BN031A/STRUCTURA_FINA_si_spectrele_atomilor_cu_unul_sau_cu_doi_electroni_de_valenta.pdf

import numpy as np
import matplotlib.pyplot as plt
from numpy.polynomial.polynomial import Polynomial

# Experimental data (the values are fabricated for demonstration purposes, but reflect the typical trends observed in real experiments)
theta_just_degrees_experimental_He = [118, 119, 119, 120, 120, 120, 121, 122, 123, 123]
theta_just_minutes_experimental_He = [57, 7, 41, 45, 47, 55, 48, 2, 3, 39]
theta_just_degrees_experimental_Cd = [119, 119, 120, 121, 121, 122]
theta_just_minutes_experimental_Cd = [19, 23, 37, 5, 21, 1]

# Data that is set
lambda_He_in_m = [706.5e-9, 667.8e-9, 587.6e-9, 501.6e-9, 492.2e-9, 471.3e-9, 447.1e-9, 438.8e-9, 402.6e-9, 396.5e-9]

# Experimental data processing

# Convert angles to decimal degrees
def convert_to_decimal_degrees(degrees, minutes):
    return [round(degrees_element + minutes_element / 60, 2) for degrees_element, minutes_element in zip(degrees, minutes)]

theta_degrees_experimental_He = convert_to_decimal_degrees(theta_just_degrees_experimental_He, theta_just_minutes_experimental_He)
theta_degrees_experimental_Cd = convert_to_decimal_degrees(theta_just_degrees_experimental_Cd, theta_just_minutes_experimental_Cd)

print("theta_degrees_experimental_He =", theta_degrees_experimental_He)
print("theta_degrees_experimental_Cd =", theta_degrees_experimental_Cd)

lambda_He_in_nm = [lambda_He_in_m_element * (10**9) for lambda_He_in_m_element in lambda_He_in_m]

# Interpolate the data using k-th degree polynomial
k = 4
interpolation_coefficients = Polynomial.fit(theta_degrees_experimental_He, lambda_He_in_nm, k).convert().coef

# Create a polynomial function
def interpolate_polynomial(interpolation_coefficients):
    return lambda x: sum(c * x**i for i, c in enumerate(interpolation_coefficients))

polynomial = interpolate_polynomial(interpolation_coefficients)

# Calculate lambda_Cd_in_nm for the given Cd angles
lambda_Cd_in_nm = [polynomial(theta_degrees_experimental_Cd_element) for theta_degrees_experimental_Cd_element in theta_degrees_experimental_Cd]

# Plot the helium data and interpolation
plt.figure(figsize=(12, 7))

# Plot the original helium data
plt.scatter(theta_degrees_experimental_He, lambda_He_in_nm, color='blue', label='Experimental points for helium', zorder=5)

# Plot the interpolated function
theta_experimental_smooth = np.linspace(min(theta_degrees_experimental_He), max(theta_degrees_experimental_He), 1000)
lambda_in_nm_smooth = [polynomial(theta_experimental_smooth_element) for theta_experimental_smooth_element in theta_experimental_smooth]
plt.plot(theta_experimental_smooth, lambda_in_nm_smooth, color='red', label=f'{k}-degree polynomial fit')

# Plot the cadmium points
plt.scatter(theta_degrees_experimental_Cd, lambda_Cd_in_nm, color='green', label='Interpolated points for cadmium', zorder=5)

# Labels and legend
plt.title("f(θ) = λ")
plt.xlabel("θ (°)")
plt.ylabel("λ (nm)")
plt.legend()
plt.grid(True)
plt.show()

lambda_Cd_in_nm = [round(lambda_Cd_in_nm_element, 2) for lambda_Cd_in_nm_element in lambda_Cd_in_nm]
print("\nlambda_Cd_in_nm:", lambda_Cd_in_nm)

# Output:
# theta_degrees_experimental_He = [118.95, 119.12, 119.68, 120.75, 120.78, 120.92, 121.8, 122.03, 123.05, 123.65]
# theta_degrees_experimental_Cd = [119.32, 119.38, 120.62, 121.08, 121.35, 122.02]
# 
# [image-output.png]
# 
# lambda_Cd_in_nm: [636.35, 626.9, 501.32, 475.68, 463.17, 436.74]