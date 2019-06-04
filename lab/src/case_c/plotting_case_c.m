%% Moving data to results folder and loading data

clc
clear all
close all

results_folder = 'results';

if ~exist(results_folder, 'dir')
    dir_status = mkdir(results_folder);
end

file_names = {  
                'eta_real.mat', 'eta_measured.mat', 'eta_adjusted.mat', ...
                'j_pos.mat', 'switch_signal.mat', 'j_ctrl_law.mat', ...
                'pd.mat'
             };

for i = 1:length(file_names)
    file_name = char(file_names(i));
        
    if exist(file_name, 'file') == 2
        movefile(file_name, results_folder);
    end
end

for i = 1:length(file_names)
    file_name = char(file_names(i));
    
    path = strcat(results_folder, '/',file_name);
    load(path);
end

%% Plotting
real_color = 'g';
measured_color = 'b';
adjusted_color = 'k';
desired_color = 'm';
point_color = 'r';

%% Trajectory

figure();
hold on;

n_arrows = 10;
step = floor(length(eta_adjusted)/n_arrows);

% Adjusted trajectory
plot(eta_adjusted(2,:), eta_adjusted(3,:), 'color', adjusted_color);
plot(eta_adjusted(2,1), eta_adjusted(3,1), 'x', 'color', point_color, ...
        'LineWidth', 5);
quiver( eta_adjusted(2,1:step:end), eta_adjusted(3,1:step:end), ...
        cos(eta_adjusted(4,1:step:end)), sin(eta_adjusted(4,1:step:end)), ...
        'color', adjusted_color);
    
% Desired trajectory
plot(pd(2,:), pd(3,:), 'color', desired_color);
plot(pd(2,1), pd(3,1), 'x', 'color', point_color, ...
        'LineWidth', 5);
quiver( pd(2,1:step:end), pd(3,1:step:end), ...
        cos(pd(4,1:step:end)), sin(pd(4,1:step:end)), ...
        'color', desired_color);
axis equal;

%% Signal plots

figure();
hold on;

% Heading signals
subplot(4,3,1);
plot(eta_real(1,:), eta_real(4,:), 'color', real_color);
xlabel('Time [s]');
ylabel('Angle [rad]');
title('Real heading from Fossen model');

subplot(4,3,2);
plot(eta_adjusted(1,:), eta_adjusted(4,:), 'color', adjusted_color);
xlabel('Time [s]');
ylabel('Angle [rad]');
title('Adjusted heading');

subplot(4,3,3);
plot(eta_measured(1,:), eta_measured(4,:), 'color', measured_color);
xlabel('Time [s]');
ylabel('Angle [rad]');
title('Measured heading');

% Adjusted position signals
subplot(4,3,4);
plot(eta_adjusted(1,:), eta_adjusted(2,:), 'color', adjusted_color);
xlabel('Time [s]');
ylabel('Position [m]');
title('Adjusted x-position');

subplot(4,3,5);
plot(eta_adjusted(1,:), eta_adjusted(3,:), 'color', adjusted_color);
xlabel('Time [s]');
ylabel('Position [m]');
title('Adjusted y-position');

subplot(4,3,6);
plot(eta_adjusted(1,:), eta_adjusted(4,:), 'color', adjusted_color);
xlabel('Time [s]');
ylabel('Position [m]');
title('Adjusted heading');

% Desired path signals
subplot(4,3,7);
plot(pd(1,:), pd(2,:), 'color', desired_color);
xlabel('Time [s]');
ylabel('Position [m]');
title('Desired x-position');

subplot(4,3,8);
plot(pd(1,:), pd(3,:), 'color', desired_color);
xlabel('Time [s]');
ylabel('Position [m]');
title('Desired y-position');

subplot(4,3,9);
plot(pd(1,:), pd(4,:), 'color', desired_color);
xlabel('Time [s]');
ylabel('Angle [rad]');
title('Desired heading');

% Counter signals and control switch signal
subplot(4,3,10);
plot(j_pos(1,:), j_pos(2,:), 'color', measured_color);
xlabel('Time [s]');
ylabel('Number of rounds [-]');
title('Position round counter');

subplot(4,3,11);
plot(j_ctrl_law(1,:), j_ctrl_law(2,:), 'color', measured_color);
xlabel('Time [s]');
ylabel('Number of rounds [-]');
title('Control law round counter');

subplot(4,3,12);
plot(switch_signal(1,:), switch_signal(2,:), 'color', measured_color);
xlabel('Time [s]');
ylabel('Status [-]');
title('Switch signal');

hold off;