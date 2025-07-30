# -*- coding: utf-8 -*-

# Copyright notice:
# © 2025 Adrian-Gabriel Doaga. All Rights Reserved.
# Email: adriangabrieldoaga@gmail.com
# Website: https://github.com/adriangabrieldoaga/pieces-of-code
# Bibliography:
# http://www.physics.pub.ro/Referate/BN031A/Experimentul_FRANCK-HERTZ_cu_tub_de_NEON_(2017).pdf

import numpy as np
import matplotlib.pyplot as plt
from sklearn.linear_model import LinearRegression

# Experimental data (the values are fabricated for demonstration purposes, but reflect the typical trends observed in real experiments)
U_minimum_experimental_in_V = np.array([
    [17.89, 33.97, 52.21, 70.97, 92.07],
    [19.40, 34.88, 51.18, 72.49, 92.03],
    [18.65, 36.23, 52.21, 71.14, 91.30],
    [19.12, 36.20, 52.95, 71.34, 89.57],
    [19.01, 35.96, 52.13, 72.07, 92.02],
    [19.23, 35.25, 52.55, 71.31, 91.28],
    [18.53, 36.12, 52.32, 72.05, 93.07]
])

# Constants
h_in_Js = 6.6e-34 # J*s; Planck's constant
c_in_SI = 3e8 # m/s; Speed of light in vacuum

# Experimental data processing

# Compute the average of each column
U_minimum_experimental_in_V_average = np.round(np.mean(U_minimum_experimental_in_V, axis=0), 2)
print("U_minimum_experimental_in_V_average =", np.array2string(U_minimum_experimental_in_V_average, precision=2, separator=' ', formatter={'float_kind':lambda x: f"{x:.2f}"}))

# Compute the numerator of the fraction: sum of (x_element - x_average)^2 for each column
N = U_minimum_experimental_in_V.shape[0]
sums = np.sum((U_minimum_experimental_in_V - U_minimum_experimental_in_V_average) ** 2, axis=0)

# Compute the sqrt of the fraction for each column
sigma_U_minimum_experimental_in_V_average = np.round(np.sqrt(sums / (N * (N - 1))), 2)
print("sigma_U_minimum_experimental_in_V_average =", np.array2string(sigma_U_minimum_experimental_in_V_average, precision=2, separator=' ', formatter={'float_kind':lambda x: f"{x:.2f}"}))

delta_U_minimum_experimental_in_V_average = []
for U_minimum_experimental_in_V_average_index in range(1, len(U_minimum_experimental_in_V_average)):
    delta_U_minimum_experimental_in_V_average.append(round(U_minimum_experimental_in_V_average[U_minimum_experimental_in_V_average_index] - U_minimum_experimental_in_V_average[U_minimum_experimental_in_V_average_index - 1], 3))

print("delta_U_minimum_experimental_in_V_average =", delta_U_minimum_experimental_in_V_average)

# Plot U_minimum_experimental_in_V_average as a function of n
n = np.arange(1, len(U_minimum_experimental_in_V_average) + 1)

# Reshape n for linear regression
n = np.array(n).reshape(-1, 1)

# Perform linear regression
model_1 = LinearRegression()
model_1.fit(n, U_minimum_experimental_in_V_average)
plt.figure(figsize=(7,7))
plt.scatter(n, U_minimum_experimental_in_V_average, color='blue')
plt.plot(n, model_1.predict(n), color='blue', label=f'slope = {round(model_1.coef_[0], 2)} V, intercept = {round(model_1.intercept_, 2)} V')  # Include slope and intercept in label

# Labels and title
plt.xlabel('n')
plt.ylabel('U (V)')
plt.title('U = U(n)')
plt.grid(True)
plt.legend()
plt.show()

# Get the slope and intercept of linear regression
slope_p1 = round(model_1.coef_[0], 2)
intercept_p1 = round(model_1.intercept_, 2)

print("slope_p1 is the potential corresponding to the first excited state of the neon atom.")
excitation_energy_for_Ne_in_eV = slope_p1
excitation_energy_for_Ne_in_J = round(excitation_energy_for_Ne_in_eV * 1.6 * (10**-19), 21)
print("excitation_energy_for_Ne_in_eV =", excitation_energy_for_Ne_in_eV, "eV")
print("excitation_energy_for_Ne_in_J =", excitation_energy_for_Ne_in_J, "J")

# Plot delta_U_minimum_experimental_in_V_average as a function of n
n = np.arange(2, len(delta_U_minimum_experimental_in_V_average) + 2)

# Reshape n for linear regression
n = np.array(n).reshape(-1, 1)

# Perform linear regression
model_2 = LinearRegression()
model_2.fit(n, delta_U_minimum_experimental_in_V_average)
plt.figure(figsize=(7,7))
plt.scatter(n, delta_U_minimum_experimental_in_V_average, color='blue')
plt.plot(n, model_2.predict(n), color='blue')

# Labels and title
plt.xlabel('n')
plt.ylabel('ΔU (V)')
plt.title('ΔU = ΔU(n)')
plt.grid(True)
plt.show()

# Plot U_minimum_experimental_in_V_average as a function of n for the first 3 minimuns
n = np.arange(1, len(U_minimum_experimental_in_V_average) + 1)

n_first_three = n[:3]
U_minimum_experimental_in_V_average_first_three = U_minimum_experimental_in_V_average[:3]

# Reshape n for linear regression
n_first_three = np.array(n_first_three).reshape(-1, 1)

# Perform linear regression
model_3 = LinearRegression()
model_3.fit(n_first_three, U_minimum_experimental_in_V_average_first_three)
plt.figure(figsize=(7,7))
plt.scatter(n_first_three, U_minimum_experimental_in_V_average_first_three, color='blue')
plt.plot(n_first_three, model_3.predict(n_first_three), color='blue', label=f'slope = {round(model_3.coef_[0], 2)} V, intercept = {round(model_3.intercept_, 2)} V')

# Labels and title
plt.xlabel('n')
plt.ylabel('U (V)')
plt.title('U = U(n) for the first 3 minimums')
plt.grid(True)
plt.legend()
plt.show()

# Get the slope and intercept of linear regression
slope_p3 = round(model_3.coef_[0], 2)
intercept_p3 = round(model_3.intercept_, 2)

excitation_energy_for_3s_Ne_in_eV = slope_p3
excitation_energy_for_3s_Ne_in_J = round(excitation_energy_for_3s_Ne_in_eV * 1.6 * (10**-19), 21)
print("excitation_energy_for_3s_Ne_in_eV =", excitation_energy_for_3s_Ne_in_eV, "eV")
print("excitation_energy_for_3s_Ne_in_J =", excitation_energy_for_3s_Ne_in_J, "J")

# Plot U_min_exp_average as a function of n for the last 3 minimuns
n_last_three = n[-3:]
U_minimum_experimental_in_V_average_last_three = U_minimum_experimental_in_V_average[-3:]

# Reshape n for linear regression
n_last_three = np.array(n_last_three).reshape(-1, 1)

# Perform linear regression
model_4 = LinearRegression()
model_4.fit(n_last_three, U_minimum_experimental_in_V_average_last_three)
plt.figure(figsize=(7,7))
plt.scatter(n_last_three, U_minimum_experimental_in_V_average_last_three, color='blue')
plt.plot(n_last_three, model_4.predict(n_last_three), color='blue', label=f'slope = {round(model_4.coef_[0], 2)} V, intercept = {round(model_4.intercept_, 2)} V')

# Labels and title
plt.xlabel('n')
plt.ylabel('U (V)')
plt.title('U = U(n) for the last 3 minimums')
plt.grid(True)
plt.legend()
plt.show()

# Get the slope and intercept of linear regression
slope_p4 = round(model_4.coef_[0], 2)
intercept_p4 = round(model_4.intercept_, 2)

excitation_energy_for_3p_Ne_in_eV = slope_p4
excitation_energy_for_3p_Ne_in_J = round(excitation_energy_for_3p_Ne_in_eV * 1.6 * (10**-19), 21)
print("excitation_energy_for_3p_Ne_in_eV =", excitation_energy_for_3p_Ne_in_eV, "eV")
print("excitation_energy_for_3p_Ne_in_J =", excitation_energy_for_3p_Ne_in_J, "J")

lambda_Ne_in_m = round(h_in_Js*c_in_SI/(excitation_energy_for_3p_Ne_in_J - excitation_energy_for_3s_Ne_in_J), 12)
lambda_Ne_in_nm = lambda_Ne_in_m * (10**9)
print("lambda_Ne_in_nm =", lambda_Ne_in_nm, "nm (red to infrared)")

# Energy of level 2s
excitation_energy_for_2s_Ne_in_eV = intercept_p1  # The intercept is considered fundamental energy level
excitation_energy_for_2s_Ne_in_J = round(excitation_energy_for_2s_Ne_in_eV * 1.6 * (10**-19), 21)
print("excitation_energy_for_2s_Ne_in_eV =", excitation_energy_for_2s_Ne_in_eV, "eV (equal to intercept_p1)")
print("excitation_energy_for_2s_Ne_in_J =", excitation_energy_for_2s_Ne_in_J, "J")

# Energy difference between the 3s and 2s levels
E_3s_to_2s_in_eV = excitation_energy_for_3s_Ne_in_eV - excitation_energy_for_2s_Ne_in_eV
E_3s_to_2s_in_J = round(E_3s_to_2s_in_eV * 1.6 * (10**-19), 21)
print("E_3s_to_2s_in_eV =", E_3s_to_2s_in_eV, "eV")
print("E_3s_to_2s_in_J =", E_3s_to_2s_in_J, "J")

# Wavelength for the transition from 3s to 2s
lambda_3s_to_2s = round(h_in_Js*c_in_SI/E_3s_to_2s_in_J, 11)
lambda_3s_to_2s_in_nm = lambda_3s_to_2s * (10**9)
print("lambda_3s_to_2s_in_nm =", lambda_3s_to_2s_in_nm, "nm (ultraviolet to x-rays)")

# Energy lost for excitation 2s -> 3s
E_loss_2s_to_3s_in_eV = excitation_energy_for_3s_Ne_in_eV - excitation_energy_for_2s_Ne_in_eV
E_loss_2s_to_3s_in_J = round(E_loss_2s_to_3s_in_eV * 1.6 * (10**-19), 21)
print("E_loss_2s_to_3s_in_eV =", E_loss_2s_to_3s_in_eV, "eV")
print("E_loss_2s_to_3s_in_J =", E_loss_2s_to_3s_in_J, "J")

# Energy lost for excitation 2s -> 3p
E_loss_2s_to_3p_in_eV = excitation_energy_for_3p_Ne_in_eV - excitation_energy_for_2s_Ne_in_eV
E_loss_2s_to_3p_in_J = round(E_loss_2s_to_3p_in_eV * 1.6 * (10**-19), 21)
print("E_loss_2s_to_3p_in_eV =", E_loss_2s_to_3p_in_eV, "eV")
print("E_loss_2s_to_3p_in_J =", E_loss_2s_to_3p_in_J, "J")

# Energy lost for excitation 3p -> 3s
E_3p_to_3s_in_eV = excitation_energy_for_3p_Ne_in_eV - excitation_energy_for_3s_Ne_in_eV
E_3p_to_3s_in_J = round(E_3p_to_3s_in_eV * 1.6 * (10**-19), 21)
print("E_3p_to_3s_in_eV =", E_3p_to_3s_in_eV, "eV")
print("E_3p_to_3s_in_J =", E_3p_to_3s_in_J, "J")

# Output:
# U_minimum_experimental_in_V_average = [18.83 35.52 52.22 71.62 91.62]
# sigma_U_minimum_experimental_in_V_average = [0.20 0.32 0.20 0.22 0.41]
# delta_U_minimum_experimental_in_V_average = [16.69, 16.7, 19.4, 20.0]
# 
# [image-output-1.png]
# slope_p1 is the potential corresponding to the first excited state of the neon atom.
# excitation_energy_for_Ne_in_eV = 18.17 eV
# excitation_energy_for_Ne_in_J = 2.907e-18 J
# 
# [image-output-2.png]
# 
# [image-output-3.png]
# excitation_energy_for_3s_Ne_in_eV = 16.69 eV
# excitation_energy_for_3s_Ne_in_J = 2.67e-18 J
# 
# [image-output-4.png]
# excitation_energy_for_3p_Ne_in_eV = 19.7 eV
# excitation_energy_for_3p_Ne_in_J = 3.152e-18 J
# lambda_Ne_in_nm = 410.788 nm (red to infrared)
# excitation_energy_for_2s_Ne_in_eV = -0.54 eV (equal to intercept_p1)
# excitation_energy_for_2s_Ne_in_J = -8.6e-20 J
# E_3s_to_2s_in_eV = 17.23 eV
# E_3s_to_2s_in_J = 2.757e-18 J
# lambda_3s_to_2s_in_nm = 71.82000000000001 nm (ultraviolet to x-rays)
# E_loss_2s_to_3s_in_eV = 17.23 eV
# E_loss_2s_to_3s_in_J = 2.757e-18 J
# E_loss_2s_to_3p_in_eV = 20.24 eV
# E_loss_2s_to_3p_in_J = 3.238e-18 J
# E_3p_to_3s_in_eV = 3.009999999999998 eV
# E_3p_to_3s_in_J = 4.82e-19 J