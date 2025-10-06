%{
Copyright notice:
© 2025 Adrian-Gabriel Doaga. All Rights Reserved.
Email: adriangabrieldoaga@gmail.com
Website: https://github.com/adriangabrieldoaga/pieces-of-code
Bibliography:
Experimental data for AM_0.txt file: https://www.nrel.gov/grid/solar-resource/spectra-astm-e490
%}

clc; clear; close all;

% Constants
k = 1.380649e-23; % Boltzmann constant (J/K)
h = 6.62607015e-34; % Planck constant (J*s)
c = 299792458; % Speed of light in a vacuum (m/s)
sigma = 5.670374419e-8; % Stefan-Boltzmann constant (W / (m^2 * K^4))
AU = 149597871e3; % Astronomical unit (m)
R_sun = 696340e3; % Radius of the sun (m)

% Retrieval of experimental data
experimental_data = importdata('AM_0.txt');
wavelength_experimental_in_nm = experimental_data.data(:, 1);
irradiance_experimental = experimental_data.data(:, 2); % Solar spectral irradiance (W * m^-2 * nm^-1)

% Computing solar irradiance above the Earth's atmosphere
solar_irradiance_experimental = trapz(wavelength_experimental_in_nm, irradiance_experimental); % (W / m^2)
disp(['Solar irradiance above the Earth''s atmosphere: ', num2str(solar_irradiance_experimental), ' W / m^2']);

% After computing the solar irradiance above the Earth's atmosphere, we can
% compute the temperature of the sun
T_sun = nthroot((solar_irradiance_experimental / sigma) * (AU / R_sun)^2, 4);
disp(['Temperature of the sun: ', num2str(T_sun), ' K']);

% Plotting solar spectral irradiance
figure;
plot(wavelength_experimental_in_nm, irradiance_experimental, 'b', 'LineWidth', 1);
xlabel('Wavelength (nm)');
ylabel('Experimental irradiance (W * m^-2 * nm^-1)');
xlim([100 4000])
title('Solar spectral irradiance as a function of wavelength');
grid on;
hold on;

% Computing of theoretical irradiance for each wavelength
wavelength_experimental_in_m = wavelength_experimental_in_nm * 1e-9;
E_theoretical = (2 * pi * h * c^2) ./ (wavelength_experimental_in_m.^5); % Energy at each wavelength (J/m^3)
B_theoretical = (1 ./ (exp((h * c) ./ (wavelength_experimental_in_m * k * T_sun)) - 1)); % Planck distribution
irradiance_theoretical_in_SI = E_theoretical .* B_theoretical; % (W * m^-2 * m^-1)
irradiance_theoretical_with_nm = irradiance_theoretical_in_SI / 1e9; % (W * m^-2 * nm^-1)
irradiance_theoretical_at_Earth_with_nm = irradiance_theoretical_with_nm * (R_sun / AU)^2;

plot(wavelength_experimental_in_nm, irradiance_theoretical_at_Earth_with_nm, 'r', 'LineWidth', 1);
ylabel('Irradiance (W * m^-2 * nm^-1)');
legend('Experimental', 'Theoretical', 'Location', 'northeast');

%{
Solar irradiance above the Earth's atmosphere: 1366.0908 W / m^2
Temperature of the sun: 5774.5612 K
%}