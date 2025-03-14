# -*- coding: utf-8 -*-

# Copyright notice:
# © 2025 Adrian-Gabriel Doaga. All Rights Reserved.
# Email: adriangabrieldoaga@gmail.com
# Website: https://github.com/adriangabrieldoaga/pieces-of-code
# Bibliography:
# http://www.physics.pub.ro/Referate/BN031A/Studiul_unor_legi_ale_RADIATIEI_TERMICE.pdf

import math
import numpy as np
import matplotlib.pyplot as plt
from numpy.polynomial.polynomial import Polynomial

# Experimental data (the values are fabricated for demonstration purposes, but reflect the typical trends observed in real experiments)
Y_8V_t2 = [10, 20, 80, 240, 320, 350, 600, 1800, 4000, 6000] # div
Y_10V_t2 = [30, 110, 150, 260, 800, 1000, 1600, 4500, 8000, 12000] # div
Y_12V_t2 = [60, 220, 370, 800, 1100, 1800, 2000, 8200, 15000, 21000] # div

# Data that is set
lambda_t1_in_m = [383e-9, 463e-9, 510e-9, 534e-9, 553e-9, 591e-9, 620e-9, 674e-9, 771e-9, 791e-9]
epsilon_t1 = [0.46, 0.46, 0.45, 0.44, 0.44, 0.44, 0.43, 0.43, 0.42, 0.41]
U_t2_in_V = [8, 10, 12]

# Constants
U_prime_1_t2_in_V = 8
U_prime_2_t2_in_V = 10
U_et_t2_in_V = 12
T_et_t2_in_K = 3150
h_in_SI = 6.626e-34 # J*s; Planck's constant
c_in_SI = 3e8 # m/s; Speed of light in vacuum
k_B_in_SI = 1.381e-23 # J/K; Boltzmann constant
b_in_SI = 2.9e-3; # m*K; Wien's displacement constant

# Create a polynomial function
def interpolate_polynomial(interpolation_coefficients):
    return lambda x: sum(c * x**i for i, c in enumerate(interpolation_coefficients))

# Experimental data processing
print("Table 2")
lambda_t1_in_nm =[lambda_t1_in_m_element*(10**9) for lambda_t1_in_m_element in lambda_t1_in_m]

# Plot the data and interpolation
plt.figure(figsize=(7, 8))

# Interpolate the data using k-th degree polynomial
k = 3

for U_t2_in_V_element in U_t2_in_V:
    if (U_t2_in_V_element == 8):
        interpolation_coefficients = Polynomial.fit(lambda_t1_in_nm, Y_8V_t2, k).convert().coef
    elif (U_t2_in_V_element == 10):
        interpolation_coefficients = Polynomial.fit(lambda_t1_in_nm, Y_10V_t2, k).convert().coef
    elif (U_t2_in_V_element == 12):
        interpolation_coefficients = Polynomial.fit(lambda_t1_in_nm, Y_12V_t2, k).convert().coef
        
    polynomial = interpolate_polynomial(interpolation_coefficients)
    
    # Experimental points
    if (U_t2_in_V_element == 8): 
        plt.scatter(lambda_t1_in_nm, Y_8V_t2, color='red', label=f'Experimental points U = {U_t2_in_V_element} V', zorder=5)
    elif (U_t2_in_V_element == 10): 
        plt.scatter(lambda_t1_in_nm, Y_10V_t2, color='blue', label=f'Experimental points U = {U_t2_in_V_element} V', zorder=5)
    elif (U_t2_in_V_element == 12): 
        plt.scatter(lambda_t1_in_nm, Y_12V_t2, color='green', label=f'Experimental points U = {U_t2_in_V_element} V', zorder=5)
    
    # Plot the interpolated function
    lambda_t1_in_nm_smooth = np.linspace(min(lambda_t1_in_nm), max(lambda_t1_in_nm), 1000)
    if (U_t2_in_V_element == 8):
        Y_8V_t2_smooth = [polynomial(lambda_t1_in_nm_smooth_element) for lambda_t1_in_nm_smooth_element in lambda_t1_in_nm_smooth]
        plt.plot(lambda_t1_in_nm_smooth, Y_8V_t2_smooth, color='red', label=f'Graph U = {U_t2_in_V_element} V')
        # plt.plot(lambda_t1_in_nm_smooth, Y_8V_t2_smooth, color='red', label=f'{k}-degree Polynomial Fit')
    elif (U_t2_in_V_element == 10):
        Y_10V_t2_smooth = [polynomial(lambda_t1_in_nm_smooth_element) for lambda_t1_in_nm_smooth_element in lambda_t1_in_nm_smooth]
        plt.plot(lambda_t1_in_nm_smooth, Y_10V_t2_smooth, color='blue', label=f'Graph U = {U_t2_in_V_element} V')
        # plt.plot(lambda_t1_in_nm_smooth, Y_10V_t2_smooth, color='red', label=f'{k}-degree Polynomial Fit')
    elif (U_t2_in_V_element == 12):
        Y_12V_t2_smooth = [polynomial(lambda_t1_in_nm_smooth_element) for lambda_t1_in_nm_smooth_element in lambda_t1_in_nm_smooth]
        plt.plot(lambda_t1_in_nm_smooth, Y_12V_t2_smooth, color='green', label=f'Graph U = {U_t2_in_V_element} V')
        # plt.plot(lambda_t1_in_nm_smooth, Y_12V_t2_smooth, color='red', label=f'{k}-degree Polynomial Fit')
    
# Labels and legend
plt.title("f(λ) = Y")
plt.xlabel("λ (nm)")
plt.ylabel("Y (div)")
plt.legend()
plt.grid(True)
plt.show()

T_prime_1_t2_in_K = round((U_prime_1_t2_in_V * (T_et_t2_in_K**4) / U_et_t2_in_V) ** (1/4), 1)
T_prime_2_t2_in_K = round((U_prime_2_t2_in_V * (T_et_t2_in_K**4) / U_et_t2_in_V) ** (1/4), 1)
print("\nT_prime_1_t2_in_K =", T_prime_1_t2_in_K)
print("T_prime_2_t2_in_K =", T_prime_2_t2_in_K, "\n")

T_t2_in_K = [T_prime_1_t2_in_K, T_prime_2_t2_in_K, T_et_t2_in_K]

for lambda_t1_in_m_element, epsilon_t1_element, Y_8V_t2_element, Y_10V_t2_element, Y_12V_t2_element in zip(lambda_t1_in_m, epsilon_t1, Y_8V_t2, Y_10V_t2, Y_12V_t2):
    print("Computations for", lambda_t1_in_m_element, "m:")
    left_member_line_t2 = []
    for U_t2_in_V_element, T_t2_in_K_element in zip(U_t2_in_V, T_t2_in_K):
        print("Computations for", U_t2_in_V_element, "V:")
        hc_on_lambda_k_B_T_t2 = round(h_in_SI*c_in_SI/(lambda_t1_in_m_element*k_B_in_SI*T_t2_in_K_element), 5)
        print("hc_on_lambda_k_B_T_t2 =", hc_on_lambda_k_B_T_t2)
        f_lambda_T = round(math.exp(hc_on_lambda_k_B_T_t2) - 1, 5)
        print("f(λ, T) =", f_lambda_T)
        if (U_t2_in_V_element == 8):
            left_member_t2 = round((lambda_t1_in_m_element**5)*(f_lambda_T/epsilon_t1_element)*Y_8V_t2_element, 31)
            left_member_line_t2.append(left_member_t2)
        elif (U_t2_in_V_element == 10):
            left_member_t2 = round((lambda_t1_in_m_element**5)*(f_lambda_T/epsilon_t1_element)*Y_10V_t2_element, 31)
            left_member_line_t2.append(left_member_t2)
        elif (U_t2_in_V_element == 12):
            left_member_t2 = round((lambda_t1_in_m_element**5)*(f_lambda_T/epsilon_t1_element)*Y_12V_t2_element, 31)
            left_member_line_t2.append(left_member_t2)
        print("left_member_t2 =", left_member_t2, "m^5*div")
        
    left_member_line_t2_count = len(left_member_line_t2)
    left_member_line_t2_average = round(sum(left_member_line_t2)/left_member_line_t2_count, 31)
    print("left_member_line_t2_average =", left_member_line_t2_average, "m^5*div")
    
    sum_var = 0
    for left_member_line_t2_element in left_member_line_t2:
        sum_var += (left_member_line_t2_element - left_member_line_t2_average)**2

    sigma_left_member_line_t2_average = round(math.sqrt(sum_var / (left_member_line_t2_count * (left_member_line_t2_count - 1))), 31)
    print("sigma_left_member_line_t2_average =", sigma_left_member_line_t2_average, "m^5*div")
    sigma_left_member_line_t2_average_percentage = round((sigma_left_member_line_t2_average/left_member_line_t2_average)*100, 2)
    print("sigma_left_member_line_t2_average_percentage =", sigma_left_member_line_t2_average_percentage, "%")
    left_member_line_t2_error_relative_to_average_value = []
    for left_member_line_t2_element in left_member_line_t2:
        left_member_line_t2_error_relative_to_average_value.append(round((abs(left_member_line_t2_element-left_member_line_t2_average)/left_member_line_t2_average)*100, 2))
    print("left_member_line_t2_error_relative_to_average_value =", left_member_line_t2_error_relative_to_average_value , "%\n")

lambda_n_in_m = []
for T_t2_in_K_element in T_t2_in_K:
    lambda_n_in_m.append(b_in_SI/T_t2_in_K_element)
lambda_n_in_nm = [lambda_n_in_m_element*(10**9) for lambda_n_in_m_element in lambda_n_in_m]
print("lambda_n_in_nm =", lambda_n_in_nm)