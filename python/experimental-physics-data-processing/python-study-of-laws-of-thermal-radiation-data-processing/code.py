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
        hc_over_lambda_k_B_T_t2 = round(h_in_SI*c_in_SI/(lambda_t1_in_m_element*k_B_in_SI*T_t2_in_K_element), 5)
        print("hc_over_lambda_k_B_T_t2 =", hc_over_lambda_k_B_T_t2)
        f_lambda_T = round(math.exp(hc_over_lambda_k_B_T_t2) - 1, 5)
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

# Output:
# Table 2
# 
# [image-output.png]
# 
# T_prime_1_t2_in_K = 2846.3
# T_prime_2_t2_in_K = 3009.6 
# 
# Computations for 3.83e-07 m:
# Computations for 8 V:
# hc_over_lambda_k_B_T_t2 = 13.20382
# f(λ, T) = 542432.07894
# left_member_t2 = 9.7181e-26 m^5*div
# Computations for 10 V:
# hc_over_lambda_k_B_T_t2 = 12.48738
# f(λ, T) = 264971.14865
# left_member_t2 = 1.42415e-25 m^5*div
# Computations for 12 V:
# hc_over_lambda_k_B_T_t2 = 11.9308
# f(λ, T) = 151872.0115
# left_member_t2 = 1.632545e-25 m^5*div
# left_member_line_t2_average = 1.342835e-25 m^5*div
# sigma_left_member_line_t2_average = 1.95023e-26 m^5*div
# sigma_left_member_line_t2_average_percentage = 14.52 %
# left_member_line_t2_error_relative_to_average_value = [27.63, 6.06, 21.57] %
# 
# Computations for 4.63e-07 m:
# Computations for 8 V:
# hc_over_lambda_k_B_T_t2 = 10.92238
# f(λ, T) = 55401.50011
# left_member_t2 = 5.12506e-26 m^5*div
# Computations for 10 V:
# hc_over_lambda_k_B_T_t2 = 10.32974
# f(λ, T) = 30629.14703
# left_member_t2 = 1.558385e-25 m^5*div
# Computations for 12 V:
# hc_over_lambda_k_B_T_t2 = 9.86933
# f(λ, T) = 19327.38462
# left_member_t2 = 1.966722e-25 m^5*div
# left_member_line_t2_average = 1.345871e-25 m^5*div
# sigma_left_member_line_t2_average = 4.33035e-26 m^5*div
# sigma_left_member_line_t2_average_percentage = 32.18 %
# left_member_line_t2_error_relative_to_average_value = [61.92, 15.79, 46.13] %
# 
# Computations for 5.1e-07 m:
# Computations for 8 V:
# hc_over_lambda_k_B_T_t2 = 9.91581
# f(λ, T) = 20246.97363
# left_member_t2 = 1.241905e-25 m^5*div
# Computations for 10 V:
# hc_over_lambda_k_B_T_t2 = 9.37778
# f(λ, T) = 11821.73912
# left_member_t2 = 1.3596e-25 m^5*div
# Computations for 12 V:
# hc_over_lambda_k_B_T_t2 = 8.9598
# f(λ, T) = 7782.80055
# left_member_t2 = 2.207883e-25 m^5*div
# left_member_line_t2_average = 1.603129e-25 m^5*div
# sigma_left_member_line_t2_average = 3.0428e-26 m^5*div
# sigma_left_member_line_t2_average_percentage = 18.98 %
# left_member_line_t2_error_relative_to_average_value = [22.53, 15.19, 37.72] %
# 
# Computations for 5.34e-07 m:
# Computations for 8 V:
# hc_over_lambda_k_B_T_t2 = 9.47015
# f(λ, T) = 12965.83211
# left_member_t2 = 3.070897e-25 m^5*div
# Computations for 10 V:
# hc_over_lambda_k_B_T_t2 = 8.95631
# f(λ, T) = 7755.68243
# left_member_t2 = 1.989972e-25 m^5*div
# Computations for 12 V:
# hc_over_lambda_k_B_T_t2 = 8.55711
# f(λ, T) = 5202.62096
# left_member_t2 = 4.107388e-25 m^5*div
# left_member_line_t2_average = 3.056086e-25 m^5*div
# sigma_left_member_line_t2_average = 6.1129e-26 m^5*div
# sigma_left_member_line_t2_average_percentage = 20.0 %
# left_member_line_t2_error_relative_to_average_value = [0.48, 34.88, 34.4] %
# 
# Computations for 5.53e-07 m:
# Computations for 8 V:
# hc_over_lambda_k_B_T_t2 = 9.14478
# f(λ, T) = 9364.42504
# left_member_t2 = 3.522119e-25 m^5*div
# Computations for 10 V:
# hc_over_lambda_k_B_T_t2 = 8.64859
# f(λ, T) = 5701.1011
# left_member_t2 = 5.360703e-25 m^5*div
# Computations for 12 V:
# hc_over_lambda_k_B_T_t2 = 8.26311
# f(λ, T) = 3877.13637
# left_member_t2 = 5.012758e-25 m^5*div
# left_member_line_t2_average = 4.63186e-25 m^5*div
# sigma_left_member_line_t2_average = 5.63888e-26 m^5*div
# sigma_left_member_line_t2_average_percentage = 12.17 %
# left_member_line_t2_error_relative_to_average_value = [23.96, 15.74, 8.22] %
# 
# Computations for 5.91e-07 m:
# Computations for 8 V:
# hc_over_lambda_k_B_T_t2 = 8.55679
# f(λ, T) = 5200.95606
# left_member_t2 = 2.982881e-25 m^5*div
# Computations for 10 V:
# hc_over_lambda_k_B_T_t2 = 8.0925
# f(λ, T) = 3268.85199
# left_member_t2 = 5.356486e-25 m^5*div
# Computations for 12 V:
# hc_over_lambda_k_B_T_t2 = 7.73181
# f(λ, T) = 2278.72477
# left_member_t2 = 6.721235e-25 m^5*div
# left_member_line_t2_average = 5.020201e-25 m^5*div
# sigma_left_member_line_t2_average = 1.09219e-25 m^5*div
# sigma_left_member_line_t2_average_percentage = 21.76 %
# left_member_line_t2_error_relative_to_average_value = [40.58, 6.7, 33.88] %
# 
# Computations for 6.2e-07 m:
# Computations for 8 V:
# hc_over_lambda_k_B_T_t2 = 8.15655
# f(λ, T) = 3485.13865
# left_member_t2 = 4.455139e-25 m^5*div
# Computations for 10 V:
# hc_over_lambda_k_B_T_t2 = 7.71398
# f(λ, T) = 2238.43751
# left_member_t2 = 7.630534e-25 m^5*div
# Computations for 12 V:
# hc_over_lambda_k_B_T_t2 = 7.37016
# f(λ, T) = 1586.88782
# left_member_t2 = 6.761861e-25 m^5*div
# left_member_line_t2_average = 6.282511e-25 m^5*div
# sigma_left_member_line_t2_average = 9.47473e-26 m^5*div
# sigma_left_member_line_t2_average_percentage = 15.08 %
# left_member_line_t2_error_relative_to_average_value = [29.09, 21.46, 7.63] %
# 
# Computations for 6.74e-07 m:
# Computations for 8 V:
# hc_over_lambda_k_B_T_t2 = 7.50306
# f(λ, T) = 1812.5835
# left_member_t2 = 1.0553622e-24 m^5*div
# Computations for 10 V:
# hc_over_lambda_k_B_T_t2 = 7.09595
# f(λ, T) = 1206.06853
# left_member_t2 = 1.7555594e-24 m^5*div
# Computations for 12 V:
# hc_over_lambda_k_B_T_t2 = 6.77967
# f(λ, T) = 878.77835
# left_member_t2 = 2.3309031e-24 m^5*div
# left_member_line_t2_average = 1.7139416e-24 m^5*div
# sigma_left_member_line_t2_average = 3.688045e-25 m^5*div
# sigma_left_member_line_t2_average_percentage = 21.52 %
# left_member_line_t2_error_relative_to_average_value = [38.42, 2.43, 36.0] %
# 
# Computations for 7.71e-07 m:
# Computations for 8 V:
# hc_over_lambda_k_B_T_t2 = 6.5591
# f(λ, T) = 704.63634
# left_member_t2 = 1.8283007e-24 m^5*div
# Computations for 10 V:
# hc_over_lambda_k_B_T_t2 = 6.2032
# f(λ, T) = 493.32836
# left_member_t2 = 2.5600513e-24 m^5*div
# Computations for 12 V:
# hc_over_lambda_k_B_T_t2 = 5.92672
# f(λ, T) = 373.92275
# left_member_t2 = 3.6382769e-24 m^5*div
# left_member_line_t2_average = 2.675543e-24 m^5*div
# sigma_left_member_line_t2_average = 5.256765e-25 m^5*div
# sigma_left_member_line_t2_average_percentage = 19.65 %
# left_member_line_t2_error_relative_to_average_value = [31.67, 4.32, 35.98] %
# 
# Computations for 7.91e-07 m:
# Computations for 8 V:
# hc_over_lambda_k_B_T_t2 = 6.39325
# f(λ, T) = 596.79626
# left_member_t2 = 2.704431e-24 m^5*div
# Computations for 10 V:
# hc_over_lambda_k_B_T_t2 = 6.04636
# f(λ, T) = 421.57206
# left_member_t2 = 3.8207764e-24 m^5*div
# Computations for 12 V:
# hc_over_lambda_k_B_T_t2 = 5.77686
# f(λ, T) = 321.74418
# left_member_t2 = 5.1030351e-24 m^5*div
# left_member_line_t2_average = 3.8760808e-24 m^5*div
# sigma_left_member_line_t2_average = 6.929693e-25 m^5*div
# sigma_left_member_line_t2_average_percentage = 17.88 %
# left_member_line_t2_error_relative_to_average_value = [30.23, 1.43, 31.65] %
# 
# lambda_n_in_nm = [1018.8665987422266, 963.5832004253057, 920.6349206349206]