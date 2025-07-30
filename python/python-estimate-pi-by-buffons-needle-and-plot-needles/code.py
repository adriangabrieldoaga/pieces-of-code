# -*- coding: utf-8 -*-

# Copyright notice:
# © 2025 Adrian-Gabriel Doaga. All Rights Reserved.
# Email: adriangabrieldoaga@gmail.com
# Website: https://github.com/adriangabrieldoaga/pieces-of-code
# Bibliography:
# https://en.wikipedia.org/wiki/Buffon%27s_needle_problem

# Needles are red if they lie across a line, black otherwise
# You can choose the seed of the generator manually at the end of the script

import numpy as np
import matplotlib.pyplot as plt

def buffon_needle(n_needles, needle_length, line_spacing, x_max, y_max, seed=None):
    if seed is not None:
        np.random.seed(seed)

    # Generate random needle centers and angles
    x_centers = np.random.uniform(0, x_max, n_needles)
    y_centers = np.random.uniform(0, y_max, n_needles)
    angles = np.random.uniform(0, np.pi, n_needles)

    # Needle endpoints
    dx = (needle_length / 2) * np.cos(angles)
    dy = (needle_length / 2) * np.sin(angles)
    x0 = x_centers - dx
    x1 = x_centers + dx
    y0 = y_centers - dy
    y1 = y_centers + dy

    # Check if needle crosses a line
    intersects = np.floor(x0 / line_spacing) != np.floor(x1 / line_spacing)

    # Estimate π
    n_hits = np.sum(intersects)
    if n_hits != 0:
        pi_estimate = (2 * needle_length * n_needles) / (line_spacing * n_hits)
    else:
        pi_estimate = np.inf

    # Zoom out one needle length to see the entire needle
    margin = needle_length
    x_min_plot = -margin
    x_max_plot = x_max + margin
    y_min_plot = -margin
    y_max_plot = y_max + margin

    fig, ax = plt.subplots(figsize=(10, 10))

    # Draw vertical lines from x = o to x = 20
    for x in np.arange(0, x_max + line_spacing, line_spacing):
        ax.axvline(x, color='blue')

    # Draw needles
    for i in range(n_needles):
        color = 'red' if intersects[i] else 'black'
        ax.plot([x0[i], x1[i]], [y0[i], y1[i]], color=color)

    ax.set_title(f"Buffon's Needle: π ≈ {pi_estimate} (Hits: {n_hits}/{n_needles})")
    ax.set_xlim(x_min_plot, x_max_plot)
    ax.set_ylim(y_min_plot, y_max_plot)
    ax.set_aspect('equal')
    plt.xlabel('x')
    plt.ylabel('y')
    plt.grid(False)
    plt.show()

buffon_needle(n_needles=1000, needle_length=1.0, line_spacing=2.0, x_max=20, y_max=20)
# buffon_needle(n_needles=1000, needle_length=1.0, line_spacing=2.0, x_max=20, y_max=20, seed=31)