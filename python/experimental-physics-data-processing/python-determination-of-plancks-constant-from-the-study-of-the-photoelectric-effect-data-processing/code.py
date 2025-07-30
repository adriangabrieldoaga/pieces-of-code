# -*- coding: utf-8 -*-

# Copyright notice:
# © 2025 Adrian-Gabriel Doaga. All Rights Reserved.
# Email: adriangabrieldoaga@gmail.com
# Website: https://github.com/adriangabrieldoaga/pieces-of-code
# Bibliography:
# http://www.physics.pub.ro/Referate/BN031A/Determinarea_constantei_lui_PLANCK_din_studiul_Efectul_Fotoelectric_(2016).pdf

import numpy as np
import matplotlib.pyplot as plt
from sklearn.linear_model import LinearRegression

# Experimental data (the values are fabricated for demonstration purposes, but reflect the typical trends observed in real experiments)
U_0_experimental_in_V = np.array([
    [0.97, 0.93, 0.97, 1.04, 1.03, 1.00, 1.12, 1.23, 1.31, 1.07],
    [1.17, 1.30, 1.54, 1.53, 1.50, 1.31, 1.49, 1.35, 1.47, 1.40],
    [1.81, 1.55, 1.91, 1.85, 1.87, 1.78, 1.90, 1.91, 1.90, 1.80],
    [2.01, 2.03, 1.97, 2.05, 2.20, 2.37, 2.31, 2.25, 2.22, 2.47],
    [2.23, 2.03, 2.28, 2.47, 2.31, 2.41, 2.29, 2.51, 2.54, 2.49]
])

# Data that is set
lambda_filter_in_m = [578e-9, 546e-9, 436e-9, 405e-9, 366e-9]

# Constants
c_in_SI = 3e8 # m/s; Speed of light in vacuum
e_in_C = 1.6e-19 # elementary electron charge

# Experimental data processing

# Compute the average of each line (each filter)
U_0_experimental_in_V_average = np.round(np.mean(U_0_experimental_in_V, axis=1), 3)
print("U_0_experimental_in_V_average =", np.array2string(U_0_experimental_in_V_average, precision=3, separator=' ', formatter={'float_kind':lambda x: f"{x:.3f}"}))

# Compute sigma_U_0_experimental_in_V
K = U_0_experimental_in_V.shape[1]
squared_differences = (U_0_experimental_in_V - U_0_experimental_in_V_average[:, np.newaxis])**2  # Squared differences
sigma_U_0_experimental_in_V = np.round(np.sqrt(np.sum(squared_differences, axis=1) / (K * (K - 1))), 3)

print("sigma_U_0_experimental_in_V =", np.array2string(sigma_U_0_experimental_in_V, precision=3, separator=' ', formatter={'float_kind':lambda x: f"{x:.3f}"}))

nu_in_Hz = []
for lambda_filter_in_m in lambda_filter_in_m:
    nu_in_Hz.append(round(c_in_SI/lambda_filter_in_m, -11))
    
nu_in_10e12_Hz =[nu_in_Hz_element*(10**-12) for nu_in_Hz_element in nu_in_Hz]

print("nu_in_10e12_Hz =", nu_in_10e12_Hz, "* 10^12 Hz")

# Reshape nu_in_10e12_Hz for linear regression
nu_in_10e12_Hz = np.array(nu_in_10e12_Hz).reshape(-1, 1)

# Perform linear regression
model_1 = LinearRegression()
model_1.fit(nu_in_10e12_Hz, U_0_experimental_in_V_average)
plt.figure(figsize=(7,7))
plt.scatter(nu_in_10e12_Hz, U_0_experimental_in_V_average, color='red')
plt.plot(nu_in_10e12_Hz, model_1.predict(nu_in_10e12_Hz), color='red', label=f'slope = {round(model_1.coef_[0], 5)} · 10^(-12) V·s, intercept = {round(model_1.intercept_, 5)} V')  # Include slope and intercept in label

# Labels and title
plt.xlabel('ν (10^12 Hz)')
plt.ylabel('U_0 (V)')
plt.title("f(ν) = U_0")
plt.grid(True)
plt.legend()
plt.show()

# Get the slope and intercept of linear regression
slope_p1_in_10e_minus12_Vs = round(model_1.coef_[0], 5)
intercept_p1_in_V = round(model_1.intercept_, 5)

h_in_SI = round(slope_p1_in_10e_minus12_Vs * (10**-12) * e_in_C, 37);

print("h_in_SI =", h_in_SI, "J*s")

# 0 = mx + n
# x = -n/m
# Compute threshold frequency and append new data points
nu_threshold_in_Hz = -intercept_p1_in_V/(slope_p1_in_10e_minus12_Vs*(10**-12))
print(f"nu_threshold_in_Hz = {nu_threshold_in_Hz:.3e}")

# Append threshold frequency to data
nu_threshold_in_10e12_Hz = nu_threshold_in_Hz * (10**-12)
nu_in_10e12_Hz = list(nu_in_10e12_Hz.flatten())  # Convert back to list for appending
nu_in_10e12_Hz.append(nu_threshold_in_10e12_Hz)

# Append corresponding U_0_experimental_in_V value
U_0_experimental_in_V_average = list(U_0_experimental_in_V_average)  # Convert back to list for appending
U_0_experimental_in_V_average.append(0)  # Corresponding U_0_experimental_in_V_average value for threshold frequency is 0

# Convert back to NumPy arrays
nu_in_10e12_Hz = np.array(nu_in_10e12_Hz).reshape(-1, 1)
U_0_experimental_in_V_average = np.array(U_0_experimental_in_V_average)

# Perform linear regression
model_2 = LinearRegression()
model_2.fit(nu_in_10e12_Hz, U_0_experimental_in_V_average)
plt.figure(figsize=(7, 7))
plt.scatter(nu_in_10e12_Hz, U_0_experimental_in_V_average, color='red')
plt.plot(nu_in_10e12_Hz, model_2.predict(nu_in_10e12_Hz), color='red')

# Labels and title
plt.xlabel('ν (10^12 Hz)')
plt.ylabel('U_0 (V)')
plt.title("f(ν) = U_0 extended to U_0 = 0")
plt.grid(True)
plt.show()

lambda_threshold_in_m = round(c_in_SI/nu_threshold_in_Hz, 10)
lambda_threshold_in_nm = lambda_threshold_in_m*(10**9)
print("\nlambda_threshold_in_nm =", lambda_threshold_in_nm)

W_extraction_in_J = round(h_in_SI*nu_threshold_in_Hz, 22)
print("W_extraction_in_J =", W_extraction_in_J)
W_extraction_in_eV = round(W_extraction_in_J/(1.6*(10**-19)), 3)
print("W_extraction_in_eV =", W_extraction_in_eV)

# Output:
# U_0_experimental_in_V_average = [1.067 1.406 1.828 2.188 2.356]
# sigma_U_0_experimental_in_V = [0.038 0.038 0.034 0.053 0.050]
# nu_in_10e12_Hz = [519.0, 549.5, 688.1, 740.6999999999999, 819.6999999999999] * 10^12 Hz
# 
# [image-output-1.png]
# h_in_SI = 6.624000000000001e-34 J*s
# nu_threshold_in_Hz = 2.358e+14
# 
# [image-output-2.png]
# 
# lambda_threshold_in_nm = 1272.3000000000002
# W_extraction_in_J = 1.562e-19
# W_extraction_in_eV = 0.976