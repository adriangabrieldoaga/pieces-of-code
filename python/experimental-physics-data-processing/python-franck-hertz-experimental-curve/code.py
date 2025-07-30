# -*- coding: utf-8 -*-

# The Unlicense
# This is basic code, you can use it freely, without any restrictions or attribution.
# Creator: Adrian-Gabriel Doaga
# Email: adriangabrieldoaga@gmail.com
# Website: https://github.com/adriangabrieldoaga/pieces-of-code
# Year: 2025
# Bibliography:
# http://www.physics.pub.ro/Referate/BN031A/Experimentul_FRANCK-HERTZ_cu_tub_de_NEON_(2017).pdf

import matplotlib.pyplot as plt
import numpy as np
from scipy.interpolate import make_interp_spline

# Experimental data (the values are fabricated for demonstration purposes, but reflect the typical trends observed in real experiments)
U_experimental = np.array([14.03, 18.50, 31.48, 35.50, 45.51, 55.12, 61.30, 70.93, 87.31, 92.21, 97.03])
I_experimental = np.array([0.84, 0.07, 3.12, 0.10, 5.78, 1.65, 8.93, 5.07, 12.31, 11.37, 17.04])

# Interpolation for smooth curve
U_experimental_smooth = np.linspace(U_experimental.min(), U_experimental.max(), 1000)  # Generate finer points for U_experimental
spline = make_interp_spline(U_experimental, I_experimental, k=3)  # Cubic spline interpolation
I_experimental_smooth = spline(U_experimental_smooth)

# Plotting the Franck-Hertz curve
plt.figure(figsize=(12, 7))
plt.plot(U_experimental_smooth, I_experimental_smooth, color='b')
plt.scatter(U_experimental, I_experimental, color='r')
plt.title('Franck-Hertz experimental curve', fontsize=16)
plt.xlabel('U (V)', fontsize=14)
plt.ylabel('I (nA)', fontsize=14)
plt.grid(True, which='both', linestyle='--', linewidth=0.5)
plt.axhline(0, color='black', linewidth=0.8)
plt.axvline(0, color='black', linewidth=0.8)
plt.show()