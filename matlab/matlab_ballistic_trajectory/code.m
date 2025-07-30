%{
Copyright notice:
© 2025 Adrian-Gabriel Doaga. All Rights Reserved.
Email: adriangabrieldoaga@gmail.com
Website: https://github.com/adriangabrieldoaga/pieces-of-code
%}

% The program plots the trajectory of a projectile launched in a homogeneous
% gravitational field with fluid friction.

clc % Clears Command Window (optional)
clear % Deletes memory of previous activity (optional)
close all % Closes all figures (optional)

% Physical quantities:
m = 1; % mass of projectile (kg)
v_0 = 320; % initial speed of the projectile (m / s)
alpha_0 = 31; % launch angle (between v0 and the horizontal axis) (°)
g = 9.81; % gravitational acceleration (m / s^2)
b = 0.75 * m * g / v_0; % fluid friction coefficient (N * s / m)

% Discretization of the time of movement
t_i = 0; % time of launch
% Overestimation of movement time, based on case b = 0:
t_f = 2 * v_0 * sind(alpha_0) / g; % time of contact with the ground
N = 2500; % discretization moments (number of steps)
t = linspace(t_i, t_f, N); % t is the array of moments of time from t_i to t_f, with constamt step

% motion rules in function of time (x and y are arrays)
x = v_0 * cosd(alpha_0) * m / b * (1 - exp(-b / m * t)); % distance (m)
y = v_0 * sind(alpha_0) * m / b * (1 - exp(-b / m * t)) - g * m / b * t + g * (m / b)^2 * (1 - exp(-b / m * t)); % altitude (m)

% We eliminate the elements where y < 0 from x, y and t
indices = (y >= 0); % The elements of indices arrat are 1 for y >= 0 and 0 otherwise
x = x(indices == 1);
y = y(indices == 1);
t = t(indices == 1);

% Plot
plot(x, y, 'b') % y in function of x; continuous blue line
daspect([1 1 1]) % units of measure on the x, y and t axes are in ratio 1:1:1
xlabel('x (m)');
ylabel('y (m)');
grid
title('Ballistic trajectory')
ylim([0, 1.1 * max(y)]) % see a bit above the graph

display_var = ['The projectile traveled a distance of ', num2str(x(length(t))), ' meters.'];
disp(display_var)

display_var = ['The projectile reached a maximum height of ', num2str(max(y)), ' meters.'];
disp(display_var)

display_var = ['The projectile was in motion for ', num2str(t(length(t))), ' seconds.', newline]; % t(length(t)) - last element in array t
disp(display_var)

%{
Output:
The projectile traveled a distance of 5964.6862 meters.
The projectile reached a maximum height of 1107.0322 meters.
The projectile was in motion for 30.1453 seconds.
%}