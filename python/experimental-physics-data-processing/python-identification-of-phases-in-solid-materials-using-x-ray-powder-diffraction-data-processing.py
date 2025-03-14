# -*- coding: utf-8 -*-

# Copyright notice:
# © 2025 Adrian-Gabriel Doaga. All Rights Reserved.
# Email: adriangabrieldoaga@gmail.com
# Website: https://github.com/adriangabrieldoaga/pieces-of-code
# Bibliography:
# http://www.physics.pub.ro/Referate/BN031A/Legea_lui_BRAGG._Difractia_radiatiilor_X_pe_monocristale_(2007).pdf

import math

# Experimental data (the values are fabricated for demonstration purposes, but reflect the typical trends observed in real experiments)
I_experimental_t1_in_m = [7e-3, 30e-3, 86e-3, 20e-3, 6e-3, 5e-3, 40e-3, 9e-3, 75e-3, 55e-3]
I_experimental_t2_in_m = [19e-3, 84e-3, 17e-3, 29e-3, 54e-3, 35e-3]
I_experimental_t3_in_m = [23e-3, 108e-3, 30e-3, 7e-3, 41e-3, 107e-3, 57e-3]
I_experimental_t4_in_m = [27e-3, 114e-3, 21e-3, 4e-3, 41e-3, 86e-3, 6e-3, 7e-3, 48e-3]

# Data that is set
theta_t1_in_degrees = [12.50, 14.10, 15.10, 15.80, 17.10, 17.20, 17.50, 24.80, 25.15, 29.90]
theta_t2_in_degrees = [14.20, 15.10, 15.75, 17.50, 25.20, 29.90]
theta_t3_in_degrees = [14.10, 15.10, 15.70, 17.10, 17.50, 25.10, 29.90]
theta_t4_in_degrees = [14.10, 15.05, 15.75, 16.71, 17.50, 25.15, 27.90, 29.10, 29.90]

# Constants
n = 1
lambda_X_in_m = 1.54e-10

# Functions
def compute_d(theta, d):
    for theta_elem in theta:
        d.append(round(n*lambda_X_in_m / (2*math.sin(math.radians(theta_elem))), 12))
    return d

def compute_I_on_I_0_ratio(I, I_on_I_0_ratio):
    I_0 = max(I)
    for I_elem in I:
        I_on_I_0_ratio.append(round(I_elem / I_0, 3))
        
# Experimental data processing
d_t1_in_m = []
compute_d(theta_t1_in_degrees, d_t1_in_m)

d_t2_in_m = []
compute_d(theta_t2_in_degrees, d_t2_in_m)

d_t3_in_m = []
compute_d(theta_t3_in_degrees, d_t3_in_m)

d_t4_in_m = []
compute_d(theta_t4_in_degrees, d_t4_in_m)

d_t1_in_angstrom = [round(d_t1_in_m_element * 1e10, 2) for d_t1_in_m_element in d_t1_in_m]
d_t2_in_angstrom = [round(d_t2_in_m_element * 1e10, 2) for d_t2_in_m_element in d_t2_in_m]
d_t3_in_angstrom = [round(d_t3_in_m_element * 1e10, 2) for d_t3_in_m_element in d_t3_in_m]
d_t4_in_angstrom = [round(d_t4_in_m_element * 1e10, 2) for d_t4_in_m_element in d_t4_in_m]

print("d_t1_in_angstrom =", d_t1_in_angstrom, "Å")
print("\nd_t2_in_angstrom =", d_t2_in_angstrom, "Å")
print("\nd_t3_in_angstrom =", d_t3_in_angstrom, "Å")
print("\nd_t4_in_angstrom =", d_t4_in_angstrom, "Å")

I_on_I_0_ratio_t1 = []
compute_I_on_I_0_ratio(I_experimental_t1_in_m, I_on_I_0_ratio_t1)

I_on_I_0_ratio_t2 = []
compute_I_on_I_0_ratio(I_experimental_t2_in_m, I_on_I_0_ratio_t2)

I_on_I_0_ratio_t3 = []
compute_I_on_I_0_ratio(I_experimental_t3_in_m, I_on_I_0_ratio_t3)

I_on_I_0_ratio_t4 = []
compute_I_on_I_0_ratio(I_experimental_t4_in_m, I_on_I_0_ratio_t4)

I_on_I_0_ratio_t1_percent = [round(I_on_I_0_ratio_t1_element * 100, 1) for I_on_I_0_ratio_t1_element in I_on_I_0_ratio_t1]
I_on_I_0_ratio_t2_percent = [round(I_on_I_0_ratio_t2_element * 100, 1) for I_on_I_0_ratio_t2_element in I_on_I_0_ratio_t2]
I_on_I_0_ratio_t3_percent = [round(I_on_I_0_ratio_t3_element * 100, 1) for I_on_I_0_ratio_t3_element in I_on_I_0_ratio_t3]
I_on_I_0_ratio_t4_percent = [round(I_on_I_0_ratio_t4_element * 100, 1) for I_on_I_0_ratio_t4_element in I_on_I_0_ratio_t4]

print("\nI_on_I_0_ratio_t1_percent =", I_on_I_0_ratio_t1_percent, "%")
print("\nI_on_I_0_ratio_t2_percent =", I_on_I_0_ratio_t2_percent, "%")
print("\nI_on_I_0_ratio_t3_percent =", I_on_I_0_ratio_t3_percent, "%")
print("\nI_on_I_0_ratio_t4_percent =", I_on_I_0_ratio_t4_percent, "%")