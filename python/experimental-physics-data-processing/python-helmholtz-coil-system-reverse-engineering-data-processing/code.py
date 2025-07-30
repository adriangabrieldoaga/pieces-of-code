# -*- coding: utf-8 -*-

# Copyright notice:
# © 2025 Adrian-Gabriel Doaga. All Rights Reserved.
# Email: adriangabrieldoaga@gmail.com
# Website: https://github.com/adriangabrieldoaga/pieces-of-code

# Characterize the provided Helmholtz coil system.
# Objectives:
# 1. Perform an analysis procedure for the given system. Identify the system elements, the operating mode and the operating parameters;
# 2. Map the magnetic field obtained with the given system;
# 3. Determine the parameters of the coils;
# 4. Design a Helmholtz coil system that can produce a constant magnetic field of 5mT.

import numpy as np
import matplotlib.pyplot as plt
from sklearn.linear_model import LinearRegression

# Experimental data (the values are fabricated for demonstration purposes, but reflect the typical trends observed in real experiments)
B_experimental_in_mT = [0.28, 0.33, 0.35, 0.36, 0.37, 0.41, 0.43, 0.45, 0.46, 0.50, 0.51, 0.53, 0.55, 0.59, 0.61, 0.64, 0.68]
B_along_axis_experimental_in_mT = [0.07, 0.10, 0.13, 0.25, 0.36, 0.48, 0.50, 0.49, 0.36, 0.24, 0.14, 0.11, 0.07]

# Data that is set
I_in_A = [1.15, 1.20, 1.25, 1.30, 1.35, 1.40, 1.45, 1.50, 1.55, 1.60, 1.65, 1.70, 1.75, 1.80, 1.85, 1.90, 1.95]
R_in_m = 0.15
d_in_m = 0.15
B_design_in_T = 5e-3
z_in_m = [-0.30, -0.25, -0.20, -0.15, -0.10, -0.05, 0, 0.05, 0.10, 0.15, 0.20, 0.25, 0.30]

# Constants
pi = 3.14
mu_0_in_SI = 4 * pi * (10**-7)  # N*A^-2

# Reshape I for linear regression
I_in_A = np.array(I_in_A).reshape(-1, 1)

# Perform linear regression
model_1 = LinearRegression()
model_1.fit(I_in_A, B_experimental_in_mT)
plt.figure(figsize=(7, 7))
plt.scatter(I_in_A, B_experimental_in_mT, color='blue')
plt.plot(I_in_A, model_1.predict(I_in_A), color='blue', label=f'Experimental: slope = {round(model_1.coef_[0], 3)} mT/A, intercept = {round(model_1.intercept_, 3)} mT')  # Include slope and intercept in label

# Get the slope and intercept of linear regression
slope_in_mT_over_A = round(model_1.coef_[0], 3)
intercept_in_mT = round(model_1.intercept_, 3)

slope_in_SI = slope_in_mT_over_A*(10**-3)
intercept_in_T = intercept_in_mT*(10**-3)

# y = slope*x + intercept
n = round((slope_in_SI*R_in_m/mu_0_in_SI) / ((4/5)**(3/2)), 1) # the number of turns in each coil
print("n =", n, "turns ≈", int(round(n, 0)), "turns")
n = int(round(n, 0))

# x = (y-intercept)/slope
I_design_in_A = round((B_design_in_T - intercept_in_T)/slope_in_SI, 2)
print("I_design_in_A =", I_design_in_A)

# Theoretical B-field calculation (on axis at the midpoint of Helmholtz coils)
def theoretical_B_midpoint(I, n, R, d):
    return (((4/5)**(3/2))*mu_0_in_SI*n*I/R)

# Calculate theoretical B-field values for the given currents
B_theoretical_in_mT = theoretical_B_midpoint(I_in_A, n, R_in_m, d_in_m) * (10**3)

# Perform linear regression
model_2 = LinearRegression()
model_2.fit(I_in_A, B_theoretical_in_mT)
plt.scatter(I_in_A, B_theoretical_in_mT, color='red', marker='s')
plt.plot(I_in_A, model_2.predict(I_in_A), color='red', label=f"Theoretical with {n} turns")

# Labels and title
plt.xlabel('I (A)')
plt.ylabel('B (mT)')
plt.title("f(I) = B")
plt.grid(True)
plt.legend()
plt.show()

B_theoretical_in_mT_formatted = np.array_str(B_theoretical_in_mT, precision=2, suppress_small=True)
print("B_theoretical_in_mT_formatted =", B_theoretical_in_mT_formatted)

I_design_2_in_A = 5
R_design_in_m = ((4/5)**(3/2))*mu_0_in_SI*n*I_design_2_in_A/B_design_in_T
R_design_in_cm = round(R_design_in_m*100, 2)
print("\nR_design_in_cm =", R_design_in_cm)

# Theoretical B-field calculation (along the axis of Helmholtz coils)
def theoretical_B_along_axis(z, I, N, R, d):
    # Contribution of each coil to the magnetic field
    z1 = z - d / 2  # Position relative to coil 1
    z2 = z + d / 2  # Position relative to coil 2
    B1 = (mu_0_in_SI * N * I * R**2) / (2 * ((R**2 + z1**2)**(3/2)))
    B2 = (mu_0_in_SI * N * I * R**2) / (2 * ((R**2 + z2**2)**(3/2)))
    return B1 + B2

# Calculate the theoretical points of magnetic field along the axis for a representative current (I = 1.5 A)
I_map_in_A = 1.5
B_along_axis_theoretical = [theoretical_B_along_axis(z_in_m_element, I_map_in_A, n, R_in_m, d_in_m) for z_in_m_element in z_in_m]

# Convert to mT for plotting
B_along_axis_theoretical_in_mT = np.array(B_along_axis_theoretical) * (10**3)

z_in_cm = [z_in_m_element * 100 for z_in_m_element in z_in_m]

# Plot the magnetic field distribution along the axis
plt.figure(figsize=(12, 7))
plt.plot(z_in_cm, B_along_axis_experimental_in_mT, label="Experimental")
plt.plot(z_in_cm, B_along_axis_theoretical_in_mT, label=f"Theoretical with {n} turns")
plt.axvline(-d_in_m / 2 * 100, color='red', linestyle='--', label="Positions of Helmholtz coils")
plt.axvline(d_in_m / 2 * 100, color='red', linestyle='--')

plt.xlabel("z (cm)", fontsize=12)
plt.ylabel("B (mT)", fontsize=12)
plt.title(f"f(z) = B at I = {I_map_in_A} A", fontsize=14)
plt.legend(fontsize=12)
plt.grid()
plt.show()

B_along_axis_theoretical_in_mT_formatted = np.array_str(B_along_axis_theoretical_in_mT, precision=2, suppress_small=True)
print("B_along_axis_theoretical_in_mT_formatted =", B_along_axis_theoretical_in_mT_formatted)

# Calculate the smooth magnetic field along the axis for a representative current (I = 1.5 A)
z_smooth_in_m = np.linspace(-0.3, 0.3, 1000)
B_along_axis_theoretical_smooth_in_T = [theoretical_B_along_axis(z_smooth_in_m_element, I_map_in_A, n, R_in_m, d_in_m) for z_smooth_in_m_element in z_smooth_in_m]

# Convert z to centimeters
z_smooth_in_cm = z_smooth_in_m * 100

# Convert B field to mT for plotting
B_along_axis_theoretical_smooth_in_mT = np.array(B_along_axis_theoretical_smooth_in_T) * 1e3

# Plot the magnetic field distribution along the axis
plt.figure(figsize=(12, 7))
plt.plot(z_in_cm, B_along_axis_experimental_in_mT, label="Experimental")
plt.plot(z_smooth_in_cm, B_along_axis_theoretical_smooth_in_mT, label=f"Theoretical smooth with {n} turns")
plt.axvline(-d_in_m / 2 * 100, color='red', linestyle='--', label="Positions of Helmholtz coils")
plt.axvline(d_in_m / 2 * 100, color='red', linestyle='--')
plt.xlabel("z (cm)", fontsize=12)
plt.ylabel("B (mT)", fontsize=12)
plt.title(f"f(z) = B at I = {I_map_in_A} A", fontsize=14)
plt.legend(fontsize=12)
plt.grid()
plt.show()

# Output:
# n = 76.6 turns ≈ 77 turns
# I_design_in_A = 11.41
# 
# [image-output-1.png]
# B_theoretical_in_mT_formatted = [[0.53]
#  [0.55]
#  [0.58]
#  [0.6 ]
#  [0.62]
#  [0.65]
#  [0.67]
#  [0.69]
#  [0.72]
#  [0.74]
#  [0.76]
#  [0.78]
#  [0.81]
#  [0.83]
#  [0.85]
#  [0.88]
#  [0.9 ]]
# 
# R_design_in_cm = 6.92
# 
# [image-output-2.png]
# B_along_axis_theoretical_in_mT_formatted = [0.11 0.17 0.27 0.43 0.6  0.68 0.69 0.68 0.6  0.43 0.27 0.17 0.11]
# 
# [image-output-3.png]