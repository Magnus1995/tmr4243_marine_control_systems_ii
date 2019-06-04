%% Plotting

clc
clear all
close all

results_folder = 'results';

if ~exist(results_folder, 'dir')
    dir_status = mkdir(results_folder);
end

file_names = {  'eta.mat', 'eta_hat.mat', 'nu_hat.mat', 'tau_cmd.mat' ...
                'b_hat.mat', 'nu.mat', 'u.mat', 'tau_applied.mat' };

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

% Quiver plot
n_arrows = 100;
step = floor(length(eta)/n_arrows);

% POSITION PLOTS
figure;
subplot(2,5,1);
plot(eta(2,:), eta(3,:));
hold on
quiver(eta(2,1:step:end), eta(3,1:step:end), cos(eta(4,1:step:end)), sin(eta(4,1:step:end)));
xlabel('x-position [m]');
ylabel('y-position [m]');

subplot(2,5,2);
plot(eta(1,:),eta(2,:),eta_hat(1,:),eta_hat(2,:));
legend('Surge','Surge_{est}');
xlabel('Time [s]');
ylabel('x-position [m]');

subplot(2,5,3);
plot(eta(1,:),eta(3,:),eta_hat(1,:),eta_hat(3,:));
legend('Sway','Sway_{est}');
xlabel('Time [s]');
ylabel('y-position [m]');

subplot(2,5,4);
plot(eta(1,:), (180/pi)*eta(4,:),eta_hat(1,:), (180/pi)*eta_hat(4,:));
legend('Yaw','Yaw_{est}');
xlabel('Time [s]');
ylabel('Heading [degs]');

% Forces
subplot(2,5,5);
plot(tau_cmd(1,:), tau_cmd(2,:), tau_applied(1,:), tau_applied(2,:));
legend('Surge force command','Surge force applied');
xlabel('Time [s]');
ylabel('Force [N]');

% VELOCITY PLOTS
subplot(2,5,6);
plot(nu(1,:), nu(2,:), nu_hat(1,:), nu_hat(2,:));
legend('Surge velocity','Surge velocity, est.');
xlabel('Time [s]');
ylabel('Velocity [m/s]');

subplot(2,5,7);
plot(nu(1,:), nu(3,:), nu_hat(1,:), nu_hat(3,:));
legend('Sway velocity','Sway velocity, est.');
xlabel('Time [s]');
ylabel('Velocity [m/s]');

subplot(2,5,8);
plot(nu(1,:), (180/pi)*nu(4,:), nu_hat(1,:), (180/pi)*nu_hat(4,:));
legend('Yaw velocity','Yaw velocity, est.');
xlabel('Time [s]');
ylabel('Angular velocity [degree/s]');