# -*- coding: utf-8 -*-

# Copyright notice:
# © 2025 Adrian-Gabriel Doaga. All Rights Reserved.
# Email: adriangabrieldoaga@gmail.com
# Website: https://github.com/adriangabrieldoaga/pieces-of-code
# Bibliography:
# http://www.physics.pub.ro/Referate/BN031A/Determinarea_sarcinii_specifice_a_electronului_(2016).pdf

import math
import numpy as np
import matplotlib.pyplot as plt
from sklearn.linear_model import LinearRegression

# Experimental data (the values are fabricated for demonstration purposes, but reflect the typical trends observed in real experiments)
I_experimental_t1_in_A = [1.47, 1.51, 1.49, 1.58, 1.60]
I_experimental_t2_in_A = [[0.97, 1.03, 1.10, 1.22, 1.35, 1.33, 1.43, 1.57, 1.59, 1.64],
            [1.07, 1.34, 1.40, 1.53, 1.66, 1.80, 1.83, 1.90, 1.95, 2.07],
            [1.61, 1.87, 2.05, 2.12, 2.31, 2.35, 2.57, 2.63, 2.77, 2.88],
            [2.65, 2.85, 3.16, 3.34, 3.60, 3.84, 3.97]]

# Data that is set
r_t1_in_m = 4e-2
U_t1_in_V = 160
r_t2_in_m = [5e-2, 4e-2, 3e-2, 2e-2]
U_t2_in_V = [120, 140, 160, 180, 200, 220, 240, 260, 280, 300]
R_in_m = 0.2
n = 154

# Constants
mu_0_in_SI = 4 * math.pi * 10**-7  # N*A^-2

# Experimental data processing
print("Table 1")

# Detecting the maximum number of decimal places in I_experimental_t1_in_A
decimal_places_I_experimental_t1_in_A = [len(str(I_experimental_t1_in_A_element).split('.')[1]) for I_experimental_t1_in_A_element in I_experimental_t1_in_A]  # Count decimal places after the dot
max_precision_I_experimental_t1_in_A = max(decimal_places_I_experimental_t1_in_A)  # Find the maximum precision

I_experimental_t1_in_A_count = len(I_experimental_t1_in_A)
I_average_t1_in_A = round(sum(I_experimental_t1_in_A) / I_experimental_t1_in_A_count, max_precision_I_experimental_t1_in_A)

print("I_average_t1_in_A =", I_average_t1_in_A)

sum_var = 0
for I_experimental_t1_in_A_element in I_experimental_t1_in_A:
    sum_var += (I_experimental_t1_in_A_element - I_average_t1_in_A)**2

sigma_I_average_t1_in_A = round(math.sqrt(sum_var / (I_experimental_t1_in_A_count * (I_experimental_t1_in_A_count - 1))), 3)
print("sigma_I_average_t1_in_A =", sigma_I_average_t1_in_A)

epsilon_I_average_t1 = round(sigma_I_average_t1_in_A / I_average_t1_in_A, 3)
print("epsilon_I_average_t1 =", epsilon_I_average_t1)

B_t1_in_T = round((4/5)**(3/2) * mu_0_in_SI * n * (I_average_t1_in_A / R_in_m), 6)
print(f"B_t1_in_T = {B_t1_in_T:.2e}")

e_over_m_ratio_t1_in_SI = round((125 / 32) * (R_in_m**2 / (mu_0_in_SI**2 * n**2)) * (U_t1_in_V / (r_t1_in_m**2 * I_average_t1_in_A**2)), -9)
print(f"e_over_m_ratio_t1_in_SI = {e_over_m_ratio_t1_in_SI:.2e} C/kg")

epsilon_e_over_m_ratio_t1 = 2 * epsilon_I_average_t1
print("epsilon_e_over_m_ratio_t1 =", epsilon_e_over_m_ratio_t1)

sigma_e_over_m_ratio_t1_in_SI = epsilon_e_over_m_ratio_t1 * e_over_m_ratio_t1_in_SI
print(f"sigma_e_over_m_ratio_t1_in_SI = {sigma_e_over_m_ratio_t1_in_SI:.1e} C/kg\n")


print("Table 2")

e_over_m_ratio_t2_in_SI = []
for r_t2_in_m_index, r_t2_in_m_element in enumerate(r_t2_in_m):
    e_over_m_ratio_t2_in_SI_element = []
    for U_t2_in_V_index, U_t2_in_V_element in enumerate(U_t2_in_V):
        if U_t2_in_V_index < len(I_experimental_t2_in_A[r_t2_in_m_index]):  # Some sublists in I_experimental_t2_in_A are shorter
            I_experimental_t2_in_A_element = I_experimental_t2_in_A[r_t2_in_m_index][U_t2_in_V_index]
            if I_experimental_t2_in_A_element != 0:  # Avoid division by zero
                e_over_m_ratio_t2_in_SI_element.append(round((125 / 32) * (R_in_m**2 / (mu_0_in_SI**2 * n**2)) * (U_t2_in_V_element / (r_t2_in_m_element**2 * I_experimental_t2_in_A_element**2)), -9))
            else:
                e_over_m_ratio_t2_in_SI_element.append(np.nan)  # In case of 0 current
        else:
            e_over_m_ratio_t2_in_SI_element.append(np.nan)  # No data available for some U
    e_over_m_ratio_t2_in_SI.append(e_over_m_ratio_t2_in_SI_element)

print("e_over_m_ratio_t2_in_SI_formatted:")
for e_over_m_ratio_t2_in_SI_element in e_over_m_ratio_t2_in_SI:
    e_over_m_ratio_t2_in_SI_formatted_row = [f"{e_over_m_ratio_t2_in_SI_element_element:.2e}" if not np.isnan(e_over_m_ratio_t2_in_SI_element_element) else 'nan' for e_over_m_ratio_t2_in_SI_element_element in e_over_m_ratio_t2_in_SI_element]
    print(e_over_m_ratio_t2_in_SI_formatted_row, "C/kg")

# Calculate average while ignoring nan values
sum_var = 0
count = 0
for e_over_m_ratio_t2_in_SI_index in range(len(e_over_m_ratio_t2_in_SI)):
    for e_over_m_ratio_t2_in_SI_element_index in range(len(e_over_m_ratio_t2_in_SI[e_over_m_ratio_t2_in_SI_index])):
        if not np.isnan(e_over_m_ratio_t2_in_SI[e_over_m_ratio_t2_in_SI_index][e_over_m_ratio_t2_in_SI_element_index]):
            sum_var += e_over_m_ratio_t2_in_SI[e_over_m_ratio_t2_in_SI_index][e_over_m_ratio_t2_in_SI_element_index]
            count += 1

e_over_m_ratio_average_t2_in_SI = round(sum_var / count, -9)
print(f"e_over_m_ratio_average_t2_in_SI = {e_over_m_ratio_average_t2_in_SI:.2e} C/kg")

# Calculate standard deviation while ignoring NaNs
sum_var = 0
for e_over_m_ratio_t2_in_SI_index in range(len(e_over_m_ratio_t2_in_SI)):
    for e_over_m_ratio_t2_in_SI_element_index in range(len(e_over_m_ratio_t2_in_SI[e_over_m_ratio_t2_in_SI_index])):
        if not np.isnan(e_over_m_ratio_t2_in_SI[e_over_m_ratio_t2_in_SI_index][e_over_m_ratio_t2_in_SI_element_index]):
            sum_var += (e_over_m_ratio_t2_in_SI[e_over_m_ratio_t2_in_SI_index][e_over_m_ratio_t2_in_SI_element_index] - e_over_m_ratio_average_t2_in_SI)**2

sigma_e_over_m_ratio_average_t2_in_SI = round(math.sqrt(sum_var / (count * (count - 1))), -7)
print(f"sigma_e_over_m_ratio_average_t2_in_SI = {sigma_e_over_m_ratio_average_t2_in_SI:.1e} C/kg")

epsilon_e_over_m_ratio_average_t1 = round(sigma_e_over_m_ratio_average_t2_in_SI / e_over_m_ratio_average_t2_in_SI, 3)
print(f"epsilon_e_over_m_ratio_average_t1 = {epsilon_e_over_m_ratio_average_t1:.1e}")

# Linear regression for each r value
slopes_t2_p1_in_SI = []
plt.figure(figsize=(12, 12))
for r_t2_in_m_index in range(len(r_t2_in_m)):
    # Calculate U/r^2
    U_over_r2_in_SI = np.array(U_t2_in_V) / (r_t2_in_m[r_t2_in_m_index] ** 2)
    
    # Get valid data for current sublist
    valid_I_squared_in_SI = [I_experimental_t2_in_A_element_element**2 for I_experimental_t2_in_A_element_element in I_experimental_t2_in_A[r_t2_in_m_index] if I_experimental_t2_in_A_element_element != 0]
    valid_U_over_r2_in_SI = U_over_r2_in_SI[:len(valid_I_squared_in_SI)]
    
    # Perform linear regression only if data is available
    if len(valid_U_over_r2_in_SI) > 0:
        valid_U_over_r2_in_SI = np.array(valid_U_over_r2_in_SI).reshape(-1, 1)  # Reshape for linear regression
        model = LinearRegression()
        model.fit(valid_U_over_r2_in_SI, valid_I_squared_in_SI)
        
        # Store the slope
        slopes_t2_p1_in_SI.append(round(model.coef_[0], 7))
        
        # Plot the points and the regression line
        plt.scatter(valid_U_over_r2_in_SI, valid_I_squared_in_SI, label=f'Points r = {r_t2_in_m[r_t2_in_m_index] * 100:.0f} cm')  # Convert r to cm in the legend
        plt.plot(valid_U_over_r2_in_SI, model.predict(valid_U_over_r2_in_SI), label=f'Graph r = {r_t2_in_m[r_t2_in_m_index] * 100:.0f} cm, slope = {slopes_t2_p1_in_SI[r_t2_in_m_index]:.2e} A^2 * m^2 / V')

# Scientific notation for x-axis
plt.ticklabel_format(style='sci', axis='x', scilimits=(0, 0))

plt.xlabel('U/r^2 (V/m^2)')
plt.ylabel('I^2 (A^2)')
plt.title('f(U/r^2) = I^2')
plt.legend()
plt.grid(True)
plt.show()

# Calculate the e/m ratio based on slopes
e_over_m_ratio_t2_p1_in_SI = []
for slopes_t2_p1_in_SI_element in slopes_t2_p1_in_SI:
    e_over_m_ratio_t2_p1_in_SI.append(round((125 / 32) * (R_in_m**2 / (mu_0_in_SI**2 * n**2)) * (1 / slopes_t2_p1_in_SI_element), -9))

print("\ne_over_m_ratio_t2_p1_in_SI:")
for r_t2_in_m_element, e_over_m_ratio_t2_p1_in_SI_element in zip(r_t2_in_m, e_over_m_ratio_t2_p1_in_SI):
    print(f"{e_over_m_ratio_t2_p1_in_SI_element:.2e} C/kg for r = {r_t2_in_m_element*100:.0f} cm")

# Calculate the average of e/m ratios based on slopes
e_over_m_ratio_average_t2_p1_in_SI = sum(e_over_m_ratio_t2_p1_in_SI) / len(e_over_m_ratio_t2_p1_in_SI)
print(f"e_over_m_ratio_average_t2_p1_in_SI = {e_over_m_ratio_average_t2_p1_in_SI:.2e} C/kg")


# Linear regression for U = 140 V
U_t2_p2_in_V = 140
plt.figure(figsize=(7, 7))
# Select the column of I_experimental_t2_in_A corresponding to U = 140 V (second element, index 1)
I_in_A_at_U_140V = [I_experimental_t2_in_A_element[1] for I_experimental_t2_in_A_element in I_experimental_t2_in_A]

# Calculate 1/r for each r value
one_over_r_in_SI = [1/r_t2_in_m_element for r_t2_in_m_element in r_t2_in_m]

# Reshape one_over_r_in_SI for linear regression
one_over_r_in_SI = np.array(one_over_r_in_SI).reshape(-1, 1)

# Perform linear regression
model = LinearRegression()
model.fit(one_over_r_in_SI, I_in_A_at_U_140V)

# Get the slope
slope_t2_p2_in_SI = round(model.coef_[0], 4)

# Plotting
plt.scatter(one_over_r_in_SI, I_in_A_at_U_140V, color='blue', label='Points r')
plt.plot(one_over_r_in_SI, model.predict(one_over_r_in_SI), color='red', label=f'Graph, slope = {slope_t2_p2_in_SI:.2e} A * m')

# Labels and title
plt.xlabel('1/r (1/m)')
plt.ylabel('I (A)')
plt.title('f(1/r) = I at U = 140 V')
plt.legend()
plt.grid(True)
plt.show()

e_over_m_ratio_t2_p2_in_SI = round((125 / 32) * (R_in_m**2 / (mu_0_in_SI**2 * n**2)) * (U_t2_p2_in_V / (slope_t2_p2_in_SI**2)), -9)
print(f"e_over_m_ratio_t2_p2_in_SI = {e_over_m_ratio_t2_p2_in_SI:.2e} C/kg")

# Output:
# Table 1
# I_average_t1_in_A = 1.53
# sigma_I_average_t1_in_A = 0.025
# epsilon_I_average_t1 = 0.016
# B_t1_in_T = 1.06e-03
# e_over_m_ratio_t1_in_SI = 1.78e+11 C/kg
# epsilon_e_over_m_ratio_t1 = 0.032
# sigma_e_over_m_ratio_t1_in_SI = 5.7e+09 C/kg
# 
# Table 2
# e_over_m_ratio_t2_in_SI_formatted:
# ['2.13e+11', '2.20e+11', '2.21e+11', '2.02e+11', '1.83e+11', '2.08e+11', '1.96e+11', '1.76e+11', '1.85e+11', '1.86e+11'] C/kg
# ['2.73e+11', '2.03e+11', '2.13e+11', '2.01e+11', '1.89e+11', '1.77e+11', '1.87e+11', '1.88e+11', '1.92e+11', '1.83e+11'] C/kg
# ['2.15e+11', '1.86e+11', '1.76e+11', '1.86e+11', '1.74e+11', '1.85e+11', '1.68e+11', '1.74e+11', '1.69e+11', '1.68e+11'] C/kg
# ['1.78e+11', '1.80e+11', '1.67e+11', '1.68e+11', '1.61e+11', '1.56e+11', '1.59e+11', 'nan', 'nan', 'nan'] C/kg
# e_over_m_ratio_average_t2_in_SI = 1.88e+11 C/kg
# sigma_e_over_m_ratio_average_t2_in_SI = 3.7e+09 C/kg
# epsilon_e_over_m_ratio_average_t1 = 2.0e-02
# 
# [image-output-1.png]
# 
# e_over_m_ratio_t2_p1_in_SI:
# 1.62e+11 C/kg for r = 5 cm
# 1.59e+11 C/kg for r = 4 cm
# 1.52e+11 C/kg for r = 3 cm
# 1.38e+11 C/kg for r = 2 cm
# e_over_m_ratio_average_t2_p1_in_SI = 1.53e+11 C/kg
# 
# [image-output-2.png]
# e_over_m_ratio_t2_p2_in_SI = 1.59e+11 C/kg