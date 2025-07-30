# -*- coding: utf-8 -*-

# Copyright notice:
# © 2025 Adrian-Gabriel Doaga. All Rights Reserved.
# Email: adriangabrieldoaga@gmail.com
# Website: https://github.com/adriangabrieldoaga/pieces-of-code
# Bibliography:
# http://www.physics.pub.ro/Referate/BN031A/Determinarea_constantei_RYDBERG_1.pdf

import math
import numpy as np
import matplotlib.pyplot as plt
from sklearn.linear_model import LinearRegression

# Experimental data (the values are fabricated for demonstration purposes, but reflect the typical trends observed in real experiments)
x_experimental_t1_in_m = [23.4e-3, 23.9e-3, 26.2e-3, 26.7e-3, 29.2e-3, 30.4e-3, 42.3e-3, 43.2e-3, 43.3e-3, 47.7e-3, 48.4e-3]
x_experimental_t2_in_m = [20.2e-3, 35.4e-3, 43.5e-3, 47.1e-3, 50.2e-3, 59.5e-3]

# Data that is set
lambda_t1_in_m = [623.4e-9, 612.3e-9, 579.0e-9, 577.0e-9, 546.1e-9, 491.6e-9, 435.8e-9, 434.7e-9, 433.9e-9, 407.8e-9, 404.7e-9]
n_t2 = [3, 4, 5, 6, 7, 8] # cuantic atomic numbers for spectral lines of hydrogen

# Experimental data processing
x_experimental_Hg_and_H_in_m = x_experimental_t1_in_m + x_experimental_t2_in_m
x_experimental_Hg_and_H_in_m.sort()

print("Table 1")

one_over_lambda_squared_t1_in_SI = []
for lambda_t1_in_m_element in lambda_t1_in_m:
    one_over_lambda_squared_t1_in_SI.append(round(1/(lambda_t1_in_m_element**2), -9))

one_over_lambda_squared_t1_in_one_over_micrometer_squared = [one_over_lambda_squared_t1_in_SI_element * (10**-12) for one_over_lambda_squared_t1_in_SI_element in one_over_lambda_squared_t1_in_SI]
print("one_over_lambda_squared_t1_in_one_over_micrometer_squared =", one_over_lambda_squared_t1_in_one_over_micrometer_squared, "1/μm^2")

print("\nTable 2")

x_experimental_t1_in_mm = [x_experimental_t1_in_m_element * (10**3) for x_experimental_t1_in_m_element in x_experimental_t1_in_m]

# Reshape x_experimental_t1_in_mm for linear regression
x_experimental_t1_in_mm = np.array(x_experimental_t1_in_mm).reshape(-1, 1)

# Perform linear regression for mercury
model_1 = LinearRegression()
model_1.fit(x_experimental_t1_in_mm, one_over_lambda_squared_t1_in_one_over_micrometer_squared)
plt.figure(figsize=(7, 7))
plt.scatter(x_experimental_t1_in_mm, one_over_lambda_squared_t1_in_one_over_micrometer_squared, color='red')
plt.plot(x_experimental_t1_in_mm, model_1.predict(x_experimental_t1_in_mm), color='red')

# Labels and title
plt.xlabel('x (mm)')
plt.ylabel('1/λ^2 (1/μm^2)')
plt.title("f(x) = 1/λ^2 for mercury")
plt.grid(True)
plt.show()

# Get the slope and intercept of linear regression for mercury
slope_p1_Hg_in_10e15_m_minus3 = model_1.coef_[0]
intercept_p1_Hg_in_one_over_micrometer_squared = model_1.intercept_

print("slope_p1_Hg_in_10e15_m_minus3 =", round(slope_p1_Hg_in_10e15_m_minus3, 3), "* 10^15 m^-3")
print("intercept_p1_Hg_in_one_over_micrometer_squared =", round(intercept_p1_Hg_in_one_over_micrometer_squared, 3), "(1/μm^2)")

x_experimental_t2_in_mm = [x_experimental_t2_in_m_element * (10**3) for x_experimental_t2_in_m_element in x_experimental_t2_in_m]

# Compute 1/lambda^2 values for hydrogen
one_over_lambda_squared_t2_in_one_over_micrometer_squared = []
for x_experimental_t2_in_mm_element in x_experimental_t2_in_mm:
    one_over_lambda_squared_t2_in_one_over_micrometer_squared.append(slope_p1_Hg_in_10e15_m_minus3 * x_experimental_t2_in_mm_element + intercept_p1_Hg_in_one_over_micrometer_squared)

one_over_lambda_squared_Hg_and_H_in_one_over_micrometer_squared = one_over_lambda_squared_t1_in_one_over_micrometer_squared + one_over_lambda_squared_t2_in_one_over_micrometer_squared
one_over_lambda_squared_Hg_and_H_in_one_over_micrometer_squared.sort()

# Reshape x_experimental_t2_in_mm for linear regression
x_experimental_t2_in_mm = np.array(x_experimental_t2_in_mm).reshape(-1, 1)

# Perform linear regression for hydrogen
model_2 = LinearRegression()
model_2.fit(x_experimental_t2_in_mm, one_over_lambda_squared_t2_in_one_over_micrometer_squared)
plt.figure(figsize=(7, 7))
plt.scatter(x_experimental_t2_in_mm, one_over_lambda_squared_t2_in_one_over_micrometer_squared, color='blue')
plt.plot(x_experimental_t2_in_mm, model_2.predict(x_experimental_t2_in_mm), color='blue')

# Labels and title
plt.xlabel('x (mm)')
plt.ylabel('1/λ (1/μm^2)')
plt.title("f(x) = 1/λ^2 for hydrogen")
plt.grid(True)
plt.show()

plt.figure(figsize=(7, 7))

# Experimental points for mercury
plt.scatter(x_experimental_t1_in_mm, one_over_lambda_squared_t1_in_one_over_micrometer_squared, color='red', label="Mercury")

# Experimental points for hydrogen
plt.scatter(x_experimental_t2_in_mm, one_over_lambda_squared_t2_in_one_over_micrometer_squared, color='blue', label="Hydrogen")

x_experimental_Hg_and_H_in_mm = [x_experimental_Hg_and_H_in_m_element * (10**3) for x_experimental_Hg_and_H_in_m_element in x_experimental_Hg_and_H_in_m]

# Reshape x_Hg_and_H_in_mm for linear regression
x_experimental_Hg_and_H_in_mm = np.array(x_experimental_Hg_and_H_in_mm).reshape(-1, 1)

# Perform linear regression for mercury and hydrogen
model_3 = LinearRegression()
model_3.fit(x_experimental_Hg_and_H_in_mm, one_over_lambda_squared_Hg_and_H_in_one_over_micrometer_squared)
plt.plot(x_experimental_Hg_and_H_in_mm, model_3.predict(x_experimental_Hg_and_H_in_mm), color='green', )

# Labels and title
plt.xlabel('x (mm)')
plt.ylabel('1/λ^2 (1/μm^2)')
plt.title("f(x) = 1/λ^2 for mercury and hydrogen")
plt.legend()
plt.grid(True)
plt.show()

# Compute Î» values for hydrogen
one_over_lambda_squared_t2_in_SI = [one_over_lambda_squared_t2_in_one_over_micrometer_squared_element * (10**12) for one_over_lambda_squared_t2_in_one_over_micrometer_squared_element in one_over_lambda_squared_t2_in_one_over_micrometer_squared]
lambda_t2_in_m = []
for one_over_lambda_squared_t2_in_SI_element in one_over_lambda_squared_t2_in_SI:
    lambda_t2_in_m.append(round(math.sqrt(1/one_over_lambda_squared_t2_in_SI_element), 10))

lambda_t2_in_nm = [lambda_t2_in_m_element * (10**9) for lambda_t2_in_m_element in lambda_t2_in_m]
print("\nlambda_t2_in_nm =", lambda_t2_in_nm)

# Compute Rydberg's constant for hydrogen
R_H_t2_in_SI = []
for n_t2_element, lambda_t2_in_m_element in zip(n_t2, lambda_t2_in_m):
    R_H_t2_in_SI.append(round((4*(n_t2_element**2)) / (lambda_t2_in_m_element*((n_t2_element**2) - 4)), 1))
    
print("R_H_t2_in_SI = ", R_H_t2_in_SI, "m^-1")

R_H_t2_in_SI_count = len(R_H_t2_in_SI)
R_H_t2_in_SI_average = round(sum(R_H_t2_in_SI)/R_H_t2_in_SI_count, 1)
print("R_H_t2_in_SI_average =", R_H_t2_in_SI_average, "m^-1")

sum_var = 0
for R_H_t2_in_SI_element in R_H_t2_in_SI:
    sum_var += (R_H_t2_in_SI_element - R_H_t2_in_SI_average)**2

sigma_R_H_t2_in_SI_average = round(math.sqrt(sum_var / (R_H_t2_in_SI_count * (R_H_t2_in_SI_count - 1))), 1)
print("sigma_R_H_t2_in_SI_average =", sigma_R_H_t2_in_SI_average, "m^-1")
print("R_H_in_SI =", R_H_t2_in_SI_average, "±", sigma_R_H_t2_in_SI_average, "m^-1")

# Output:
# Table 1
# one_over_lambda_squared_t1_in_one_over_micrometer_squared = [2.573, 2.667, 2.983, 3.004, 3.3529999999999998, 4.138, 5.265, 5.292, 5.312, 6.013, 6.106] 1/μm^2
# 
# Table 2
# 
# [image-output-1.png]
# slope_p1_Hg_in_10e15_m_minus3 = 0.138 * 10^15 m^-3
# intercept_p1_Hg_in_one_over_micrometer_squared = -0.572 (1/μm^2)
# 
# [image-output-2.png]
# 
# [image-output-3.png]
# 
# lambda_t2_in_nm = [672.5, 482.0, 429.5, 411.1, 397.0, 362.09999999999997]
# R_H_t2_in_SI =  [10706319.7, 11065006.9, 11087089.1, 10946241.8, 10971172.7, 11783117.0] m^-1
# R_H_t2_in_SI_average = 11093157.9 m^-1
# sigma_R_H_t2_in_SI_average = 148658.6 m^-1
# R_H_in_SI = 11093157.9 ± 148658.6 m^-1
